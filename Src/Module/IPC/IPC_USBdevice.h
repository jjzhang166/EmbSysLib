//*******************************************************************
/*!
\file   Module/IPC_USBdevice.h
\author Thomas Breuer
\date   11.12.2014, 17.03.2016
*/

//*******************************************************************
#ifndef _IPC_USB_DEVICE_H
#define _IPC_USB_DEVICE_H

//*******************************************************************
#include "Module/IPC.h"
#include "Module/USB/USBinterfClassVSC.h"

//*******************************************************************
#pragma pack(1)
class cIPC_USBdevice_DATA
{
  public:
    static const WORD maxLength = 60;

    BYTE id;
    BYTE length;
    WORD crcValue;   
    BYTE data[ maxLength ];
};
#pragma pack()

//*******************************************************************
/*!
\class cIPC_USBdevice

\brief IPC transport class with USB hardware

\remark The length of the payload is limited to 60 bytes

\example cIPC.cpp
*/
class cIPC_USBdevice : public cIPC, 
                       public cUSBinterfClassVSC< cIPC_USBdevice_DATA, 
                                                  cIPC_USBdevice_DATA >
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate an IPC transport object with USB interface
    
        \param uart Reference to USB hardware
        \param interfId USB interface ID
        \param crcMode Select CRC calculation mode (FAST or SMALL)
    */
    cIPC_USBdevice( cHwUSB    &usb, 
                    BYTE       interfId, 
                    cCRC::MODE crcMode = cCRC::SMALL );

    //---------------------------------------------------------------
    /*! Update the IPC transport object
    
        NOT required with USB
    */
     virtual void update( void );

   private:
    //---------------------------------------------------------------
    virtual void writeStream( BYTE  id, 
                              BYTE *data, 
                              BYTE  size, 
                              WORD  crc );

    //---------------------------------------------------------------
    virtual int onTransmit( cIPC_USBdevice_DATA &data );

    //---------------------------------------------------------------
    virtual int onReceive( cIPC_USBdevice_DATA &data );

  private:
    //---------------------------------------------------------------
    cHwUSB &usb;
    
    cFifo<cIPC_USBdevice_DATA> fifo;

}; //cIPC_USBdevice

#endif
