#pragma once

#include "mbed.os"

class NetzerEcoder{

	public:
		NetzerEncoder(int frequency = 500000);
		void spi_callback_debug(const int events);
		void spi_read();
	

	private:
		const int WORDS = 2;											// 2, 8 bit words
		const uint8_t tx_buffer[WORDS] = {0};			// Initialize dummy tx
		uint8_t rx_buffer[WORDS];									// Initialize rx buffer to receive data (16 bits in total)
		int freq;																	// SPI read frequency
		SPI spi(SPI_MOSI, SPI_MISO, SPI_SCK);			// most, miso, sclk (PA_7, PA_6, PA_5)
}


