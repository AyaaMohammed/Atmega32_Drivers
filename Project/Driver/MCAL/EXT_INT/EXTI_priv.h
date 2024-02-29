/*
 * EXTI_priv.h
 *
 *  Created on: May 5, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_EXT_INT_EXTI_PRIV_H_
#define DRIVER_MCAL_EXT_INT_EXTI_PRIV_H_

#define ACTIVE 		5
#define DEACTIVE 		9


#define RISING_EDGE			5
#define FALLING_EDGE		9
#define ANY_LOGIC			19
#define LOW_LEVEL			93


#define MCUCR				*((u8*)0x55)
#define MCUCSR				*((u8*)0x54)
#define GICR				*((u8*)0x5B)
#define GIFR				*((u8*)0x5A)

#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__ ((signal));\
							void VECT_NUM (void)

#define VECT_INT0			__vector_1
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3
#define VECT_TIMER2_CTC		__vector_4

#define VECT_TIMER0_OVF     __vector_11

#endif /* DRIVER_MCAL_EXT_INT_EXTI_PRIV_H_ */
