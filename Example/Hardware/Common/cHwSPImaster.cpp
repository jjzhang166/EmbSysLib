//*******************************************************************
/*!
\file   cHwSPImaster.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
BYTE dataOut = 0;
BYTE dataIn  = 0;
BYTE addr    = 0;
BYTE ok      = true;
char str[50];

//*******************************************************************
int main( void )
{
  uart.set( "\r\n\ncHwSPImaster,"__DATE__ ","__TIME__"\r\n\n" );

  while( 1 )
  {
    sys.run();

    dataOut = rand();

    spi.transceive( addr|0x80 );
    cSystem::delayMilliSec(1);

    spi.transceive( dataOut );
    cSystem::delayMilliSec(1);

    spi.transceive( addr&0x7F );
    cSystem::delayMilliSec(1);

    dataIn = spi.transceive( 0 );
    cSystem::delayMilliSec(1);

    if( dataIn != dataOut )
    {
      ok = false;
    }

    sprintf( str, "addr: 0x%02x,  write: 0x%02x,  read: 0x%02x, %s\r",
                  addr,
                  dataOut,
                  dataIn,
                  ok ? "OK" : "not OK" );
    uart.set( str );

    addr++;
  }
}
