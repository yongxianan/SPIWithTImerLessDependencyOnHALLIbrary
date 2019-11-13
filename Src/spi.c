/*
 * spi.c
 *
 *  Created on: Nov 6, 2019
 *      Author: User
 */
#include "spi.h"

void spiConfig(SPIx *SPI,uint32_t CR){
	SPI->CR1 |= (uint32_t)(CR & 0xffff);
	SPI->CR2 |= (uint32_t)((CR >>16 )& 0xffff);
}

void spiEnable(SPIx *SPI){
	SPI->CR1 |= SPI_ENABLE;
}

void sendData(SPIx *SPI,uint8_t data){
	while(!(SPI->SR & TX_EMPTY));
	SPI->DR = (uint32_t)(data & 0xff);
}

uint8_t receiveData(SPIx *SPI){
	while(!(SPI->SR & RXNE_NOT_EMPTY));
	return (SPI->DR & 0xff);
}
