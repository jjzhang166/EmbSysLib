//*******************************************************************
/*!
\file   cDevMemory.cpp
\author Thomas Breuer
\date   31.01.2013
\brief  Sample Device Memory
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
#include "stdio.h"

//===================================================================
#if defined _MCU_TYPE_STM32L1XX
//===================================================================

//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================
  cHwMemory_Flash    flash( cHwMemory_Flash::SECTOR_7);
//===================================================================
#endif
//===================================================================

//*******************************************************************
class myClass
{
  public:
    myClass( void )
    {
      strcpy(str,"new string");
      cnt = 0;
    }

  public:
    char str[20];
    WORD cnt;
};

//*******************************************************************
cDevMemoryFlash<myClass>  memory( flash );

//*******************************************************************
int main( void )
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  // Show stored data
  com.printf( "str: %s\r\n", memory.data.str );
  com.printf( "cnt: %d\r\n", memory.data.cnt );

  // Modify data
  memory.data.cnt  = (memory.data.cnt%3) + 1;
  sprintf( memory.data.str, "Step %d", memory.data.cnt );

  // Store modified data
  memory.store();
  
  int alive = 0;
  while( 1 )
  {
    com.printf( "alive %10d\r", alive++ );   
  }
}
