/*
 * TIMER_prog.c
 *
 *  Created on: May 13, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "TIMER_priv.h"
#include "TIMER_config.h"

static u32 Num_OVF =0;
static u32 Preload =0;

static void (*gptr)(void*)=NULL;
static void * gpara = NULL;


ES_t TIMER_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
#if  TIMER_PRES  == 1024
	TCCR0 &= 0xf8;
	TCCR0 |= 5;
#endif

#if TIMER_MODE == OVF
	TCCR0 &=~(1<<3);
	TCCR0 &=~(1<<6);

#endif

#if OC_MODE == DISCONNED
	TCCR0 &=~(1<<4);
	TCCR0 &=~(1<<5);
#endif
	return Local_enuErrorState;
}
ES_t TIMER_enuSetPreload(u8 Copy_u8Preload)
{
	ES_t Local_enuErrorState = ES_NOK;
		TCNT0 = Copy_u8Preload;
	return Local_enuErrorState;
}
//ms
ES_t TIMER_enuSetAsychDelay(u32 Copy_u8Time,void(*Copy_pfunApp)(void*),void*Parameter )
{
	ES_t Local_enuErrorState = ES_NOK;
	f32 ovfTime = 256 * ((f32)TIMER_PRES/TIMER_F_CPU);

	f32 NumOVF  = (Copy_u8Time)/(ovfTime);

	if((NumOVF-(u32)NumOVF) !=0.0)
	{
		u32 NumOVF_int =(u32)NumOVF +1;
		NumOVF = NumOVF -(u32)NumOVF;
		u8 preload = 256 - (NumOVF * 256);

		Num_OVF = NumOVF_int;
		Preload = preload;
		TCNT0 = preload;
	}
	else
	{
		Num_OVF = (u32)NumOVF;
	}
	if (Copy_pfunApp != NULL)
	{
		gptr = Copy_pfunApp;
		gpara = Parameter;
	}
	TIMSK |=(1<<0);
	return Local_enuErrorState;
}

ES_t TIMER_enuSetSychDelay(u32 Copy_u8Time)
{

	ES_t Local_enuErrorState = ES_NOK;
	TIMSK &=~(1<<0);
	f32 ovfTime = 256 * ((f32)TIMER_PRES/TIMER_F_CPU);

	f32 NumOVF  = (Copy_u8Time)/(ovfTime);

	if((NumOVF-(u32)NumOVF) !=0.0)
	{
		u32 NumOVF_int =(u32)NumOVF +1;
		NumOVF = NumOVF -(u32)NumOVF;
		u8 preload = 256 - (NumOVF * 256);
		TCNT0 = preload;
		while(NumOVF_int >0)
		{
			while(((TIFR>>0)&1)==0);
			TIFR |=(1<<0);
			NumOVF_int--;
		}
	}
	else
	{
		u32 NumOVF_int =(u32)NumOVF ;
		while(NumOVF_int >0)
		{
			while(((TIFR>>0)&1)==0);
			TIFR |=(1<<0);
			NumOVF_int--;
		}
	}
	return Local_enuErrorState;
}
ISR(VECT_TIMER0_OVF)
{
	if(gptr != NULL)
	{
		static u32 counts = 0;
		counts++;
		if(counts == Num_OVF)
		{
			TCNT0 = Preload;
			gptr(gpara);
			counts = 0;
		}
	}
}
