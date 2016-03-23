//*******************************************************************
/*!
\file   Module/IPC_UART.cpp
\author Thomas Breuer
\date   11.12.2014, 17.03.2016
*/

//*******************************************************************
#include "lib.h"
#include "Module/IPC.h"

//*******************************************************************
//
// cIPC_UART
//
//*******************************************************************
/*
  In order to achieve a fast synchronisation of the data stream 
  without using a timeout, each byte of the payload is devided in 
  two parts. The payload is bit-or operated with an 
  identifier befor sending. To synchronize the data stream, just wait 
  until 0001 xxxx is received.
     
  Byte | 7654 3210
  ---- | ---- ----
  0    | 0001 high part of identifier
  1    | 0010 low  part of identifier
  2    | 0011 high part of data byte 0
  3    | 0100 low  part of data byte 0
  ...  | 0011 high part of data byte 1,...,N-1
  ...  | 0100 low  part of data byte 1,...,N-1
  2N+2 | 0101 high part of high byte crc
  2N+3 | 0110 low  part of high byte crc
  2N+4 | 0111 high part of low byte crc
  2N+5 | 1000 low  part of low byte crc
*/
//-------------------------------------------------------------------
cIPC_UART::cIPC_UART( cHwUART &uartIn, cCRC::MODE crcMode )
: cIPC( crcMode ),
  uart(uartIn)
{
  idx = 0;
  state = 0x80;
}

//-------------------------------------------------------------------
void cIPC_UART::writeStream( BYTE  id, 
                             BYTE *data, 
                             BYTE  size, 
                             WORD  crc )
{
  BYTE  buf[ 2*maxLength + 6 ];
  BYTE *bufPtr = buf;

  if( size > maxLength )
  {
    return;
  }

  *(bufPtr++) = 0x10 | (  id>>4  ); // id, high part
  *(bufPtr++) = 0x20 | (  id&0x0F); // id, low part 

  for( BYTE i=0; i<size; i++ )
  {
    *(bufPtr++) = 0x30 | (data[i]>>4  ); // data[0:N-1], high part
    *(bufPtr++) = 0x40 | (data[i]&0x0F); // data[0:N-1], low part
  }

  *(bufPtr++) = 0x50 | ( (crc>>12)&0x0F ); // crc, high byte, high part
  *(bufPtr++) = 0x60 | ( (crc>> 8)&0x0F ); // crc, high byte, low part

  *(bufPtr++) = 0x70 | ( (crc>> 4)&0x0F ); // crc, low byte, high part
  *(bufPtr++) = 0x80 | ( (crc    )&0x0F ); // crc, low byte, low part

  uart.set( buf, 2*size+6 );
}

//-------------------------------------------------------------------
// Parse and synchronize incomming data stream 
void cIPC_UART::update( void )
{
  BYTE c = 0;
  BYTE d = 0;

  while( uart.get(&c) )
  {
    d = c & 0x0F;
    c = c & 0xF0;
    switch( c )
    {
      case 0x10: // start, id high part
        if( state != 0x80 )
        {
          error = true; // package is restarted, skip previous data
        }
        id = d<<4;
        break;

      case 0x20: // id, size low part
        if( state != 0x10 )
        {
          error = true;
        }
        id |= d;
        break;

      case 0x30: // data, high part
        if( state != 0x20 && state != 0x40)
        {
          error = true;
        }
        data[idx] = d<<4;
        break;

      case 0x40: // data, low part
        if( state != 0x30 )
        {
          error = true;
        }
        data[idx] |= d;
        idx++;
        if( idx >= maxLength )
        {
          error = true;
        }
        break;

      case 0x50: // crc, high byte, high part
        if( state != 0x40 )
        {
          error = true;
        }
        crcValue = (WORD)d<<12;
        break;

     case 0x60: // crc, high byte, low part
        if( state != 0x50 )
        {
          error = true;
        }
        crcValue |= (WORD)d<<8;
        break;

      case 0x70: // crc, low byte, high part
        if( state != 0x60 )
        {
          error = true;
        }
        crcValue |= (WORD)d<<4;
        break;

     case 0x80: // crc, low byte, low part ; finish
        if( state != 0x70 )
        {
          error = true;
        }
        crcValue |= (WORD)d;
        ready = true;
        break;

      default:
        error = true;
        break;
    }

    state = c;

    if( error )
    {
      error = false;
      ready = false;
      idx   = 0;
      state = 0x80;
      errorCnt++;
    }

    if( ready )
    {
      ready = false;

      // look up correct data object: identifier and length OK?
      DataInterface *ptr = (DataInterface*)list.getFirst();

      while( ptr && ptr->id != id )
      {
        ptr = (DataInterface*)ptr->getNext();
      }

      if(    ptr 
          && idx == ptr->dataLength 
          && crcValue == crc( data, idx ) )
      {
        memcpy( ptr->dataRef, data, ptr->dataLength );
        ptr->update(); // we found a matching data object
      }
      state = 0x80;
      idx   = 0;
    }
  }
}

//EOF
