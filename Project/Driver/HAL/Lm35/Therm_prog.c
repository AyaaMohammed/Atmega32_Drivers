/*
 * Therm_prog.c
 *
 *  Created on: May 6, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"
#include  "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_config.h"
#include "../../MCAL/ADC/ADC_int.h"

#include "../LCD/LCD_int.h"
#include "Therm_priv.h"
#include "Therm_config.h"
#include <util/delay.h>
//extern THERM_t THERM_AstrThermistorConfig[NUM_LM];
ES_t THERMISTOR_enuInit(THERM_t*THERM_AstrThermistorConfig)
{
	ADC_enuInit();
	ADC_enuSelectChannel(ADC_INPUT);
	ADC_enuEnableInterruptMode();
	ADC_enuEnableTriggeringMode(ADC_EXIT0_INT);

	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8Iterator = 0;
	if(THERM_AstrThermistorConfig != NULL)
	{
		for(Local_u8Iterator=0;Local_u8Iterator<NUM_LM ; Local_u8Iterator++)
		{
			if(THERM_AstrThermistorConfig[Local_u8Iterator].THERM_u8PostivePinChannel != NOT_CONNECTED)
			{
				DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8INPUT,THERM_AstrThermistorConfig[Local_u8Iterator].THERM_u8PostivePinChannel);
			}
			if(THERM_AstrThermistorConfig[Local_u8Iterator].THERM_u8PostivePinChannel == NOT_CONNECTED)
			{
				return Local_enuErrorState;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
		return Local_enuErrorState;
	}
void read(void*p);
void read(void*p)
{
	ADC_enuRead((u16*)p);

}

ES_t THERMISTOR_enuGetTemprtature(THERM_t*THERM_AstrThermistorConfig, u32 * Copy_pu8Temp)
{
		ES_t Local_enuErrorState = ES_NOK;
		if(THERM_AstrThermistorConfig != NULL)
		{
			u16 * Local_pu8Value = NULL;
			ADC_enuCallBack(read,&Local_pu8Value);
			ADC_enuStartConversion();
			_delay_ms(5);
			*Copy_pu8Temp = (((((u32)Local_pu8Value)*0.0048828)/0.01));
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
		return Local_enuErrorState;
}


