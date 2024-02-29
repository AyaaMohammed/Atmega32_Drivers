/*
 * TIMER1_Prog.c
 *
 *  Created on: Sep 6, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "TIMER1_Priv.h"
#include "TIMER1_Config.h"

static void (*Timer_ptrFunc[4])(void) = {0};

ES_t Timer1_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if TIMER1_MODE == TIMER1_FAST_PWM_TOP_ICR1
	TCCR1A &=~(1<<WGM10);
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12);
	TCCR1B |= (1<<WGM13);
#endif

#if TIMER1_PRES == TIMER1_PRE_8
	TCCR1B &=~(1<<CS10);
	TCCR1B |= (1<<CS11);
	TCCR1B &=~(1<<CS12);
#endif

#if TIMER1_OC0_PIN_STATE_CHA == TIMER1_FAST_PWM_CLEAR_CTC_SET_TOP_CHA
	TCCR1A &=~(1<<COM1A0);
	TCCR1A |=(1<<COM1A1);
#endif

#if TIMER1_OC0_PIN_STATE_CHB == TIMER1_DISCONNECTED_CTC_OC0_CHB
	TCCR1A &=~(1<<COM1B0);
	TCCR1A &=~(1<<COM1B1);
#endif
	return Local_enuErrorState;
}
ES_t Timer1_enuSetPreloadValue(u16 Copy_u16Value)
{
	ES_t Local_enuErrorState = ES_NOK;
	TCNT1 = Copy_u16Value;

	return Local_enuErrorState;
}
ES_t Timer1_enuReadValue(u16 * Copy_u16PValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	 *Copy_u16PValue = TCNT1;

	return Local_enuErrorState;
}
ES_t Timer1_enuICUSetTriggerEdge(u8 Copy_u8Edge)
{
	ES_t Local_enuErrorState = ES_NOK;
#if Copy_u8Edge == FALLING_EDGE
	TCCR1B &=~(1<<ICES1);
#elif Copy_u8Edge == RISING_EDGE
	TCCR1B |= (1<<ICES1);
#endif
	return Local_enuErrorState;
}
ES_t  Timer1_u16ReadICR1Value(u16 * Copy_u16PValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	return ICR1;

	return Local_enuErrorState;
}
ES_t Timer1_enuSetOCR1AValue(u16 Copy_u16Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	OCR1A = Copy_u16Value;
	return Local_enuErrorState;
}
ES_t Timer1_enuSetOCR1BValue(u16 Copy_u16Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	OCR1B = Copy_u16Value;
	return Local_enuErrorState;
}
ES_t Timer1_enuSetICR1Value(u16 Copy_u16Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	ICR1 = Copy_u16Value;
	return Local_enuErrorState;
}

ES_t Timer1_enuOVFInterruptEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK |=(1<<TOIE1);

	return Local_enuErrorState;
}
ES_t Timer1_enuOVFInterruptDisable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK &=~(1<<TOIE1);

	return Local_enuErrorState;
}
ES_t Timer1_enuOC1AInterruptEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK |=(1<<OCIE1A);

	return Local_enuErrorState;
}
ES_t Timer1_enuOC1AInterruptDisable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK &=~(1<<OCIE1A);

	return Local_enuErrorState;
}

ES_t Timer1_enuOC1BInterruptEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK |=(1<<OCIE1B);

	return Local_enuErrorState;
}
ES_t Timer1_enuOC1BInterruptDisable(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	TIMSK &=~(1<<OCIE1B	);
	return Local_enuErrorState;
}
ES_t Timer1_enuICUInterruptEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK |=(1<<TICIE1);

	return Local_enuErrorState;
}
ES_t Timer1_enuICUInterruptDisable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	TIMSK &=~(1<<TICIE1	);

	return Local_enuErrorState;
}

ES_t Timer1_enuOVFSetCallBack(void (*Copy_pfNotification)(void))
{
	ES_t Local_enuErrorState = ES_NOK;
	Timer_ptrFunc[0] = Copy_pfNotification;

	return Local_enuErrorState;
}
ES_t Timer1_enuOC1ASetCallBack(void (*Copy_pfNotification)(void))
{
	ES_t Local_enuErrorState = ES_NOK;
	Timer_ptrFunc[1] = Copy_pfNotification;

	return Local_enuErrorState;
}
ES_t Timer1_enuOC1BSetCallBack(void (*Copy_pfNotification)(void))
{
	ES_t Local_enuErrorState = ES_NOK;
	Timer_ptrFunc[2] = Copy_pfNotification;

	return Local_enuErrorState;
}
ES_t Timer1_enuICUSetCallBack(void (*Copy_pfNotification)(void))
{
	ES_t Local_enuErrorState = ES_NOK;
	Timer_ptrFunc[3] = Copy_pfNotification;

	return Local_enuErrorState;
}


ISR(VECT_TIMER1_OVF)
{
    if(Timer_ptrFunc[0] != NULL)
    {
    	Timer_ptrFunc[0]();
    }
}

ISR(VECT_TIMER1_COMPA)
{
    if(Timer_ptrFunc[0] != NULL)
    {
    	Timer_ptrFunc[0]();
    }
}

ISR(VECT_TIMER1_COMPB)
{
    if(Timer_ptrFunc[0] != NULL)
    {
    	Timer_ptrFunc[0]();
    }
}

ISR(VECT_TIMER1_CAPT)
{
    if(Timer_ptrFunc[0] != NULL)
    {
    	Timer_ptrFunc[0]();
    }
}
