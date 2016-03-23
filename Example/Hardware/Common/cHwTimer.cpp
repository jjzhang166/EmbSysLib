//*******************************************************************
/*!
\file   cHwTimer.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes

\todo getNumberOfTimers / hasPWM???
\todo use different PWM-channels? 
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
char str[40];

//*******************************************************************
class cTest : public cList::Item
{
  public:
    //---------------------------------------------------------------
    cTest( cHwTimer &timer )
    {
      timer.add( this );

      cnt = 0;
    }

    //---------------------------------------------------------------
    virtual void update( void )
    {
      cnt = ((cnt < 99999) ? (cnt + 1) : 0);
    }

    //---------------------------------------------------------------
    WORD cnt;
};

//*******************************************************************
int main(void)
{
  cTest          testFast( timerFast );
  cTest          testSlow( timerSlow );

  timerPWM.enablePWM( timerPWMchannel );

  uart.set( "\r\n\ncHwTimer,"__DATE__ ","__TIME__"\r\n\n" );

  while( 1 )
  {
    sys.run();

    char str[40];

    timerPWM.setPWM( testFast.cnt<<4, timerPWMchannel );

    sprintf( str, "fast: %5u,  slow: %5u\r",
                  testFast.cnt,
                  testSlow.cnt);

    uart.set( str );
  }
}
