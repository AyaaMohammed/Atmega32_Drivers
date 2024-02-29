/*
 * SPI_Prog.c

 *
 *  Created on: Aug 31, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "SPI_Priv.h"
#include "SPI_Config.h"



/* Set MOSI and SCK output, all others input */
//DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);


ES_t SPI_enuMasterInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR =(1<<SPE) | (1<<MSTR) |(1<<SPR1)|(1<<SPR0);
	SPCR &=~(1<<DORD); // LSB
	SPCR &=~(1<<CPOL); //Leading edge Rising
	SPCR &=~(1<<CPHA); // Leading edge  Sample
	return Local_enuErrorState;
}

ES_t SPI_enuMasterTransmit(char Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	SPDR = Copy_u8Data;
	/* Wait for transmission complete */
	while(!((SPSR>>SPIE)&1));
	return Local_enuErrorState;

}



ES_t SPI_enuSlaveInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	SPCR &=~(1<<MSTR);
	SPCR |= (1<<SPE);

	SPCR &=~(1<<DORD); // LSB
	SPCR &=~(1<<CPOL); //Leading edge Rising
	SPCR &=~(1<<CPHA); // Leading edge  Sample
	return Local_enuErrorState;
}

ES_t SPI_enuSlaveReceive(char * Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	/* Wait for reception complete */
	while(!((SPSR>>SPIE)&1));
	/*  data register */
	*Copy_u8Data= SPDR;
	return Local_enuErrorState;
}
/*ES_t SPI_u8Tranceive(u8 * Copy_u8Data , u8 Copy_u8TData)
{
	ES_t Local_enuErrorState = ES_NOK;
	SPDR = Copy_u8TData;
	 Wait for transmission complete
	while(!(SPSR & (1<<SPIF)));

	*Copy_u8Data =SPDR;
	return Local_enuErrorState;
}*/
