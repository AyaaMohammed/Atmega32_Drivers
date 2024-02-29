/*
 * I2C_Prog.c
 *
 *  Created on: Sep 4, 2023
 *      Author: 00214
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include "I2C_Priv.h"
#include "I2C_Config.h"

ES_t IIC_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if IIC_MODE == I2C_MASTER
	// bitrate
	TWBR = (u8)BITRATE(IIC_CLOCK_SPEED);
	#if IIC_PRES  == 1ul
		TWSR &=~(3<<0);
	#endif
		// Address
	TWAR &=~(1<<0);
	TWAR = (IIC_NODE_ADDRESS<<1) | IIC_RECOG_GENERAL_CALL;

	// clear flag && enable IIC
	TWCR |=(1<<7);
	TWCR |=(1<<2);
	Local_enuErrorState = ES_OK;
#elif 	IIC_MODE == I2C_SLAVE
		// Address
	TWAR &=~(1<<0);
	TWAR = (IIC_NODE_ADDRESS<<1) | IIC_RECOG_GENERAL_CALL;

	// clear flag && enable IIC
	TWCR |=(1<<7);
	TWCR |=(1<<2);
	Local_enuErrorState = ES_OK;
#endif

	return Local_enuErrorState;
}

ES_t IIC_enuStartCondition(void)
{
	ES_t Local_enuErrorState = ES_NOK;
		TWCR |=(1<<5);
		// clear flag
		TWCR |=(1<<7);
		while(!((TWCR>>7)&1));

		if((TWSR & 0xF8)== 0x08)
			Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t IIC_enuRepeatedStartCondition(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	TWCR |=(1<<5);
	// clear flag
	TWCR |=(1<<7);
	while(!((TWCR>>7)&1));

	if((TWSR & 0xF8)== 0x10)
		Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t IIC_enuStopCondition(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	// clear flag
	TWCR |=(1<<7);
	TWCR |=(1<<4);
	return Local_enuErrorState;
}

ES_t IIC_enuWriteSlaveAddress(u8  Copy_u8SlaveAddress,u8 Copy_u8Operation)
{
	ES_t Local_enuErrorState = ES_NOK;
	TWDR = ((Copy_u8SlaveAddress<<1) | Copy_u8Operation);
	//clear start condition
	TWCR &=~(1<<5);
	// clear flag
	TWCR |=(1<<7);
	while(!((TWCR>>7)&1));


	if((TWSR& 0xF8) == 0x18 && Copy_u8Operation == 0)
	{
		Local_enuErrorState = ES_OK;
	}
	else if((TWSR& 0xF8) == 0x40 && Copy_u8Operation == 1)
	{
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}

ES_t IIC_enuWriteData(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	TWDR = Copy_u8Data;
	// clear flag
	TWCR |=(1<<7);
	while(!((TWCR>>7)&1));

	if((TWSR & 0xF8)== 0x28)
		Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t IIC_enuCheckMyAddress(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	// slave , enable acknowledge
	TWCR |= (1<<6);

	// clear flag
	TWCR |=(1<<7);
	while(!((TWCR>>7)&1));

	if((TWSR& 0xF8) == 0x60 )
	{
		Local_enuErrorState = ES_OK;
	}
	else if((TWSR& 0xF8) == 0xA8 )
	{
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}

ES_t IIC_enuReadData(u8 * Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	// clear flag
	TWCR |=(1<<7);
	while(!((TWCR>>7)&1));

	if((TWSR & 0xF8)== 0x58) //  master receive
	{
		*Copy_u8Data = TWDR;
		Local_enuErrorState = ES_OK;
	}
	else if((TWSR & 0xF8)== 0x80)
	{
		*Copy_u8Data = TWDR;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}











