//*******************************************************************
/*!
\file   cHwPort_MCU.cpp
\author Thomas Breuer
\date   31.01.2013, 17.03.2016
\brief  Sample of using hardware related classes, MCU: STM32F4xx
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
cSystem     sys;

cHwPinConfig::MAP cHwPinConfig::table[] = 
{
  // UART
  USART6_RX_PC_7,
  USART6_TX_PC_6,
  
  END_OF_TABLE
};

cHwUART_N  uart( cHwUART_N::USART_6, cHwUART::BR_9600, 100, 100 );
  
//*******************************************************************
cHwPort_N portIn ( cHwPort_N::PA ); // define an input port 
cHwPort_N portOut( cHwPort_N::PD ); // define an output port

// using port-class:
BYTE pinIn_a  =  0;
BYTE pinOut_a = 12;

// using pin-class:
cHwPort::Pin  pinIn_b ( portIn,   1 );
cHwPort::Pin  pinOut_b( portOut, 15 );

//*******************************************************************
#include "../../Common/cHwPort.cpp"
//*******************************************************************
