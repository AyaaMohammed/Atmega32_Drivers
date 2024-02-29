/*
 * SPI_Priv.h
 *
 *  Created on: Aug 31, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_SPI_SPI_PRIV_H_
#define DRIVER_MCAL_SPI_SPI_PRIV_H_

#define SPDR	*((volatile u8*) 0x2f)
#define SPSR	*((volatile u8*) 0x2e)
#define SPCR	*((volatile u8*) 0x2d)


// SPCR
#define SPIE	7
#define SPE		6
#define DORD	5  // zer0
#define MSTR	4
#define CPOL    3
#define CPHA	2
#define SPR1	1
#define SPR0    0


//SPSR
#define SPIF    7
#define WCOL    6
#define SPI2X   0

//SPDR
#define MSB    7
#define LSB    0



#endif /* DRIVER_MCAL_SPI_SPI_PRIV_H_ */
