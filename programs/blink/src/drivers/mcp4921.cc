/*
dac_mcp4921.c
Driver for 12-bit single channel SPI DAC

Copyright (c) 2015 4ms Company

Author: Dan Green - danngreen1@gmail.com

LICENSE:

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

See http://creativecommons.org/licenses/MIT/ for more information.
*/
#include <avr/io.h>
#include <drivers/mcp4921.h>

namespace lst {

void init_spi(void){
	SPI_DDR |= (1<<SPI_MOSI) | (1<<SPI_SCLK); //SCK, MOSI are output
	DAC_CS_DDR |= (1<<DAC_CS) | (1<<DAC_CS2) | (1<<DAC_CS3); //CS for MCP4922 DAC
	DAC_CS_PORT |= (1<<DAC_CS) | (1<<DAC_CS2) | (1<<DAC_CS3); //pull CS high to intialize	
	
	SPI_DDR &= ~(1<<SPI_MISO); // MISO is input
				
	SPCR = (1<<SPE) | (1<<MSTR) | (0<<SPR1)| (0<<SPR0); //SPI enable, Master Mode, F_OSC/4, interrupt enabled
	SPSR = (1<<SPI2X); //SPI double speed = 2MHz

	output_dac(0, DAC_CS, 0);
	output_dac(0, DAC_CS2, 0);
	output_dac(0, DAC_CS3, 0);
}

void output_dac(uint8_t channel, uint8_t id, uint16_t data){
	DAC_CS_PORT &= ~(1<<id);	//pull CS low to enable DAC

//using a 4921, we only have one channel, so set _ABSEL=0
//with a 4922 our function is output_dac(char channel, uint16_t data){
//...and then do SPDR = (channel<<MCP4921_ABSEL)....
	SPDR = (channel<<MCP4921_ABSEL) | (1<<MCP4921_BUF) | (1<<MCP4921_GAIN) | (1<<MCP4921_SHDN) | ((data>>8) & 0x0F);
	while (!(SPSR & (1<<SPIF)))
		;
	SPDR = data & 0x00FF;
	while (!(SPSR & (1<<SPIF)))
		;
	DAC_CS_PORT |= (1<<id);		//pull CS high to latch data

}

}

