//*******************************************************************
/*!
\file   cHwADC_MCU.cpp
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

  // ADC
  ADC123_IN0_PA_0,
  ADC123_IN1_PA_1,
  ADC123_IN2_PA_2,
  ADC123_IN3_PA_3,
  ADC12_IN4_PA_4,
  ADC12_IN5_PA_5,
  ADC12_IN6_PA_6,
  ADC12_IN7_PA_7,
  ADC12_IN8_PB_0,
  ADC12_IN9_PB_1,
  ADC123_IN10_PC_0,
  ADC123_IN11_PC_1,
  ADC123_IN12_PC_2,
  ADC123_IN13_PC_3,
  ADC12_IN14_PC_4,
  ADC12_IN15_PC_5,

  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_6, cHwUART::BR_9600, 100, 100 );

//*******************************************************************
cHwADC_0   adc;

//*******************************************************************
#include "../../Common/cHwADC.cpp"
//*******************************************************************
