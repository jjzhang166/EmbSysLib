//*******************************************************************
/*!
\file   cHwPort.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related classes
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
MTYPE value = 0;
char  str[40];
MTYPE a;
MTYPE b;

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwPort,"__DATE__ ","__TIME__"\r\n\n" );

  // set port as output
  portOut.setMode( 1<<pinOut_a, cHwPort::Out );

  // set pin as output
  pinOut_b.setMode( cHwPort::Out);

  while(1)
  {
    sys.run();

    // get input from port
    a = (portIn.get() & (1<<pinIn_a))?1:0;

    // set output to port
    value = (a<<pinOut_a);
    portOut.set(  value );
    portOut.clr( ~value );

    // get input from pin
    b = pinIn_b.get();

    // set output to pin
    if( b )
      pinOut_b.set();
    else
      pinOut_b.clr();


    #ifndef PORT_TERMINAL
    sprintf(str, "a: %d   b: %d\r\n", a, b );
    uart.set( str );
    #endif
  }
}
