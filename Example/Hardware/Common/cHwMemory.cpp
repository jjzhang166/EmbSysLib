//*******************************************************************
/*!
\file   cHwMemory.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample of using hardware related class 'cHwMemory'
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
WORD addr = 0;
BYTE data = 0;
BYTE cnt  = 0;
char str[40];

//*******************************************************************
int main(void)
{
  uart.set( "\r\n\ncHwMemory,"__DATE__ ","__TIME__"\r\n\n" );

  data = mem.read( addr );
  cnt  = mem.read( addr+1 );

  sprintf( str, "read: %u (%u %u %u)\r\n", data,  mem.read( addr+1 ), mem.read( addr +2),mem.read( addr+3 )); //cnt );
  uart.set( str );

  data++;

  if( data > 4 )
  {
    uart.set( "clearing memory...\r\n" );
    mem.clear(); 
  }
  else
  {
    if( mem.isFlash() ) // block erase only
    {  
      uart.set( "erase flash\r\n" );
      mem.clear();
    }
    
    for(int i=0;i<4;i++)
    {
      mem.write(addr+i,data+i);
    }
    
    sprintf( str, "write: %u\r\n", data );
    uart.set( str );
  }

  uart.set( "done\r\n" );
  while(1)
  {
    sys.run();
  }
}
