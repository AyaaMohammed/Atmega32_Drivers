/*
 * LCD_priv.h
 *
 *  Created on: Feb 22, 2023
 *      Author: 00214
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define  EIGHT_BIT    44
#define  FOUR_BIT     4


static inline void LCD_invidSendCommend(u8 Copy_u8Command);

static void LCD_voidLatch(u8 Copy_u8Data);

#endif /* LCD_PRIV_H_ */
