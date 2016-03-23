//*******************************************************************
/*!
\file   cHwEncoder_MCU.cpp
\author Thomas Breuer
\date   30.03.2015, 17.03.2016
\brief  Sample of using hardware related classes, MCU: STM32L1xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem   sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  USART1_TX_PA_9,
  USART1_RX_PA_10,
  
  // Timer (Encoder)
  TIM2_CH1_ETR_PA_0,
  TIM2_CH2_PA_1,
  
  TIM3_CH1_PB_4,
  TIM3_CH2_PB_5,
  
  TIM4_CH1_PB_6,
  TIM4_CH2_PB_7,
  
  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwEncoder_N enc ( cHwEncoder_N::TIM_2, cHwEncoder_N::NORMAL );

//*******************************************************************
#include "../../Common/cHwEncoder.cpp"
//*******************************************************************
