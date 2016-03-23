//*******************************************************************
/*!
\file   cUSBinterfClassVSC.cpp
\author Thomas Breuer
\date   18.03.2016
\brief  Sample code, class cUSBinterfClassVSC

Install Driver_n from "EmbCpp\Lib\Example\Module\USB\Driver". 
Run "EmbCpp\Lib\Tools\USB-HostLibusb\USB-Host.bat"
*/

//*******************************************************************
#include "lib.h"
#include "Module/USB/USBinterfClassVSC.h"
#include "config.h"

//*******************************************************************
#include "descriptor_VSC.cpp" // Include automatic generated 
                              // descriptor

//*******************************************************************
cHwUSBdesc_0   desc;
cHwUSB_0       usb( desc );

//*******************************************************************
__packed class cData
{
  public:
    //---------------------------------------------------------------
    cData()
    {
      data = 0;
      tCnt = 0;
      rCnt = 0;
      tep = 0xff;
      rep = 0xff;
    }

  public:
    //---------------------------------------------------------------
    DWORD data;
    DWORD tCnt;
    DWORD rCnt;
    DWORD id;
    DWORD tep;
    DWORD rep;
    DWORD dummy[2];
};

//*******************************************************************
typedef cData cDataIN;
typedef cData cDataOUT;

//*******************************************************************
class cMyInterf : public cUSBinterfClassVSC< cDataIN, cDataOUT >
{
  public:
    //---------------------------------------------------------------
    cMyInterf( cHwUSB &usb, BYTE interfId )

    : cUSBinterfClassVSC( usb, 1 /*configId*/, interfId )
    {
      id          = interfId;
      transmitCnt = 0;
      receiveCnt  = 0;
    }

    //---------------------------------------------------------------
    virtual int onTransmit( cDataOUT &data )
    {
      dataLoc.tCnt  = ++transmitCnt;
      dataLoc.id    = id;
      dataLoc.tep   = 0x8F;
      data = dataLoc;
      return( true );
    }

    //---------------------------------------------------------------
    virtual int onReceive(cDataIN &data)
    {
      dataLoc      = data;
      dataLoc.rCnt = --receiveCnt;
      dataLoc.rep  = 0x0F;
      return( true );
    }

  public:
    //---------------------------------------------------------------
    int   transmitCnt;
    int   receiveCnt;
    BYTE  id;
    cData dataLoc;

};

//*******************************************************************
int main( void )
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  WORD cnt = 0;

  cMyInterf  interface_0( usb, 0 );
  cMyInterf  interface_1( usb, 1 );
  cMyInterf  interface_2( usb, 2 );
  //                           ^-- interfId

  usb.start();

  while(1)
  {
    interface_0.dataLoc.id = cnt++;
  }
}
