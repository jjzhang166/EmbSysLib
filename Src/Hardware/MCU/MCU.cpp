//*******************************************************************
/*!
\file   Hardware/MCU/MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief Summary of MCU related code
*/

//*******************************************************************
//===================================================================
#if defined _MCU_TYPE_STM32F4XX

  #include "Hardware/MCU/STM32F4xx/MCU_STM32F4xx.cpp"

//===================================================================
#elif defined _MCU_TYPE_STM32L1XX

  #include "Hardware/MCU/STM32L1xx/MCU_STM32L1xx.cpp"

//===================================================================
#elif defined _MCU_TYPE_VIRTUAL

  #include "Hardware/MCU/Virtual/MCU_Virtual.cpp"

//===================================================================
#else
  #error "MCU.cpp: device type not defined"
#endif
//===================================================================

// EOF
