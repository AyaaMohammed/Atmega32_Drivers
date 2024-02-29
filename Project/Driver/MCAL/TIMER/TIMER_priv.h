/*
 * TIMER_priv.h
 *
 *  Created on: May 13, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_TIMER_TIMER_PRIV_H_
#define DRIVER_MCAL_TIMER_TIMER_PRIV_H_


#define OVF		    0
#define DISCONNED   0






#define TIMSK  *((volatile u8*)0x59)
//
#define TIFR   *((volatile u8*)0x58)
//
#define TCCR0   *((volatile u8*)0x53)
#define TCCR1A  *((volatile u8*)0x4f)
#define TCCR1B  *((volatile u8*)0x4e)
#define TCCR2   *((volatile u8*)0x45)
//
#define TCNT0   *((volatile u8*)0x52)

#define TCNT1H  *((volatile u8*)0x4d)
#define TCNT1L  *((volatile u8*)0x4c)

#define TCNT1   *((volatile u16*)0x4c)

#define TCNT2   *((volatile u8*)0x44)
//
#define OCR0    *((volatile u8*)0x5c)
#define OCR1AH  *((volatile u8*)0x4b)
#define OCR1AL  *((volatile u8*)0x4a)

#define OCR1A   *((volatile u16*)0x4a)

#define OCR1BH  *((volatile u8*)0x49)
#define OCR1BL  *((volatile u8*)0x48)

#define OCR1B   *((volatile u16*)0x48)

#define OCR2    *((volatile u8*)0x43)





#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__ ((signal));\
							void VECT_NUM (void)

#define VECT_INT0			__vector_1
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3
#define VECT_TIMER2_CTC		__vector_4

#define VECT_TIMER0_CTC     __vector_10
#define VECT_TIMER0_OVF     __vector_11
#define VECT_ADC            __vector_16

#endif /* DRIVER_MCAL_TIMER_TIMER_PRIV_H_ */
