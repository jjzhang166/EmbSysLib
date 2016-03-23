//*******************************************************************
/*!
\file   cHwI2Cmaster_MCU.cpp
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
  cHwPinConfig::USART6_RX_PC_7,
  cHwPinConfig::USART6_TX_PC_6,
  
  // I2C
  cHwPinConfig::I2C1_SCL_PB_6,
  cHwPinConfig::I2C1_SDA_PB_7,

  cHwPinConfig::I2C2_SCL_PB_10,
  cHwPinConfig::I2C2_SDA_PB_11,

  cHwPinConfig::I2C3_SCL_PA_8,
  cHwPinConfig::I2C3_SDA_PC_9,

  cHwPinConfig::END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_6, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
#define HWADDR 0xB0   // I2C address for I2Cmaster/-slave test

cHwI2Cmaster_N       i2c_N( cHwI2Cmaster_N::I2C_2, 
                            cHwI2Cmaster::CR_100kHz );

cHwI2Cmaster::Device i2c  ( i2c_N, HWADDR );

//*******************************************************************
#include "../../Common/cHwI2Cmaster.cpp"
//*******************************************************************
