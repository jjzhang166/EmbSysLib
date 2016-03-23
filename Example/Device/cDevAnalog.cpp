//*******************************************************************
/*!
\file   cDevAnalog.cpp
\author Thomas Breuer
\date   31.01.2013, 18.03.2016
\brief  Sample code, class cDevAnalog
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
//===================================================================
#if defined _MCU_TYPE_STM32L1XX
//===================================================================
  cDevDigital          led ( portC,  9, cDevDigital::Out, 0 );
  
  cDevAnalogInADC      in  ( adc,                        2, 3.0, 0.0 );
  cDevAnalogOutDAC     outA( dac,                        0, 3.0, 0.0 );
  cDevAnalogOutPWM     outB( timerPWM, cHwTimer::NORMAL, 2, 3.0, 0.0 );
  cDevAnalogOutPWMemul outC( timer,    led, 4/*bit*/,       3.0, 0.0 );
//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================
  cDevDigital          led ( portD, 15, cDevDigital::Out, 0 );
  
  cDevAnalogInADC      in  ( adc,                        2, 3.0, 0.0 );
  cDevAnalogOutDAC     outA( dac,                        1, 3.0, 0.0 );
  cDevAnalogOutPWM     outB( timerPWM, cHwTimer::NORMAL, 0, 3.0, 0.0 );
  cDevAnalogOutPWMemul outC( timer,    led, 4/*bit*/,       3.0, 0.0 );
//===================================================================
#endif
//===================================================================

//*******************************************************************
int main( void )
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );
  
  while( 1 )
  {
    WORD  w = in.getRaw();
    float f = in;

    outA = in;
    outB = f;
    outC.setRaw( w );

    com.printf( "ADC: %6.3f (%5u)\r", f, w );
  }
}
