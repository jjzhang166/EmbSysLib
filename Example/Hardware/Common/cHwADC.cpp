//*******************************************************************
/*!
\file   cHwADC.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related class cHwADC
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
int main(void)
{
  WORD value;
  BYTE ch = 0;
  BYTE key;
  char str[30];

  uart.set( "\r\n\ncHwADC,"__DATE__ ","__TIME__"\r\n\n" );

  for( BYTE i=0; i<adc.getNumberOfChannels(); i++ )
  {
    adc.enable( i );
  }

  while( 1 )
  {
    sys.run();

    adc.update();

    value = adc.get( ch );

    sprintf( str, "\rADC(%d): %5u  \r", ch, value );
    uart.set( str );

    // select channel
    if( uart.get( &key ) )
    {
      switch( key )
      {
        case 'n': if( ch+1 < adc.getNumberOfChannels() ) ch++; break;
        case 'p': if( ch   > 0                         ) ch--; break;
      }
    }
  }
}
