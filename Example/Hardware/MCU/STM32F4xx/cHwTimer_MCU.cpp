//*******************************************************************
/*!
\file   cHwTimer_MCU.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016
\brief  Sample of using hardware related classes, MCU: STM32F4xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem        sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  USART6_RX_PC_7,
  USART6_TX_PC_6,
  
  // Timer (PWM)
  TIM2_CH1_PA_0,
  TIM2_CH2_PA_1,
  TIM2_CH3_PA_2,
  TIM2_CH4_PA_3,
  TIM4_CH2_PD_13,
  TIM4_CH3_PD_14,
  TIM4_CH4_PD_15,
  
  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_6, cHwUART::BR_9600, 100, 100 );


//*******************************************************************
cHwTimer_N     timerFast ( cHwTimer_N::TIM_4,   1000L/*us*/ );
cHwTimer_N     timerSlow ( cHwTimer_N::TIM_2,1000000L/*us*/ );

cHwTimer_N    &timerPWM = timerFast;

BYTE           timerPWMchannel = 3; // TIM4.CH4 on PD15

//*******************************************************************
#include "../../Common/cHwTimer.cpp"
//*******************************************************************
