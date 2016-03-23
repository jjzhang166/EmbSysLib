//*******************************************************************
/*!
\file   Module/IPC_UART.h
\author Thomas Breuer
\date   11.12.2014, 17.03.2016
*/

//*******************************************************************
#ifndef _IPC_UART_H
#define _IPC_UART_H

//*******************************************************************
#include "Module/IPC.h"

//*******************************************************************
/*!
\class cIPC_UART

\brief IPC transport class with UART hardware

\remark The length of the payload is limited to 64 bytes

\example cIPC.cpp
*/
class cIPC_UART : public cIPC
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate an IPC transport object with UART hardware
    
        \param uart Reference to UART hardware
        \param crcMode Select CRC calculation mode (FAST or SMALL)
    */
    cIPC_UART( cHwUART    &uart, 
               cCRC::MODE  crcMode = cCRC::SMALL );

    //---------------------------------------------------------------
    /*! Update the IPC transport object
    
        Checks, if new data are arrived. In that case IPC copies the 
        data to identified data object, sets the new data flag and 
        calls the related \b update() method. 
    */
    virtual void update( void );

  private:
    //---------------------------------------------------------------
    virtual void writeStream( BYTE  id, 
                              BYTE *data, 
                              BYTE  size, 
                              WORD  crc );

  private:
    //---------------------------------------------------------------
    cHwUART &uart;

    static const WORD maxLength = 64;
    
    BYTE     data[maxLength];
 
    bool     error;
    WORD     errorCnt;
    WORD     crcValue;
    BYTE     idx;
    BYTE     ready;
    BYTE     length;
    BYTE     id;
    BYTE     state;
    
}; //cIPC_UART

#endif
