//*******************************************************************
/*!
\file   cHwSPImaster.cpp
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

  // SPI
  SPI2_MOSI_PB_15,
  SPI2_MISO_PB_14,
  SPI2_SCK_PB_13,

  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_1, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
cHwSPImaster_N        spi_N( cHwSPImaster_N::SPI_2, 
                             cHwSPImaster::CR_500kHz,
                             cHwSPImaster::CPOL_H_CPHA_H );

cHwPort_N             portD( cHwPort_N::PD );

cHwPort::Pin          spiCS( portD, 2 );

cHwSPImaster::Device  spi  ( spi_N, spiCS );

//*******************************************************************
#include "../../Common/cHwSPImaster.cpp"
//*******************************************************************
