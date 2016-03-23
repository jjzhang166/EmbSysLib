//*******************************************************************
/*!
\file   cDevDigital.cpp
\author Thomas Breuer
\date   15.02.2013, 18.03.2016
\brief  Sample code, class cDevDigital
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
#include <stdio.h>

//*******************************************************************
//===================================================================
#if defined _MCU_TYPE_STM32L1XX
//===================================================================
  cDevDigital ledA( portC,  8, cDevDigital::Out,  0 );
  cDevDigital ledB( portC,  9, cDevDigital::Out,  0 );
  cDevDigital btnA( portC,  0, cDevDigital::InPU, 1 );
  cDevDigital btnB( portA,  0, cDevDigital::In  , 0 );
//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================
  cDevDigital ledA( portD, 12, cDevDigital::Out,  0 );
  cDevDigital ledB( portD, 15, cDevDigital::Out,  0 );
  cDevDigital btnA( portA,  0, cDevDigital::In  , 0 );
  cDevDigital btnB( portA,  1, cDevDigital::In  , 0 );
//===================================================================
#endif
//===================================================================

//*******************************************************************
class cReport
{
  public:
    //---------------------------------------------------------------
    cReport( cDevDigital &btnIn )
    : btn(btnIn)
    {
      txtEvent = "---";
      txtState = "---";
      cnt      = 0;
    }

    //---------------------------------------------------------------
    char *evaluate( void )
    {
      if( btn.isChanged()   )  { cnt = (cnt+1)%10; }
      if( btn.isClr()       )  { txtState = "clr"; }
      if( btn.isSet()       )  { txtState = "set"; }
      if( btn.isReleased()  )  { txtEvent = "rel"; }
      if( btn.isActivated() )  { txtEvent = "act"; }

      sprintf( txt, "%s,%s,%d", txtEvent, txtState, cnt );
      return( txt );
  }

  private:
    //---------------------------------------------------------------
    const char  *txtEvent;
    const char  *txtState;
    char         txt[32];
    BYTE         cnt;
    cDevDigital &btn;
};

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  cReport A( btnA );
  cReport B( btnB );

  while( 1 )
  {
    btnA.update();
    btnB.update();
     
    if( btnA.isActivated() )
    {
      ledA.toggle();
    }

    ledB = btnB;
    
    //  if( btnB )
    //  {
    //    ledA = false;
    //  }
    
    com.printf( "%s  %s\r", A.evaluate(), B.evaluate() );
  }
}
