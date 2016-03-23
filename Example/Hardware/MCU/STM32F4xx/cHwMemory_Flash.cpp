//*******************************************************************
/*!
\file   cHwMemory_EEPROM.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016
\brief  Sample of using hardware related classes, MCU: STM32L1xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem   sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  USART6_RX_PC_7,
  USART6_TX_PC_6,
  
  USART3_RX_PC_11,
  USART3_TX_PC_10,

  cHwPinConfig::END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_6, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
cHwMemory_Flash mem( cHwMemory_Flash::SECTOR_11 );

//*******************************************************************
#include "../../Common/cHwMemory.cpp"
//*******************************************************************
