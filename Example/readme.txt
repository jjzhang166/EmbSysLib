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
 Com-Port    |             | PA9  | UART1-RX
 Com-Port    |             | PA10 | UART1-TX
 Analog In   |             | PA2  | ADC-CH2
 Analog Out  |             | PA4  | DAC-CH1
 Push button |             | PC0  | GPIO
             | USER-button | PA0  | GPIO
             | LED blue    | PC8  | GPIO
             | LED green   | PC9  | GPIO
             | USB         | PA11 | USB-DM
             | USB         | PA12 | USB-DP
 ------------|-------------|------|------------


STM32F4xx
=========
IDE:         µVision 4.74

Test board:  STM32F4-DISCOVERY (STMicroelectronics)

Board configuration:

 ------------|-------------|------|------------
 External    | Onboard     | Port | Function
 ------------|-------------|------|------------
 Com-Port    |             | PC7  | USART6-RX
 Com-Port    |             | PC6  | USART6-TX
 Analog In   |             | PA2  | ADC-CH2
 Analog Out  |             | PA5  | DAC-CH2
 Push button |             | PA1  | GPIO
             | LED blue    | PD15 | GPIO
             | LED green   | PD12 | GPIO
             | USER-button | PA0  | GPIO
             | USB         | PA12 | USB-DP
             | USB         | PA12 | USB-DP
 ------------|-------------|------|------------
