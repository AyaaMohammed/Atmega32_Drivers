/*
 * ADC_config.h
 *
 *  Created on: May 3, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_ADC_ADC_CONFIG_H_
#define DRIVER_MCAL_ADC_ADC_CONFIG_H_

#define ADC_PRES       PRES_128

#define ADC_REF_VOLT   AVCC_REF

#define ADC_ADJ        RIGHT_ADJ

#define ADC_SOURCE_INPUT   SINGLE_ENDED
#define ADC_INPUT          ADC2

#define ISR(VECT_NUM)  void VECT_NUM (void)__attribute__((signal));\
					   void VECT_NUM (void)

#define VECT_INT0   		__vector_1
#define VECT_INT1   		__vector_2
#define VECT_INT2   		__vector_3
#define VECT_TIMER2_CTC 	__vector_4
#define VECT_ADC			__vector_16
#endif /* DRIVER_MCAL_ADC_ADC_CONFIG_H_ */
