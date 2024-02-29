/*
 * ADC_int.h
 *
 *  Created on: May 3, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_ADC_ADC_INT_H_
#define DRIVER_MCAL_ADC_ADC_INT_H_

ES_t ADC_enuInit(void);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuPollingSystem(void);

ES_t ADC_enuReadHighValue(u8 * Copy_pu8Value);

ES_t ADC_enuRead(u16 * Copy_pu16Value);

ES_t ADC_enuCallBack(void(*Copy_pfunAppFun(void*)) , void * Copy_pvidAppParamater);

ES_t ADC_enuEnable(void);

ES_t ADC_enuDisable(void);

ES_t ADC_enuSelectChannel(u8 Copy_u8ChannelID);

ES_t ADC_enuEnableTriggeringMode(u8 CopyTriggeringSource);

ES_t ADC_enuDisableTriggeringMode(void);

ES_t ADC_enuEnableInterruptMode(void);

ES_t ADC_enuDisableInterruptMode(void);

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

#define ADC_FREE_RUNNING_MODE 	0
#define ADC_ANALOG_COMPARATOR 	1
#define ADC_EXIT0_INT 			2
#define ADC_TIMER0_CMP 			3
#define ADC_TIMER0_OVF 			4
#define ADC_TIMER_COMPARE_B 	5
#define ADC_TIMER1_OVF 			6
#define ADC_TIMER1_CAPTURE 		7







#endif /* DRIVER_MCAL_ADC_ADC_INT_H_ */
