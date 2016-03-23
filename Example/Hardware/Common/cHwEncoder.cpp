//*******************************************************************
/*!
\file   cHwEncoder.cpp
\author Thomas Breuer
\date   30.03.2015
\brief  Sample of using hardware related classes

*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
char str[40];

int speed = 0;
int pos   = 0;

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwEncoder,"__DATE__ ","__TIME__"\r\n\n" );

  while( 1 )
  {
    sys.run();

    char str[40];

		speed  = enc.get();
		pos   += speed;
		
    sprintf( str, "speed: %5d,  pos: %5d\r", speed, pos );
    uart.set( str );
  }
}
