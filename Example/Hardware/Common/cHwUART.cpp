//*******************************************************************
/*!
\file   cHwUART.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016

\brief  Sample of using hardware related class 'cHwUART'
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
BYTE value = 0;
BYTE cnt   = 0;
char str[40];

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwUART,"__DATE__ ","__TIME__"\r\n\n" );
  uart.set( "UART: \r\n" );

  while( 1 )
  {
    sys.run();

    if( uart.get( &value ) )
    {
      uart.set( value );

      sprintf(str, ":0x%02x ", value );
      uart.set( str );

      if( (cnt++) >= 7 )
      {
        cnt = 0;
        uart.set("\r\n");
      }
    }
  }
}
