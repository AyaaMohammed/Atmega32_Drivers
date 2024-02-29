/*
 * AVR_REG.h
 *
 *  Created on: Jul 2, 2023
 *      Author: 00214
 */

#ifndef DRIVER_LIB_AVR_REG_H_
#define DRIVER_LIB_AVR_REG_H_

/*
 * NULL
 */
///#define NULL  ((void*)0)

/*
 * DIO REGISTERS
 */

#define PORTA 	*((volatile u8*) 0x3B)
#define DDRA  	*((volatile u8*) 0x3A)
#define PINA  	*((volatile u8*) 0x39)

#define PORTB 	*((volatile u8*) 0x38)
#define DDRB  	*((volatile u8*) 0x37)
#define PINB  	*((volatile u8*) 0x36)

#define PORTC 	*((volatile u8*) 0x35)
#define DDRC  	*((volatile u8*) 0x34)
#define PINC  	*((volatile u8*) 0x33)

#define PORTD 	*((volatile u8*) 0x32)
#define DDRD  	*((volatile u8*) 0x31)
#define PIND  	*((volatile u8*) 0x30)

/*
 * INTERRUPT REGISTERS
 */
#ifndef EXT_REG
#define EXT_REG
#define SREG  	*((volatile u8*) 0x5f)
#endif

/*
 * ADC REGISTERS
 */
#define ADMUX	*((volatile u8*) 0x27)
#define ADCSRA	*((volatile u8*) 0x26)
#define ADCH	*((volatile u8*) 0x25)
#define ADCL	*((volatile u8*) 0x24)

/*
 * UASRT REGISTERS
 */

#define UDR		*((volatile u8*) 0x2c)
#define UCSRA	*((volatile u8*) 0x2b)
#define UCSRB	*((volatile u8*) 0x2a)
#define UCSRC	*((volatile u8*) 0x40)
#define UBRRL	*((volatile u8*) 0x29)
#define UBRRH	*((volatile u8*) 0x40)

/*
 * SPI REGISTERS
 */



#endif /* DRIVER_LIB_AVR_REG_H_ */
