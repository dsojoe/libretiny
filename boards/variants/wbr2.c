/* This file was auto-generated from wbr2.json using boardgen */

#include <Arduino.h>

#ifdef LT_VARIANT_INCLUDE
#include LT_VARIANT_INCLUDE
#endif

// clang-format off
PinInfo lt_arduino_pin_info_list[PINS_COUNT] = {
	// D0: PA19, SD_D0, SPI0_MOSI, UART2_CTS, I2C0_SCL, PWM7
	{PIN_A19, PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_I2C | PIN_SPI | PIN_UART,  PIN_NONE, 0},
	// D1: PA18, SD_CLK, PWM6
	{PIN_A18, PIN_GPIO | PIN_IRQ | PIN_PWM,                                 PIN_NONE, 0},
	// D2: PA13, UART0_RX, PWM7
	{PIN_A13, PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_UART,                      PIN_NONE, 0},
	// D3: PA17, SD_CMD, PWM5
	{PIN_A17, PIN_GPIO | PIN_IRQ | PIN_PWM,                                 PIN_NONE, 0},
	// D4: PA14, SD_INT, UART0_TX, PWM2
	{PIN_A14, PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_UART,                      PIN_NONE, 0},
	// D5: PA20, SD_D1, SPI0_MISO, UART2_RTS, I2C0_SDA, PWM0
	{PIN_A20, PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_I2C | PIN_SPI | PIN_UART,  PIN_NONE, 0},
	// D6: PA12, FD3, UART0_RX, I2C0_SDA, PWM1
	{PIN_A12, PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_I2C | PIN_UART,            PIN_NONE, 0},
	// D7: PA11, FD0, UART0_TX, I2C0_SCL, PWM0
	{PIN_A11, PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_I2C | PIN_UART,            PIN_NONE, 0},
	// D8: PA16, SD_D3, SPI0_SCK, UART2_TX, I2C0_SDA, PWM4
	{PIN_A16, PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_I2C | PIN_SPI | PIN_UART,  PIN_NONE, 0},
	// D9: PA15, SD_D2, SPI0_CS, UART2_RX, I2C0_SCL, PWM3
	{PIN_A15, PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_I2C | PIN_SPI | PIN_UART,  PIN_NONE, 0},
	// D10: PA00, TCK, UART1_RX, PWM0, SWCLK
	{PIN_A0,  PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_JTAG | PIN_SWD | PIN_UART, PIN_NONE, 0},
	// D11: PA01, TMS, UART1_TX, PWM1, SWDIO
	{PIN_A1,  PIN_GPIO | PIN_IRQ | PIN_PWM | PIN_JTAG | PIN_SWD | PIN_UART, PIN_NONE, 0},
};

PinInfo *lt_arduino_pin_gpio_map[] = {
	[0]  = &(lt_arduino_pin_info_list[10]), // PIN_A0 (D10)
	[1]  = &(lt_arduino_pin_info_list[11]), // PIN_A1 (D11)
	[11] = &(lt_arduino_pin_info_list[7]),  // PIN_A11 (D7)
	[12] = &(lt_arduino_pin_info_list[6]),  // PIN_A12 (D6)
	[13] = &(lt_arduino_pin_info_list[2]),  // PIN_A13 (D2)
	[14] = &(lt_arduino_pin_info_list[4]),  // PIN_A14 (D4)
	[15] = &(lt_arduino_pin_info_list[9]),  // PIN_A15 (D9)
	[16] = &(lt_arduino_pin_info_list[8]),  // PIN_A16 (D8)
	[17] = &(lt_arduino_pin_info_list[3]),  // PIN_A17 (D3)
	[18] = &(lt_arduino_pin_info_list[1]),  // PIN_A18 (D1)
	[19] = &(lt_arduino_pin_info_list[0]),  // PIN_A19 (D0)
	[20] = &(lt_arduino_pin_info_list[5]),  // PIN_A20 (D5)
};
// clang-format on
