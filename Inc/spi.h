/*
 * spi.h
 *
 *  Created on: Nov 6, 2019
 *      Author: User
 */

#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

typedef struct SPIx SPIx;
struct SPIx{
	volatile	uint32_t	CR1;		//0x00
	volatile	uint32_t	CR2;		//0x04
	volatile	uint32_t	SR;			//0x08
	volatile	uint32_t	DR;			//0x0C
	volatile	uint32_t	CRCPR;		//0x10
	volatile	uint32_t	RXCRCR;		//0x14
	volatile	uint32_t	TXCRCR;		//0x18
	volatile	uint32_t	I2SCFGR;	//0x1C
	volatile	uint32_t	I2SPR;		//0x20
};
/*
 * APB2:
 * SPI6
 * SPI5
 * SPI4
 * SPI1
 */
#define SPI6	((SPIx *)(0x40015400))
#define SPI5	((SPIx *)(0x40015000))
#define SPI4	((SPIx *)(0x40013400))
#define SPI1	((SPIx *)(0x40013000))

/*
 * APB1:
 * SPI3 / I2S3
 * SPI2 / I2S2
 */
#define SPI3	((SPI *)(0x40003C00))
#define SPI2	((SPI *)(0x40003800))

void spiConfig(SPIx *SPI,uint32_t CR);
void sendData(SPIx *SPI,uint8_t data);
uint8_t receiveData(SPIx *SPI);

/*
 * SPI_CR1
 * (not used in I2S mode)
 */
#define	UNIDIRECT_DATA_MODE_TWO_LINE	(0<<15)
#define	BIDIRECT_DATA_MODE_ONE_LINE		(1<<15)
#define	OUT_DISABLE_BIDIOE				(0<<14)//receive only mode
#define	OUT_ENABLE_BIDIOE				(1<<14)//transmit only mode
#define	DATA_FRAME_8_BIT				(0<<11)
#define	DATA_FRAME_16_BIT				(1<<11)
#define	FULL_DUPLEX						(0<<10)
#define	OUT_DISABLE						(1<<10)
#define	SPI_MSB_FIRST					(0<<7)
#define	SPI_LSB_FIRST					(1<<7)
#define	SPI_DISABLE						(0<<6)
#define	SPI_ENABLE						(1<<6)

#define	F_PCLK_DIV_2					(0<<3)
#define	F_PCLK_DIV_4					(1<<3)
#define	F_PCLK_DIV_8					(2<<3)
#define	F_PCLK_DIV_16					(3<<3)
#define	F_PCLK_DIV_32					(4<<3)
#define	F_PCLK_DIV_64					(5<<3)
#define	F_PCLK_DIV_128					(6<<3)
#define	F_PCLK_DIV_256					(7<<3)

#define	MSTR_SLAVE_CONFIG				(0<<2)
#define	MSTR_MASTER_CONFIG				(1<<2)
#define	CPOL_CK0_WHEN_IDLE				(0<<1)
#define	CPOL_CK1_WHEN_IDLE				(1<<1)
#define	CPHA_FIRST						(0<<0)
#define	CPHA_SECOND						(1<<0)

/*
 * SPI_CR2
 */
#define	TXEIE_MASK						(0<<(7+16))
#define	TXEIE_NOT_MASK					(1<<(7+16))
#define	RXNEIE_MASK						(0<<(6+16))
#define	RXNEIE_NOT_MASK					(1<<(6+16))
#define	ERRIE_MASK						(0<<(5+16))
#define	ERRIE_ENABLE					(1<<(5+16))
#define	FRF_SPI_MOTOROLA				(0<<(4+16))
#define	FRF_SPI_TI						(1<<(4+16))
#define	SSOE_0							(0<<(2+16))
#define	SSOE_1							(1<<(2+16))

/*
 * SPI_SR
 */
#define	NO_FRE_OCCUR					(0<<8)
#define	FRE_OCCUR						(1<<8)
#define	SPI_NOT_BUSY					(0<<7)
#define	SPI_BUSY_TX_NOT_EMPTY			(1<<7)
#define	NO_OVERRUN_OCCUR				(0<<6)
#define	OVERRUN_OCCUR					(1<<6)
#define NO_MODE_FAULT_OCCUR				(0<<5)
#define MODE_FAULT_OCCUR				(1<<5)

#define	TX_NOT_EMPTY					(0<<1)
#define	TX_EMPTY						(1<<1)
#define	RXNE_EMPTY						(0<<0)
#define	RXNE_NOT_EMPTY					(1<<0)

/*
 * SPI_I2SCFGR
 */
#define	SPI_SELECTED					(0<<11)
#define	I2C_SELECTED					(1<<11)



#endif /* SPI_H_ */
