//*******************************************************************
/*!
\file   cHwI2Cmaster_MCU.cpp
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

  // I2C
  I2C2_SCL_PB_10,
  I2C2_SDA_PB_11,

  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_1, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
#define HWADDR 0xB0   // I2C address for I2Cmaster/-slave test

cHwI2Cmaster_N       i2c_N( cHwI2Cmaster_N::I2C_2, 
                            cHwI2Cmaster::CR_100kHz );

cHwI2Cmaster::Device i2c  ( i2c_N, HWADDR  );

//*******************************************************************
#include "../../Common/cHwI2Cmaster.cpp"
//*******************************************************************
