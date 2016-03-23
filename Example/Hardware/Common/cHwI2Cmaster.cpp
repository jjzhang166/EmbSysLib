//*******************************************************************
/*!
\file   cHwI2Cmaster.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related class 'cHwI2Cmaster'
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
BYTE dataOut = 0;
BYTE dataIn  = 0;
BYTE addr    = 0;
BYTE ok      = true;
char str[50];

//*******************************************************************
int main( void )
{
  uart.set( "\r\n\ncHwI2Cmaster,"__DATE__ ","__TIME__"\r\n\n" );

  while( 1 )
  {
    sys.run();

    dataOut = rand();

    i2c.write( addr, dataOut );

    dataIn = i2c.read( addr );

    if( dataIn != dataOut )
    {
      ok = false;
    }

    sprintf( str, "addr: 0x%02x, write: 0x%02x,  read: 0x%02x, %s\r",
                  addr,
                  dataOut,
                  dataIn,
                  ok ? "OK" : "not OK" );
    uart.set( str );

    addr++;
  }
}
