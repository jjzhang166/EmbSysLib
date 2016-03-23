//*******************************************************************
/*!
\file   Lib/Example/Device/config.h
\author Thomas Breuer
\date   31.01.2013
\brief  Configuration file
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem sys;

//===================================================================
#if defined _MCU_TYPE_STM32L1XX
//===================================================================
  cHwPinConfig::MAP cHwPinConfig::table[] = 
  {
    // UART
    USART1_TX_PA_9,
    USART1_RX_PA_10,

    // ADC
    ADC12_IN2_PA_2,

    // DAC
    DAC_OUT1_PA_4,

    // Timer
    TIM3_CH3_PC_8,
    
    END_OF_TABLE
  };
  
  cHwPort_N    portA   ( cHwPort_N::PA );
  cHwPort_N    portB   ( cHwPort_N::PB );
  cHwPort_N    portC   ( cHwPort_N::PC );
  cHwTimer_N   timer   ( cHwTimer_N::TIM_2, 1000 );
  cHwTimer_N   timerPWM( cHwTimer_N::TIM_3, 4095 );
  cHwADC_0     adc     ( &timer );
  cHwDAC_0     dac;
  cHwUART_N    uart    ( cHwUART_N::USART_1, 
                         cHwUART::BR_9600, 
                         100, 
                         100 );
  
//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================
  
  cHwPinConfig::MAP cHwPinConfig::table[] = 
  {
    // UART
    USART6_RX_PC_7,
    USART6_TX_PC_6,
    
    // ADC
    ADC123_IN2_PA_2,
    
    // DAC
    DAC2_OUT_PA_5,
    
    // Timer
    TIM4_CH1_PD_12,
      
    END_OF_TABLE
  };

  cHwPort_N    portA   ( cHwPort_N::PA );
  cHwPort_N    portD   ( cHwPort_N::PD );
  cHwTimer_N   timer   ( cHwTimer_N::TIM_4, 1000 );
  cHwTimer_N  &timerPWM = timer; 
  cHwADC_0     adc     ( &timer );
  cHwDAC_0     dac;
  cHwUART_N    uart    ( cHwUART_N::USART_6, 
                         cHwUART::BR_9600, 
                         100, 
                         100 );
  
//===================================================================
#else
  #error "config.h: device type not defined"
#endif
//===================================================================

cDevTextIO_UART com ( uart, 100, 100 ); 

//EOF
