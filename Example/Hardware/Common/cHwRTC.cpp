//*******************************************************************
/*!
\file   cHwRTC.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related class 'cHwRTC'
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
char str[40];

//*******************************************************************
int main(void)
{
  cHwRTC::Properties prop;
  
  uart.set( "\r\n\ncHwRTC,"__DATE__ ","__TIME__"\r\n\n" );

  rtc.get( prop );

  prop.second = 0;

  rtc.set( prop );

  while( 1 )
  {
    sys.run();

    rtc.get( prop );

    sprintf( str, "RTC: %02u.%02u.%04u  %02u:%02u:%02u\r",
                  prop.day,
                  prop.month,
                  prop.year,
                  prop.hour,
                  prop.minute,
                  prop.second );
    uart.set( str );
  }
}
