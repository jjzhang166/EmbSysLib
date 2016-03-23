//*******************************************************************
/*!
\file   cHwDAC.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related class 'cHwDAC'
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
WORD value = 0;
BYTE ch    = 0;
BYTE step  = 0;
BYTE key   = 0;
char str[40];

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwDAC,"__DATE__ ","__TIME__"\r\n\n" );

  for( BYTE i=0; i<dac.getNumberOfChannels(); i++ )
  {
    dac.enable( i );
  }

  while(1)
  {
    dac.set( value, ch );

    sprintf(str, "\rDAC(%d): %5u (0x%04x)  \r", ch, value, value );
    uart.set( str );

    if( uart.get( &key ) )
    {
      switch( key )
      {
        // set amplitude
        case '+': if( step < 32 ) step++;    break;
        case '-': if( step >  0 ) step--;    break;
        
        // select channel
        case 'n': if( ch+1 < dac.getNumberOfChannels() ) ch++; break;
        case 'p': if( ch   > 0                         ) ch--; break;
      }
      value = (WORD)((DWORD)0xFFFF*step/32);
    }
  }
}
