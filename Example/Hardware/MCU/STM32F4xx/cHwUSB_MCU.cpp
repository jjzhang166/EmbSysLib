//*******************************************************************
/*!
\file   cHwUSB_MCU.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016
\brief  Sample of using hardware related classes, MCU: STM32F4xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem    sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  USART6_RX_PC_7,
  USART6_TX_PC_6,

  // USB
  OTG_FS_ID_PA_10,
  OTG_FS_DM_PA_11,
  OTG_FS_DP_PA_12,
  
  END_OF_TABLE
};


cHwUART_N  uart( cHwUART_N::USART_6, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
#include "../../Common/cHwUSB.cpp"
//*******************************************************************
