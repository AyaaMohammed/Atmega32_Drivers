/*
 * LDR_Prog.c
 *
 *  Created on: Sep 14, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "../../MCAL/ADC/ADC_config.h"
#include "../../MCAL/ADC/ADC_int.h"

#include "LDR_Config.h"
#include "LDR_Int.h"
#include <util/delay.h>
ES_t LDR_enuinit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8INPUT,DIO_u8PIN1);
	ADC_enuSelectChannel(LDR_Channel);
	ADC_enuDisableTriggeringMode();
	return Local_enuErrorState;
}

ES_t LDR_enuGetValue(u16 * Copy_u16Value )
{
	u16  Local_pu8Value;
	ES_t Local_enuErrorState = ES_NOK;

	ADC_enuStartConversion();
	ADC_enuPollingSystem();
	ADC_enuRead(&Local_pu8Value);
	LCD_enuDisplayIntegerNum(Local_pu8Value);
	//*Copy_u16Value = (((((u16)Local_pu8Value)*0.0048828)/0.01));
	*Copy_u16Value = 0;
	return Local_enuErrorState;
}
