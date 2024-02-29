/*
 * LCD_int.h
 *
 *  Created on: Feb 22, 2023
 *      Author: 00214
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuConvertTostring(u8 Copy_pu8String[],s32 Copy_u8Data);

ES_t LCD_enuDisplayString(u8 *Copy_pu8String);

ES_t LCD_enuDisplayIntegerNum(s32 Copy_s32Num);
ES_t LCD_enuDisplayFloatNum(f32 Copy_f32Num);
ES_t LCD_enuSetPosition(u8 Copy_u8Row , u8 Copy_u8Col);
#endif /* LCD_INT_H_ */
