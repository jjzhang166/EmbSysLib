//*******************************************************************
/*!
\file   cSystem.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related class 'cSystem'
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
BYTE feedWD = true; // yes, feed watchdog
BYTE key    = 0;

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncSystem,"__DATE__ ","__TIME__"\r\n\n" );

  cSystem::enableWatchdog( cSystem::WD_TIMEOUT_1000ms );

  while( 1 )
  {
    if( uart.get( &key ) )
    {
      switch( key )
      {
        case 'r':  cSystem::reset();
                   break;

        case 'w':  feedWD = false;
                   break;
      }
    }

    if( feedWD )
    {
      cSystem::feedWatchdog();
    }
  }
}
