/*
 * LCD_config.h
 *
 *  Created on: Feb 22, 2023
 *      Author: 00214
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

//LCD MODE  8_BIT

#define LCD_MODE   EIGHT_BIT

// control pins

#define RS_PORT		DIO_u8PORTA
#define RS_PIN		DIO_u8PIN3

#define RW_PORT		DIO_u8PORTA
#define RW_PIN		DIO_u8PIN4

#define EN_PORT		DIO_u8PORTA
#define EN_PIN		DIO_u8PIN5

/*			Data Pins		*/
#define D7_PORT		DIO_u8PORTA
#define D7_PIN		DIO_u8PIN6

#define D6_PORT		DIO_u8PORTA
#define D6_PIN		DIO_u8PIN7

#define D5_PORT		DIO_u8PORTB
#define D5_PIN		DIO_u8PIN0

#define D4_PORT		DIO_u8PORTB
#define D4_PIN		DIO_u8PIN1

#define D3_PORT		DIO_u8PORTC
#define D3_PIN		DIO_u8PIN4

#define D2_PORT		DIO_u8PORTC
#define D2_PIN		DIO_u8PIN5

#define D1_PORT		DIO_u8PORTC
#define D1_PIN		DIO_u8PIN6

#define D0_PORT		DIO_u8PORTC
#define D0_PIN		DIO_u8PIN7


#endif /* LCD_CONFIG_H_ */
