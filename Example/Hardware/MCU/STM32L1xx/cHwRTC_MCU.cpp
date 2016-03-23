//*******************************************************************
/*!
\file   cHwRTC_MCU.cpp
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
  USART1_RX_PA_10,
  USART1_TX_PA_9,

  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_1, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
cHwRTC_0  rtc;

//*******************************************************************
#include "../../Common/cHwRTC.cpp"
//*******************************************************************
