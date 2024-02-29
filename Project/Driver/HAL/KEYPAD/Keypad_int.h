/*
 * Keypad_int.h
 *
 *  Created on: Feb 22, 2023
 *      Author: 00214
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_


ES_t Keypad_enuInit(void);

ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue);

#define KEYPAD_NOT_PRESSSED    0xff

#endif /* KEYPAD_INT_H_ */
