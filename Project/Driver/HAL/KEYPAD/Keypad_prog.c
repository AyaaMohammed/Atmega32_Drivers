/*
 * Keypad_prog.c
 *
 *  Created on: Feb 22, 2023
 *      Author: 00214
 */
#include  "../../LIB/stdTypes.h"
#include  "../../LIB/errorStates.h"

#include  "../../MCAL/DIO/DIO_int.h"

#include  "Keypad_config.h"
#include  "Keypad_priv.h"

#include  "util/delay.h"
ES_t Keypad_enuInit(void)
{
	ES_t Local_enuErrorState  = ES_NOK;

	DIO_enuSetPinDirection(C1_PORT,DIO_u8OUTPUT,C1_PIN);
	DIO_enuSetPinDirection(C2_PORT,DIO_u8OUTPUT,C2_PIN)	;
	DIO_enuSetPinDirection(C3_PORT,DIO_u8OUTPUT,C3_PIN);
	DIO_enuSetPinDirection(C4_PORT,DIO_u8OUTPUT,C4_PIN);

	DIO_enuSetPinDirection(R1_PORT,DIO_u8INPUT,R1_PIN);
	DIO_enuSetPinDirection(R2_PORT,DIO_u8INPUT,R2_PIN);
	DIO_enuSetPinDirection(R3_PORT,DIO_u8INPUT,R3_PIN );
	DIO_enuSetPinDirection(R4_PORT,DIO_u8INPUT,R4_PIN);

	DIO_enuSetPinValue(C1_PORT,C1_PIN,DIO_u8HIGH);
	DIO_enuSetPinValue(C2_PORT,C2_PIN,DIO_u8HIGH);
	DIO_enuSetPinValue(C3_PORT,C3_PIN,DIO_u8HIGH);
	DIO_enuSetPinValue(C4_PORT,C4_PIN,DIO_u8HIGH);

	DIO_enuSetPinValue(R1_PORT,R1_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(R2_PORT,R2_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(R3_PORT,R3_PIN, DIO_u8PULL_UP);
	DIO_enuSetPinValue(R4_PORT,R4_PIN, DIO_u8PULL_UP);


	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue)
{
	ES_t Local_enuErrorState =ES_NOK;

	if (Copy_pu8KeyValue != NULL)
	{
		u8 Local_Au8RowPins [ROWS_NUM] = { R1_PIN , R2_PIN , R3_PIN , R4_PIN };
		u8 Local_Au8ColPins [COLS_NUM] = { C1_PIN , C2_PIN , C3_PIN , C4_PIN };
		u8 Local_Au8RowPorts[ROWS_NUM] = { R1_PORT , R2_PORT , R3_PORT , R4_PORT };
		u8 Local_Au8ColPorts[COLS_NUM] = { C1_PORT , C2_PORT , C3_PORT , C4_PORT };

		*Copy_pu8KeyValue = KEYPAD_NOT_PRESSSED;

		u8 Local_Au8KeyValues[ROWS_NUM][COLS_NUM] = KEYS_VALUES;

		u8 Local_u8PinValue = 0xff;

		u8 Local_u8RowIter , Local_u8ColIter;

		for (Local_u8ColIter =0; Local_u8ColIter < COLS_NUM ; Local_u8ColIter ++)
		{
			DIO_enuSetPinValue(Local_Au8ColPorts[Local_u8ColIter] , Local_Au8ColPins[Local_u8ColIter] , DIO_u8LOW);

			for (Local_u8RowIter =0 ; Local_u8RowIter <ROWS_NUM ; Local_u8RowIter ++)
			{
				DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], &Local_u8PinValue ,Local_Au8RowPins[Local_u8RowIter]);
				if (! Local_u8PinValue)
				{
					_delay_ms(10);
					DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], &Local_u8PinValue ,Local_Au8RowPins[Local_u8RowIter]);
					if (! Local_u8PinValue)
					{
						while (! Local_u8PinValue)
						{
							DIO_enuGetPinValue(Local_Au8RowPorts[Local_u8RowIter], &Local_u8PinValue, Local_Au8RowPins[Local_u8RowIter]);
						}

						*Copy_pu8KeyValue = Local_Au8KeyValues[Local_u8RowIter][Local_u8ColIter];

						return Local_enuErrorState=ES_OK;
					}
				}
			}

			DIO_enuSetPinValue(Local_Au8ColPorts[Local_u8ColIter] , Local_Au8ColPins[Local_u8ColIter] , DIO_u8HIGH);
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
