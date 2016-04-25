//*******************************************************************
/*!
\file   cDevDisplay.cpp
\author Thomas Breuer
\date   15.02.2013
\brief  Sample Device Display (character)
*/

//*******************************************************************
#include "lib.h"
#include "config.h"

//===================================================================
#if defined _MCU_TYPE_STM32L1XX
//===================================================================
  cHwSPImaster_N    spi2( cHwSPImaster_N::SPI_2,
                          cHwSPImaster::CR_2000kHz,
                          cHwSPImaster::CPOL_H_CPHA_H );

  cHwSPImaster::Device spi  ( spi2, portB, 12 );
  cHwDisp_DIP204spi    disp ( spi );
  cDevDisplayChar      lcd  ( disp );
//===================================================================
#elif defined _MCU_TYPE_STM32F4XX
//===================================================================
//===================================================================
#endif
//===================================================================

//*******************************************************************
int main( void )
{
  BYTE cnt = 0;

  while( 1 )
  {
    sys.run();

    if( cnt == 0 )
    {
      lcd.clear();

      lcd.printf( 0, 0, 0, "cDevDisplayChar" );
      lcd.printf( 1, 0, 0, __DATE__ "," __TIME__"\r\n" );
      lcd.printf( 2, 0, 0, "123456789012345678901234567890" );
      lcd.printf( 3, 0, 0, "------------------------------" );
    }
    lcd.printf( 3, 3, 10, "cnt = %d", cnt++ );
  }
}
