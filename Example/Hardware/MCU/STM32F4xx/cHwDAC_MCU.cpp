//*******************************************************************
/*!
\file   cHwDAC_MCU.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016
\brief  Sample of using hardware related classes, MCU: STM32F4xx
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

  // DAC
  DAC1_OUT_PA_4,
  DAC2_OUT_PA_5,

  cHwPinConfig::END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_6, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
cHwDAC_0   dac;

//*******************************************************************
#include "../../Common/cHwDAC.cpp"
//*******************************************************************
