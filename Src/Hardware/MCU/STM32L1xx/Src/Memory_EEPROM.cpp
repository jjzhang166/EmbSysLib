//*******************************************************************
/*!
\file   Memory_EEPROM.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Memory_EEPROM.h"

//*******************************************************************
//
// cHwMemory_EEPROM
//
//*******************************************************************
//-------------------------------------------------------------------
cHwMemory_EEPROM::cHwMemory_EEPROM( void )

: cHwMemory( 0x2000, // size
             0x00 )  // default value

{
  ptr = (BYTE*)0x08080000; // see Datasheet, Table 8 to 11
}

//-------------------------------------------------------------------
void cHwMemory_EEPROM::writeByte( DWORD addr, BYTE data )
{
  FLASH->PEKEYR = 0x89ABCDEF;
  FLASH->PEKEYR = 0x02030405;
  
  FLASH->PECR &= ~FLASH_PECR_FTDW;
  while( FLASH->SR & FLASH_SR_BSY );
  ptr[addr] = data;
  
  FLASH->PECR |= FLASH_PECR_PELOCK;
}

//-------------------------------------------------------------------
BYTE cHwMemory_EEPROM::readByte( DWORD addr )
{
  return( ptr[addr] );
}

//EOF
