//*******************************************************************
/*!
\file   cHwDisplay.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related class cHwDisplay
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
int main(void)
{
  BYTE c   = 32;
  WORD cnt = 0;
  char txt[21];

  uart.set( "\r\n\ncHwDisplay,"__DATE__ ","__TIME__"\r\n\n" );

  disp.clear();

  for( BYTE line = 0; line < disp.getNumberOfLines() - 1; line++ )
  {
    for( BYTE column = 0; column < disp.getNumberOfColumns(); column++ )
    {
      disp.gotoTextPos( line, column );
      disp.putChar( c );
      c++;
    }
  }

  while(1)
  {
    sprintf(txt,"--- %6d ---------",cnt++);

    disp.gotoTextPos( disp.getNumberOfLines() - 1, 0 );
    for( WORD i = 0; txt[i] != 0; i++ )
    {
      disp.putChar( txt[i] );
    }
  }
}
