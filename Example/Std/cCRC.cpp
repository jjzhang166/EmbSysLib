//*******************************************************************
/*!
\file   Std/cCRC.cpp
\author Thomas Breuer
\date   31.01.2013, 22.03.2016
\brief  Sample

  Calculates CRC16 with
    GP    = 0xA001
    Start = 0xFFFF

  Test condition:
    Test  = 0x01,0x23,0x45,0x67,0x89,0xAB
    CRC   = 0xF146

  \see http://www.lammertbies.nl/comm/info/crc-calculation.html (CRC-16, Modbus)
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//*******************************************************************
BYTE data[] = {0x01,0x23,0x45,0x67,0x89,0xAB};

//*******************************************************************
cCRC  crcCalulator_Fast ( cCRC::FAST  );
cCRC  crcCalulator_Small( cCRC::SMALL );

//*******************************************************************
int main(void)
{
  com.printf( "\r\n\n" __FILE__ "," __DATE__ "," __TIME__ "\r\n\n" );

  WORD crc;

  // print data
  com.printf( "data:      " );
  for(BYTE i = 0; i < sizeof(data); i++ )
  {
    com.printf( " 0x%02X", data[i] );  
  }
  com.printf( "\r\n" );

  // CRC calculation with table
  //----------------------------------------------
  crc = crcCalulator_Fast( data, sizeof( data ) );
  //----------------------------------------------

  com.printf( "CRC(FAST):  0x%04X\r\n", crc );

  // CRC calculation without table
  //----------------------------------------------
  crc = crcCalulator_Small( data, sizeof( data ) );
  //----------------------------------------------

  com.printf( "CRC(SMALL): 0x%04X\r\n", crc );

  while( 1 );
  {
  }
}
