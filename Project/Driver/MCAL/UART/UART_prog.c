/*
 * UART_prog.c
 *
 *  Created on: Jul 14, 2023
 *      Author: 00214
 */
#include "../../LIB/errorStates.h"
#include "../../LIB/stdTypes.h"

#include "UART_priv.h"
#include "UART_config.h"

ES_t UART_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if SPEED_MODE == NORMAL
	UCSRA &=~(1<<1);
#endif
#if UART_MODE == TRANSCIEVER
	UCSRB |=(3<<3);  // bit 3,4
#endif

	u8 Local_u8UCSRC = 0;  //bit access

#if DATA_LEN == EIGHT
	Local_u8UCSRC |=(3<<1);  // bit 3,4
#endif

#if PARITY_STATE == NO_PARITY
	Local_u8UCSRC &= ~(3<<4);
#endif

#if STOP_STATE == ONE_STOP_BIT
	Local_u8UCSRC &=~(1<<3);
#endif
#if CLOCK_MODE == ASYCH
	Local_u8UCSRC &=~(1<<6);
#endif
	Local_u8UCSRC |=(1<<7); // register select
	UCSRC = Local_u8UCSRC;

	u16 Local_u16UBRR = (u16)BUAD(BUAD_RATE);
	Local_u16UBRR &=~(1<<15);

	UBRRL  = (u8)Local_u16UBRR;
	UBRRH  = (Local_u16UBRR>>8);


		return Local_enuErrorState;
}
ES_t UART_enuSendChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	while(!((UCSRA>>UDRE)&1));
	UDR = Copy_u8Data;

	return Local_enuErrorState;
}

ES_t UART_enuRecieveChar(u8 * Copy_puData)
{
	ES_t Local_enuErrorState = ES_NOK;
	while(!((UCSRA>>RXC)&1));
	if (Copy_puData!= NULL )
		*Copy_puData=UDR;

	return Local_enuErrorState;
}

ES_t UART_enuSendString(const char * Copy_pcData)
{
	ES_t Local_enuErrorState = ES_NOK;
	while (*Copy_pcData !='\0')
	{
		while(!((UCSRA>>UDRE)&1));
			UDR = *Copy_pcData;
			Copy_pcData++;
	}

	return Local_enuErrorState;
}
/*  \r = 13   \n */
ES_t UART_enuRecieveString(char * Copy_pcData)
{
	ES_t Local_enuErrorState = ES_NOK;

	u8 Local_u8Data = 0 , Local_u8Index = 0;
	while(!((UCSRA>>RXC)&1));
		u8 Local_u8Exit = UDR;
	while(1)
	{
		while(!((UCSRA>>RXC)&1));
		Local_u8Data = UDR;
// if((Local_u8Data == Local_u8Exit)
		if(Local_u8Data == Local_u8Exit)
		{
			Copy_pcData[Local_u8Index]='\0';
			break;
		}
		Copy_pcData[Local_u8Index]=Local_u8Data;
		Local_u8Index++;
	}

	return Local_enuErrorState;
}








