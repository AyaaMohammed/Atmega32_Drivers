/*
 * TIMER_int.h
 *
 *  Created on: May 13, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_TIMER_TIMER_INT_H_
#define DRIVER_MCAL_TIMER_TIMER_INT_H_

ES_t TIMER_enuInit(void);

ES_t TIMER_enuSetPreload(u8 Copy_u8Preload);

ES_t TIMER_enuSetAsychDelay(u32 Copy_u8Time,void(*Copy_pfunApp)(void*),void*Parameter );
//  delay dependent ISR , not dependent before and after
ES_t TIMER_enuSetSychDelay(u32 Copy_u8Time);
// POLLING

#endif /* DRIVER_MCAL_TIMER_TIMER_INT_H_ */
