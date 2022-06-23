/* Copyright (c) Kuba Szczodrzyński 2022-06-23. */

#include "SerialClass.h"

extern "C" {
#include <uart_pub.h>

extern void bk_send_byte(uint8_t uport, uint8_t data);
extern void uart_hw_set_change(uint8_t uport, bk_uart_config_t *uart_config);
extern int uart_rx_callback_set(int uport, uart_callback callback, void *param);
}

#ifdef PIN_SERIAL1_RX
SerialClass Serial1(UART1_PORT);
#endif
#ifdef PIN_SERIAL2_RX
SerialClass Serial2(UART2_PORT);
#endif

SerialClass::SerialClass(uint8_t port) {
	this->port = port;
	this->buf  = NULL;
}

static void callback(int port, void *param) {
	RingBuffer *buf = (RingBuffer *)param;
	buf->store_char(uart_read_byte(port));
}

void SerialClass::begin(unsigned long baudrate, uint16_t config) {
	uint8_t dataWidth = ((config & SERIAL_DATA_MASK) >> 8) - 1;				  // 0x100..0x400 -> 0..3
	uint8_t parity	  = 3 - (config & SERIAL_PARITY_MASK);					  // 0x3..0x1 -> 0..2
	uint8_t stopBits  = (config & SERIAL_STOP_BIT_MASK) == SERIAL_STOP_BIT_2; // 0x10..0x30 -> 0..1

	bk_uart_config_t cfg = {
		.baud_rate	  = baudrate,
		.data_width	  = (uart_data_width_t)dataWidth,
		.parity		  = (uart_parity_t)parity,
		.stop_bits	  = (uart_stop_bits_t)stopBits,
		.flow_control = FLOW_CTRL_DISABLED,
	};
	if (this->buf) {
		this->buf->clear();
	} else {
		this->buf = new RingBuffer();
	}
	uart_hw_set_change(port, &cfg);
	uart_rx_callback_set(port, callback, this->buf);
}

void SerialClass::end() {
	uart_rx_callback_set(port, NULL, NULL);
	delete this->buf;
}

int SerialClass::available() {
	return buf->available();
}

int SerialClass::peek() {
	return buf->peek();
}

int SerialClass::read() {
	return buf->read_char();
}

void SerialClass::flush() {
	uart_wait_tx_over();
}

size_t SerialClass::write(uint8_t c) {
	bk_send_byte(port, c);
	return 1;
}
