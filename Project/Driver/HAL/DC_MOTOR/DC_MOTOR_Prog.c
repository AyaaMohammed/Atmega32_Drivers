/*
 * DC_MOTOR_Prog.c
 *
 *  Created on: Aug 25, 2023
 *      Author: 00214
 */
#include "../../LIB/errorStates.h"
#include "../../LIB/stdTypes.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "DC_MOTOR_Config.h"
#include "DC_MOTOR_Priv.h"

ES_t DC_MOTOR_enuInit(void)
{
	ES_t Local_enuErrorState = ES_OK;
	/*    SET  DIRECTION  */
	DIO_enuSetPinDirection(MOTOR_PIN1_PORT,DIO_u8OUTPUT,MOTOR_PIN1_PIN);
	DIO_enuSetPinDirection(MOTOR_PIN2_PORT,DIO_u8OUTPUT,MOTOR_PIN2_PIN);
	/*     Direction      */
	if(MOTOR_STATES == ON)
	{
		if(MOTOR_DIRECTION == CLOCK_WISE)
		{
			DIO_enuSetPinValue(MOTOR_PIN1_PORT,MOTOR_PIN1_PIN,DIO_u8HIGH);
			DIO_enuSetPinValue(MOTOR_PIN2_PORT,MOTOR_PIN2_PIN,DIO_u8LOW);
		}
		else if (MOTOR_DIRECTION == COUNTER_CLOCK_WISE)
		{
			DIO_enuSetPinValue(MOTOR_PIN1_PORT,MOTOR_PIN1_PIN,DIO_u8LOW);
			DIO_enuSetPinValue(MOTOR_PIN2_PORT,MOTOR_PIN2_PIN,DIO_u8HIGH);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		DIO_enuSetPinValue(MOTOR_PIN1_PORT,MOTOR_PIN1_PIN,DIO_u8LOW);
		DIO_enuSetPinValue(MOTOR_PIN2_PORT,MOTOR_PIN2_PIN,DIO_u8LOW);
	}
	return Local_enuErrorState;
}

ES_t DC_MOTOR_enuDirection(u8 Copy_u8Direction , u8 Copy_u8States)
{
	ES_t Local_enuErrorState = ES_OK;
	if(Copy_u8States == ON)
	{
		if(Copy_u8Direction == CLOCK_WISE)
		{
			DIO_enuSetPinValue(MOTOR_PIN1_PORT,MOTOR_PIN1_PIN,DIO_u8HIGH);
			DIO_enuSetPinValue(MOTOR_PIN2_PORT,MOTOR_PIN2_PIN,DIO_u8LOW);
		}
		else if (Copy_u8Direction == COUNTER_CLOCK_WISE)
		{
			DIO_enuSetPinValue(MOTOR_PIN1_PORT,MOTOR_PIN1_PIN,DIO_u8LOW);
			DIO_enuSetPinValue(MOTOR_PIN2_PORT,MOTOR_PIN2_PIN,DIO_u8HIGH);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		DIO_enuSetPinValue(MOTOR_PIN1_PORT,MOTOR_PIN1_PIN,DIO_u8LOW);
		DIO_enuSetPinValue(MOTOR_PIN2_PORT,MOTOR_PIN2_PIN,DIO_u8LOW);
	}

	return Local_enuErrorState;
}

ES_t DC_MOTOR_enuStop()
{
	ES_t Local_enuErrorState = ES_OK;
	DIO_enuSetPinValue(MOTOR_PIN1_PORT,MOTOR_PIN1_PIN,DIO_u8LOW);
	DIO_enuSetPinValue(MOTOR_PIN2_PORT,MOTOR_PIN2_PIN,DIO_u8LOW);

	return Local_enuErrorState;
}
