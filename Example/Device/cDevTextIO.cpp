//*******************************************************************
/*!
\file   cDevTextIO.cpp
\author Thomas Breuer
\date   15.02.2013, 18.03.2016
\brief  Sample code, class cDevTextIO
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
cDevTextIO_UART  text_IO( uart, 30, 30, "#\r\n", " +-ABCD123\r\t" );
//                              |   |    |        |
//                              |   |    |        +- list of single keys
//                              |   |    +---------- list of terminating 
//                              |   |                characters
//                              |   +--------------- output buffer size
//                              +------------------- input buffer size

//*******************************************************************
int main( void )
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  while( 1 )
  {
    if( char *str = text_IO.getString() )
    {
      switch( (BYTE)str[0] )
      {
        case 0xC1: text_IO.printf( "<Ctrl up>   \r\n" ); break;
        case 0xC2: text_IO.printf( "<Ctrl down> \r\n" ); break;
        case 0xC3: text_IO.printf( "<Ctrl right>\r\n" ); break;
        case 0xC4: text_IO.printf( "<Ctrl left> \r\n" ); break;
        default:   text_IO.printf( "-->%s\r\n", str   ); break;
      }
    }
  }
}
