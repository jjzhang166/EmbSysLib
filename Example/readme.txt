Example and test conditions
===========================

STM32L1xx
=========
IDE:         µVision 4.74

Test board:  32L100C-DISCOVERY (STMicroelectronics)

Board configuration:

 ------------|-------------|------|------------
 External    | Onboard     | Port | Function
 ------------|-------------|------|------------
             | USER-button | PA0  | GPIO
             | LED blue    | PC8  | GPIO
             | LED green   | PC9  | GPIO
             | USB         | PA11 | USB-DM
             | USB         | PA12 | USB-DP
 ------------|-------------|------|------------
 Com-Port    |             | PA9  | UART1-RX
 Com-Port    |             | PA10 | UART1-TX
 Analog In   |             | PA2  | ADC-CH2
 Analog Out  |             | PA4  | DAC-CH1
 Push button |             | PC0  | GPIO
 ------------|-------------|------|------------
 LCD         |             | PB15 | SPI2-MOSI
 LCD         |             | PB14 | SPI2-MISO
 LCD         |             | PB13 | SPI2-SCK
 LCD         |             | PB12 | GPIO (SS)


STM32F4xx
=========
IDE:         µVision 4.74

Test board:  STM32F4-DISCOVERY (STMicroelectronics)

Board configuration:

 ------------|-------------|------|------------
 External    | Onboard     | Port | Function
 ------------|-------------|------|------------
             | LED blue    | PD15 | GPIO
             | LED green   | PD12 | GPIO
             | USER-button | PA0  | GPIO
             | USB         | PA12 | USB-DP
             | USB         | PA12 | USB-DP
 ------------|-------------|------|------------
 Com-Port    |             | PC7  | USART6-RX
 Com-Port    |             | PC6  | USART6-TX
 Analog In   |             | PA2  | ADC-CH2
 Analog Out  |             | PA5  | DAC-CH2
 Push button |             | PA1  | GPIO
 ------------|-------------|------|------------
 LCD         |             | PC3  | SPI2-MOSI
 LCD         |             | PC2  | SPI2-MISO
 LCD         |             | PB10 | SPI2-SCK
 LCD         |             | PB14 | GPIO (SS)
