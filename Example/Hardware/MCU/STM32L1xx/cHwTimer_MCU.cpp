//*******************************************************************
/*!
\file   cHwTimer_MCU.cpp
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
  USART1_TX_PA_9,
  USART1_RX_PA_10,
  
  // Timer (PWM)
  TIM2_CH1_ETR_PA_0,
  TIM2_CH2_PA_1,
  TIM2_CH3_PA_2,
  TIM2_CH4_PA_3,
  
  TIM3_CH1_PB_4,
  TIM3_CH2_PB_5,
  TIM3_CH3_PB_0,
  TIM3_CH4_PB_1,
  
  TIM4_CH1_PB_6,
  TIM4_CH2_PB_7,
  TIM4_CH3_PB_8,
  TIM4_CH4_PB_9,
  
  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_1, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwTimer_N     timerFast ( cHwTimer_N::TIM_3,    1000L/*us*/ );
cHwTimer_N     timerSlow ( cHwTimer_N::TIM_6, 1000000L/*us*/ );

cHwTimer_N    &timerPWM = timerFast;

BYTE           timerPWMchannel = 3; /* TIM3.CH4 on PB1 */

//*******************************************************************
#include "../../Common/cHwTimer.cpp"
//*******************************************************************
