/*
 * ADC_prog.c
 *
 *  Created on: May 3, 2023
 *      Author: 00214
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include"ADC_priv.h"
#include"ADC_config.h"

static volatile void (*ADC_pfunISRFun)(void*)=NULL;
static volatile void * ADC_pvidISRParameter = NULL;

ES_t ADC_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA |=(1<<7);   // Enable ADC
#if ADC_PRES ==  PRES_2
	ADCSRA &=~ (1<<0);
	ADCSRA &=~ (1<<1);
	ADCSRA |= (1<<2);
#elif ADC_PRES == PRES_4
	ADCSRA &=~ (1<<0);
	ADCSRA |= (1<<1);
	ADCSRA &=~ (1<<2);
#elif ADC_PRES == PRES_8
	ADCSRA &=~(1<<0);
	ADCSRA |= (1<<1);
	ADCSRA |= (1<<2);
#elif ADC_PRES == PRES_16
	ADCSRA |= (1<<0);
	ADCSRA &=~ (1<<1);
	ADCSRA &=~ (1<<2);
#elif ADC_PRES == PRES_32
	ADCSRA |= (1<<0);
	ADCSRA &=~ (1<<1);
	ADCSRA |= (1<<2);
#elif ADC_PRES == PRES_64
	ADCSRA |= (1<<0);
	ADCSRA |= (1<<1);
	ADCSRA &=~ (1<<2);
#elif ADC_PRES == PRES_128
	ADCSRA |= (1<<0);
	ADCSRA |= (1<<1);
	ADCSRA |= (1<<2);
#else
#error "ADC PERS is Wrong"
#endif

#if ADC_REF_VOLT == AREFF_REF
	ADMUX &=~(1<<7);
	ADMUX &=~(1<<6);
#elif ADC_REF_VOLT == INTERNAL
	ADMUX |= (1<<7);
	ADMUX |= (1<<6);
#elif ADC_REF_VOLT == AVCC_REF
	ADMUX &=~(1<<7);
	ADMUX |= (1<<6);
#else
#error "ADC REF_VOLT is Wrong"
#endif

#if ADC_ADJ == LEFT_ADJ
	ADMUX |= (1<<5);
#elif ADC_ADJ == RIGHT_ADJ
	ADMUX &=~(1<<5);
#else
#error "ADC ADJ is Wrong" // stop build
#endif

	return Local_enuErrorState;
}
ES_t ADC_enuStartConversion(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA |=(1<<6);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuPollingSystem(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	while(((ADCSRA>>4)&1) == 0);
		ADCSRA |=(1<<4);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuReadHighValue(u8 * Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;
#if ADC_ADJ==LEFT_ADJ
	*Copy_pu8Value = ADCH;
#elif  ADC_ADJ == RIGHT_ADJ
	*Copy_pu8Value  = (ADCL >> 2);
	*Copy_pu8Value |= (ADCH << 6);
#else
#error "ADC ADJ is Wrong"
#endif
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuRead(u16 * Copy_pu16Value)
{
	ES_t Local_enuErrorState = ES_NOK;
#if ADC_ADJ == LEFT_ADJ
	*Copy_pu16Value  =  (ADCL>>6) ;
	*Copy_pu816Value |=  (ADCH<<2);
#elif  ADC_ADJ == RIGHT_ADJ
	*Copy_pu16Value  = ADCL;
	*Copy_pu16Value |= ((u16)ADCH<<8);// implict casting(complier dependent)
#else
#error "ADC ADJ is Wrong"
#endif
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuCallBack(void(*Copy_pfunAppFun(void*)) , void * Copy_pvidAppParamater)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_pfunAppFun != NULL)
	{
		ADC_pfunISRFun = Copy_pfunAppFun;
		ADC_pvidISRParameter = Copy_pvidAppParamater;
	}
	return Local_enuErrorState;
}


ES_t ADC_enuEnable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA |=(1<<7);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}


ES_t ADC_enuDisable(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA &=~(1<<7);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}


ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID)
{
	ES_t Local_enuErrorState = ES_NOK;
	//Clear MUX4:0
	ADMUX &=~ 0x1F;
	//Single Ended Mode
	if(ADC_SOURCE_INPUT == SINGLE_ENDED)
	{
		switch(Copy_u8ChannelID)
		{
		case ADC0:
			Local_enuErrorState = ES_OK;
			break;
		case ADC1:
			ADMUX |= (1<<0);
			Local_enuErrorState = ES_OK;
			break;
		case ADC2:
			ADMUX |= (1<<1);
			Local_enuErrorState = ES_OK;
			break;
		case ADC3:
			ADMUX |= (1<<0);
			ADMUX |= (1<<1);
			Local_enuErrorState = ES_OK;
			break;
		case ADC4:
			ADMUX |= (1<<2);
			Local_enuErrorState = ES_OK;
			break;
		case ADC5:
			ADMUX |= (1<<0);
			ADMUX |= (1<<2);
			Local_enuErrorState = ES_OK;
			break;
		case ADC6:
			ADMUX |= (1<<1);
			ADMUX |= (1<<2);
			Local_enuErrorState = ES_OK;
			break;
		case ADC7:
			ADMUX |= (1<<0);
			ADMUX |= (1<<1);
			ADMUX |= (1<<2);
			Local_enuErrorState = ES_OK;
			break;
		default:
			Local_enuErrorState = ES_NOK;
		}
	}
	//Differential Mode
	else if(ADC_SOURCE_INPUT == DIFFERENTIAL)
	{

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}


ES_t ADC_enuEnableTriggeringMode(u8 CopyTriggeringSource)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA &=~(1<<5);
	switch(CopyTriggeringSource)
	{
	case FREE_RUNNING_MODE:
		SFIOR &=~(1<<5);
		SFIOR &=~(1<<6);
		SFIOR &=~(1<<7);
		break;
	case ANALOG_COMPARATOR:
		SFIOR |= (1<<5);
		SFIOR &=~(1<<6);
		SFIOR &=~(1<<7);
		break;
	case EXIT0_INT :
		SFIOR &=~(1<<5);
		SFIOR |= (1<<6);
		SFIOR &=~(1<<7);
		Local_enuErrorState = ES_OK;
		break;
	case TIMER0_CMP:
		SFIOR |= (1<<5);
		SFIOR |= (1<<6);
		SFIOR &=~(1<<7);
		break;
	case TIMER0_OVF:
		SFIOR &=~(1<<5);
		SFIOR &=~(1<<6);
		SFIOR |= (1<<7);
		break;
	case TIMER_COMPARE_B:
		SFIOR |= (1<<5);
		SFIOR &=~(1<<6);
		SFIOR |= (1<<7);
		break;
	case TIMER1_OVF:
		SFIOR &=~(1<<5);
		SFIOR |= (1<<6);
		SFIOR |= (1<<7);
		break;
	case TIMER1_CAPTURE:
		SFIOR |= (1<<5);
		SFIOR |= (1<<6);
		SFIOR |= (1<<7);
		break;
	default :
		break;
	}
	ADCSRA |= (1<<5);
	return Local_enuErrorState;
}


ES_t ADC_enuDisableTriggeringMode(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA &=~ (1<<5);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}


ES_t ADC_enuEnableInterruptMode(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA |= (1<<3);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}


ES_t ADC_enuDisableInterruptMode(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	ADCSRA &=~(1<<3);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ISR(VECT_ADC)
{
	if(ADC_pfunISRFun != NULL)
	{
		ADC_pfunISRFun(ADC_pvidISRParameter);
	}
}
