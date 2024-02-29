/*
 * DIO_int.h
 *
 *  Created on: Feb 1, 2023
 *      Author: 00214
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
//port A B C D
#define DIO_u8PORTA   0
#define DIO_u8PORTB   1
#define DIO_u8PORTC   2
#define DIO_u8PORTD   3

#define DIO_u8PIN0   0
#define DIO_u8PIN1   1
#define DIO_u8PIN2   2
#define DIO_u8PIN3   3
#define DIO_u8PIN4   4
#define DIO_u8PIN5   5
#define DIO_u8PIN6   6
#define DIO_u8PIN7   7


#define DIO_u8HIGH     1
#define DIO_u8LOW      0
#define DIO_u8FLOAT    0
#define DIO_u8PULL_UP  1

#define DIO_u8INPUT    0
#define DIO_u8OUTPUT   1




ES_t DIO_enuInit(void); //pre_build conf

ES_t DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value); //I/O
ES_t DIO_enuSetValue(u8 Copy_u8PortID , u8 Copy_u8Value);// H/L
ES_t DIO_enuTogPortValue(u8 Copy_u8PortID); // tog
ES_t DIO_enuGetPortValue(u8 Copy_u8PortID ,u8 * Copy_pu8Value); // Get Value h/l
//pins
ES_t DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8Value ,u8 Copy_u8PinID); //I/O
ES_t DIO_enuSetPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID ,u8 Copy_u8Value);// H/L
ES_t DIO_enuTogPinValue(u8 Copy_u8PortID ,u8 Copy_u8PinID); // tog
ES_t DIO_enuGetPinValue(u8 Copy_u8PortID ,u8 * Copy_pu8Value , u8 Copy_u8PinID); // Get Value

#endif /* DIO_INT_H_ */
