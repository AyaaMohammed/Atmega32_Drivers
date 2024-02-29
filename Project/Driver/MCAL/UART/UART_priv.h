/*
 * UART_priv.h
 *
 *  Created on: Jul 14, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_UART_UART_PRIV_H_
#define DRIVER_MCAL_UART_UART_PRIV_H_

#define NORMAL  2
#define DOUBLE  1

#define TRANSMITTER  0
#define RECIEVER    5
#define TRANSCIEVER   9
#define UDR		*((volatile u8*) 0x2c)
#define UCSRA	*((volatile u8*) 0x2b)
#define UCSRB	*((volatile u8*) 0x2a)
#define UCSRC	*((volatile u8*) 0x40)
#define UBRRL	*((volatile u8*) 0x29)
#define UBRRH	*((volatile u8*) 0x40)


#define EIGHT   8
#define FIVE    9

#define NO_PARITY   9
#define ODD_PARITY  18
#define EVEN_PARITY  4


#define ONE_STOP_BIT    9
#define TWO_STOP_BIT    5

#define SYCH	4
#define ASYCH	6

#define BUAD(BUAD_VAL)  (u16)(F_CPU/(SPEED_MODE*8*BUAD_VAL)-1)

#define UDRE    5
#define RXC      7




#endif /* DRIVER_MCAL_UART_UART_PRIV_H_ */
