/*
 * DIO_priv.h
 *
 *  Created on: May 3, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_ADC_ADC_PRIV_H_
#define DRIVER_MCAL_ADC_ADC_PRIV_H_

#define PRES_2      6
#define PRES_4      5
#define PRES_8      2
#define PRES_16     1
#define PRES_32     8
#define PRES_64     7
#define PRES_128    9

#define AVCC_REF     16
#define AREFF_REF    36
#define INTERNAL     56

#define RIGHT_ADJ  14
#define LEFT_ADJ   12

#define ADMUX    *((u8*)0x27)
#define ADCSRA   *((u8*)0x26)
#define ADCH     *((volatile u8*)0x25)
#define ADCL     *((volatile u8*)0x24)
#define SFIOR    *((u8*)0x50)

#define SINGLE_ENDED	45
#define DIFFERENTIAL	34

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

#define FREE_RUNNING_MODE 	0
#define ANALOG_COMPARATOR 	1
#define EXIT0_INT 			2
#define TIMER0_CMP 			3
#define TIMER0_OVF 			4
#define TIMER_COMPARE_B 	5
#define TIMER1_OVF 			6
#define TIMER1_CAPTURE 		7

#endif /* DRIVER_MCAL_ADC_ADC_PRIV_H_ */
