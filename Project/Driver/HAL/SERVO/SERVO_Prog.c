/*
 * SERVO_Prog.c
 *
 *  Created on: Sep 6, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "../../MCAL/TIMER1/TIMER1_Int.h"

#include "SERVO_Priv.h"
#include "SERVO_Config.h"

ES_t SERVO_enuInitTimer1(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	Timer1_enuInit();

	//u16 Local_u8PeriodTime = (1/FREQUENCY)*1000;

	//Timer1_enuSetICR1Value((Local_u8PeriodTime*1000)-1);
	Timer1_enuSetICR1Value(19999);
	u16 Local_u8Angle0 =  999;
	Timer1_enuSetOCR1AValue(Local_u8Angle0);


	return Local_enuErrorState;
}

ES_t SERVO_ENUSetAngle(u8 Copy_u8Angle)
{
	ES_t Local_enuErrorState = ES_NOK;
	u16 Local_u8OCR1A =((Copy_u8Angle*1000UL)/180)+999;
	Timer1_enuSetOCR1AValue(Local_u8OCR1A);
	return Local_enuErrorState;
}
