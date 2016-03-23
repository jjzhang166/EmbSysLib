#include "lib.h"

#include "descriptor.cpp"

//-----------------------------------------------------------------
__packed class cData
{
  public:
    cData()
    {    
      data = 0;
      tCnt = 0;
      rCnt = 0;
      tep = 0xff;
      rep = 0xff;
    }
    
    DWORD data;
    DWORD tCnt;
    DWORD rCnt;
    DWORD id;
    DWORD tep;
    DWORD rep;
    DWORD dummy[2];
};


//-----------------------------------------------------------------
class cMyInterf : public cHwUSBinterf
{
  public:
    //---------------------------------------------------------------
    cMyInterf( cHwUSB &usb, BYTE interfId )
  
    : cHwUSBinterf( usb, 1/*configId*/, interfId )

    {
      id          = interfId;
      transmitCnt = 0;
      receiveCnt  = 0;
    }

   //---------------------------------------------------------------
    virtual bool transmit(BYTE epId,cDataPointer &data)
    {
      dataLoc.tCnt  = --transmitCnt;
      dataLoc.id    = id;
      dataLoc.tep   = epId;
      data.set( dataLoc );
      return(true);              
    }

    //---------------------------------------------------------------
    virtual bool receive(BYTE epId, WORD cnt)
    {
      dataLoc      = dataBuf;
      dataLoc.rCnt = ++receiveCnt;
      dataLoc.rep  = epId;
      
      return(true);
    }

    //---------------------------------------------------------------
    virtual bool requestCtrlIN( cDataPointer &dataPtr, 
                                BYTE          request,
                                WORD          value, 
                                WORD          length )
    {
        dataLoc.tCnt  = --transmitCnt;
        dataLoc.id    = id;
        dataLoc.tep   = 0x80;
        dataPtr.set( dataLoc );
        return( true );
    }

    //---------------------------------------------------------------
    virtual bool requestCtrlOUT( cDataPointer &dataPtr, 
                                 BYTE          request,
                                 WORD          value, 
                                 WORD          length )
    {
       dataPtr = dataBuf;
       return( true );
    }

    //---------------------------------------------------------------
    virtual bool request( BYTE epId, cDataPointer &epdata )
    {
      epdata = dataBuf;
      return( true );
    }
    
    //---------------------------------------------------------------
    cData dataBuf;
    cData dataLoc;
    int   transmitCnt;
    int   receiveCnt;
    BYTE  id;
    
};


//*******************************************************************
cHwUSBdesc_0  desc;
cHwUSB_0      usb( desc );
cMyInterf     interface_0(usb, 0 );    
    
//*******************************************************************
int main(void)
{
  usb.start();

  uart.set( "\r\n\ncHwUSB,"__DATE__ ","__TIME__"\r\n\n" );

  while(1)
  {
  }
}
