//*******************************************************************
/*!
\file   Lib/Example/main.cpp
\author Thomas Breuer
\date   15.02.2013, 17.03.2016
\brief  Samples
*/

//*******************************************************************
// Uncomment the desired example file.
//*******************************************************************

//-------------------------------------------------------------------
// Hardware - MCU - STM32L1xx
//-------------------------------------------------------------------
//
//                                                            Test
//
//#include "Hardware/MCU/STM32L1xx/cHwADC_MCU.cpp"            // ok
//#include "Hardware/MCU/STM32L1xx/cHwDAC_MCU.cpp"            // ok
//#include "Hardware/MCU/STM32L1xx/cHwEncoder_MCU.cpp"        // not tested
//#include "Hardware/MCU/STM32L1xx/cHwI2Cmaster_MCU.cpp"      // not tested
//#include "Hardware/MCU/STM32L1xx/cHwMemory_EEPROM.cpp"      // ok
//#include "Hardware/MCU/STM32L1xx/cHwMemory_Flash.cpp"       // ok
//#include "Hardware/MCU/STM32L1xx/cHwMemory_RAM.cpp"         // ok
//#include "Hardware/MCU/STM32L1xx/cHwPort_MCU.cpp"           // ok
//#include "Hardware/MCU/STM32L1xx/cHwRTC_MCU.cpp"            // ok
//#include "Hardware/MCU/STM32L1xx/cHwRTOS_MCU.cpp"           // ok
//#include "Hardware/MCU/STM32L1xx/cHwSPImaster_MCU.cpp"      // not tested
//#include "Hardware/MCU/STM32L1xx/cHwTimer_MCU.cpp"          // ok
//#include "Hardware/MCU/STM32L1xx/cHwUART_MCU.cpp"           // ok
//#include "Hardware/MCU/STM32L1xx/cHwUSB_MCU.cpp"            // ok
//#include "Hardware/MCU/STM32L1xx/cSystem_MCU.cpp"           // ok

//-------------------------------------------------------------------
// Hardware - MCU - STM32F4xx
//-------------------------------------------------------------------
//
//                                                            Test
//
//#include "Hardware/MCU/STM32F4xx/cHwADC_MCU.cpp"            // ok
//#include "Hardware/MCU/STM32F4xx/cHwDAC_MCU.cpp"            // ok
//#include "Hardware/MCU/STM32F4xx/cHwEncoder_MCU.cpp"        // not tested
//#include "Hardware/MCU/STM32F4xx/cHwI2Cmaster_MCU.cpp"      // not tested
//#include "Hardware/MCU/STM32F4xx/cHwMemory_RAM.cpp"         // ok
//#include "Hardware/MCU/STM32F4xx/cHwMemory_Flash.cpp"       // ok
//#include "Hardware/MCU/STM32F4xx/cHwPort_MCU.cpp"           // ok
//#include "Hardware/MCU/STM32F4xx/cHwRTC_MCU.cpp"            // ok
//#include "Hardware/MCU/STM32F4xx/cHwRTOS_MCU.cpp"           // ok
//#include "Hardware/MCU/STM32F4xx/cHwSPImaster_MCU.cpp"      // not tested
//#include "Hardware/MCU/STM32F4xx/cHwTimer_MCU.cpp"          // ok
//#include "Hardware/MCU/STM32F4xx/cHwUART_MCU.cpp"           // ok
//#include "Hardware/MCU/STM32F4xx/cHwUSB_MCU.cpp"            // ok
//#include "Hardware/MCU/STM32F4xx/cSystem_MCU.cpp"           // ok

//-------------------------------------------------------------------
// Hardware - Peripheral
//-------------------------------------------------------------------
// Cross mapping of supported peripheral hardware and sample code
//
// legend:
//
//    yes    target supports the peripheral device
//    no     no support
//    no*    not yet, but maybe in future
//    nt     not tested
//    (y)    yes, but not tested or properly configured
//
//                                                Target:  +STM32L1
//                                                         |   +STM32F4
//                                                         |   |
//                                                         |   |
//#include "Hardware/Peripheral/cHwDisp_DIP204spi.cpp" // ok  ok

//-------------------------------------------------------------------
//
//                                          Target:  +STM32L1
//                                                   |   +STM32F4
//                                                   |   |
//                                                   |   |
// Device                                            |   |
// ------                                            |   |
//#include "Device/cDevAnalog.cpp"               // ok  ok 
//#include "Device/cDevDigital.cpp"              // ok  ok 
//#include "Device/cDevDisplayChar.cpp"          // nt  nt 
//
#include "Device/cDevMemoryFlash.cpp"          // nt  nt 
//#include "Device/cDevTextIO.cpp"               // ok  ok 
//                                                   |   |
// Module                                            |   |
// ------                                            |   |
//#include "Module/IPC/cIPC.cpp"                 // ok  ok 
//#include "Module/RTOS/cRTOS.cpp"               // ok  ok 
//#include "Module/USB/cUSBinterfClassVSC.cpp"   // ok  ok 
//                                                   |   |
// Std                                               |   |
// ---                                               |   |
//#include "Std/cCRC.cpp"                        // ok  ok 
//#include "Std/cFifo.cpp"                       // ok  ok 
//#include "Std/cList.cpp"                       // ok  ok 
//#include "Std/cSharedMem.cpp"                  // ok  ok 
//#include "Std/cTimer.cpp"                      // ok  ok 
//                                                   |   |
// Task                                              |   |
// ----                                              |   |
//#include "Task/cTaskHandler.cpp"               // ok  ok 

//EOF
