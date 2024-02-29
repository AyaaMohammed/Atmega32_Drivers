/*
 * TIMER1_Priv.h
 *
 *  Created on: Sep 6, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_TIMER1_TIMER1_PRIV_H_
#define DRIVER_MCAL_TIMER1_TIMER1_PRIV_H_

#define TIMSK		*((volatile u8*)0X59)
#define TICIE1		5
#define OCIE1A		4
#define OCIE1B		3
#define TOIE1		2

#define TIFR		*((volatile u8*)0X58)
#define ICF1		5
#define OCF1A		4
#define OCF1B		3
#define TOV1		2

#define TCCR1A		*((volatile u8*)0X4F)
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
#define FOC1A		3
#define FOC1B		2
#define WGM11		1
#define WGM10		0



#define TCCR1B		*((volatile u8*)0X4E)
#define ICNC1		7
#define ICES1		6
#define WGM13		4
#define WGM12		3
#define CS12		2
#define CS11		1
#define CS10		0

#define TCNT1			*((volatile u16*)0X4C)
#define TCNT1L          *((volatile u8 *)0x4C)
#define TCNT1H          *((volatile u8 *)0x4D)


#define OCR1A			 *((volatile u16*)0X4A)
#define OCR1AL       	 *((volatile u8 *)0x4A)
#define OCR1AH           *((volatile u8 *)0x4B)



#define OCR1B			*((volatile u16*)0X48)
#define OCR1BL          *((volatile u8 *)0x48)
#define OCR1BH          *((volatile u8 *)0x49)



#define ICR1			*((volatile u16*)0X46)
#define ICR1L           *((volatile u8 *)0x46)
#define ICR1H           *((volatile u8 *)0x47)



#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__ ((signal));\
							void VECT_NUM (void)

#define VECT_INT0			__vector_1
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3
#define VECT_TIMER2_CTC		__vector_4
#define VECT_TIMER1_CAPT	__vector_6
#define VECT_TIMER1_COMPA	__vector_7
#define VECT_TIMER1_COMPB	__vector_8
#define VECT_TIMER1_OVF		__vector_9
// PRESCALER
#define TIMER1_PRE_NO_CLOCK						0
#define TIMER1_PRE_1							1
#define TIMER1_PRE_8							8
#define TIMER1_PRE_64							64
#define TIMER1_PRE_256							256
#define TIMER1_PRE_1024							1024
#define TIMER1_EXTERNAL_CLOCK_ON_FALLING_EDGE	7
#define TIMER1_EXTERNAL_CLOCK_ON_RISING_EDGE	8

// Mode
#define TIMER1_NORMAL_TOP_0XFFFF						0
#define TIMER1_PWM_PHASE_CORRECT_8BIT_TOP_0X00FF		1
#define TIMER1_PWM_PHASE_CORRECT_9BIT_TOP_0X01FF		2
#define TIMER1_PWM_PHASE_CORRECT_10BIT_TOP_0X03FF		3
#define TIMER1_CTC_TOP_OCR1A							4
#define TIMER1_FAST_PWM_8BIT_TOP_0X00FF					5
#define TIMER1_FAST_PWM_9BIT_TOP_0X01FF					6
#define TIMER1_FAST_PWM_10BIT_TOP_0X03FF				7
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_ICR1 	8
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_	OCR1A   9
#define TIMER1_PWM_PHASE_CORRECT_TOP_ICR1				10
#define TIMER1_PWM_PHASE_CORRECT_TOP_OCR1A				11
#define TIMER1_CTC_TOP_ICR1								12
#define TIMER1_FAST_PWM_TOP_ICR1						14
#define TIMER1_FAST_PWM_TOP_OCR1A						15


// OC0 PIN STATES channel A
#define TIMER1_DISCONNECTED_OVF_OC0_CHA           	 			1

#define TIMER1_DISCONNECTED_CTC_OC0_CHA							2
#define TIMER1_TOGGLE_CTC_OC0_CHA  								3
#define TIMER1_CLEAR_CTC_OC0_CHA  								4
#define TIMER1_SET_CTC_OC0_CHA  								5

#define TIMER1_FAST_PWM_CLEAR_CTC_SET_TOP_CHA  					6
#define TIMER1_FAST_PWM_SET_CTC_CLEAR_TOP_CHA  					7

#define TIMER1_PHASE_CORRECT_CLEAR_CTC_UP_SET_CTC_DOWN_CHA  	8
#define TIMER1_PHASE_CORRECT_SET_CTC_UP_CLEAR_CTC_DOWN_CHA  	9


// OC0 PIN STATES channel B
#define TIMER1_DISCONNECTED_OVF_OC0_CHB           	 			1

#define TIMER1_DISCONNECTED_CTC_OC0_CHB							2
#define TIMER1_DISCONNECTED_NORMAL_CTC_OC0_CHB  						3
#define TIMER1_CLEAR_CTC_OC0_CHB  								4
#define TIMER1_SET_CTC_OC0_CHB  								5

#define TIMER1_FAST_PWM_CLEAR_CTC_SET_TOP_CHB  					6
#define TIMER1_FAST_PWM_SET_CTC_CLEAR_TOP_CHB  					7

#define TIMER1_PHASE_CORRECT_CLEAR_CTC_UP_SET_CTC_DOWN_CHB  	8
#define TIMER1_PHASE_CORRECT_SET_CTC_UP_CLEAR_CTC_DOWN_CHB  	9

#define FALLING_EDGE		0
#define RISING_EDGE			1
#endif /* DRIVER_MCAL_TIMER1_TIMER1_PRIV_H_ */
