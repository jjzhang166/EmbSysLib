//*******************************************************************
/*!
\file   cHwSPImaster.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016
\brief  Sample of using hardware related classes, MCU: STM32F4xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem         sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  USART6_RX_PC_7,
  USART6_TX_PC_6,

  // SPI
  SPI1_MISO_PA_6,
  SPI1_MOSI_PA_7,
  SPI1_SCK_PA_5,

  SPI2_MISO_PB_14,
  SPI2_MOSI_PB_15,
  SPI2_SCK_PB_10,

  SPI3_MISO_PB_4,
  SPI3_MOSI_PB_5,
  SPI3_SCK_PB_3,

  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_6, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
cHwSPImaster_N       spi_N   ( cHwSPImaster_N::SPI_1, 
                               cHwSPImaster::CR_500kHz, 
                               cHwSPImaster::CPOL_H_CPHA_H );

cHwPort_N            portA   ( cHwPort_N::PA );

cHwPort::Pin         spiCS   ( portA, 4 );

cHwSPImaster::Device  spi  ( spi_N, spiCS );

//*******************************************************************
#include "../../Common/cHwSPImaster.cpp"
//*******************************************************************
