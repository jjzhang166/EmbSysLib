//*******************************************************************
/*!
\file   cIPC.cpp
\author Thomas Breuer
\date   18.03.2016
\brief  IPC sample code
*/

//*******************************************************************
#include "lib.h"
#include "Module/USB/USBinterfClassVSC.h"
#include "Module/IPC.h"
#include "config.h"
 
//*******************************************************************
#include "descriptor.cpp" // Include automatic generated 
                          // descriptor

//*******************************************************************
cHwUSBdesc_0   desc;
cHwUSB_0       usb( desc );

//*******************************************************************
class myData
{
  public:
    //---------------------------------------------------------------
    #pragma pack(1)
    class Data
    {
      public:
        Data() {cnt=0;rec=0;random=0;}
        DWORD cnt;
        DWORD rec;
        DWORD random;
    } data;
    #pragma pack()

    //---------------------------------------------------------------
    myData() {recCnt=0;}
    
    //---------------------------------------------------------------
    virtual void update()
    {
      recCnt++;
    }

    //---------------------------------------------------------------
    DWORD recCnt;
};

//*******************************************************************
cIPC_UART             ipcUART( uart, cCRC::FAST );
cIPC::Data<myData, 1> outUART( ipcUART  );
cIPC::Data<myData, 2> inUART ( ipcUART  );

cIPC_USBdevice         ipcUSB( usb, 0, cCRC::FAST );
cIPC::Data<myData, 11> outUSB( ipcUSB  );
cIPC::Data<myData, 12> inUSB ( ipcUSB  );

//*******************************************************************
int main(void)
{
  usb.start();
  
  while( 1 )
  {
    // IPC-UART
    ipcUART.update();

    if( inUART.isNew() )
    {
      outUART.data.cnt++;
      outUART.data.rec    =  inUART.prop.recCnt;
      outUART.data.random = -inUART.data.random;

      outUART.write();
    }

    // IPC-USB
    ipcUSB.update();

    if( inUSB.isNew() )
    {
      outUSB.data.cnt++;
      outUSB.data.rec    =  inUSB.prop.recCnt;
      outUSB.data.random = -inUSB.data.random;

      outUSB.write();
    }
  }
}

//EOF
