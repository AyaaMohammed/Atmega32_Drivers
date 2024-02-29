/*
 * TIMER1_Int.h
 *
 *  Created on: Sep 6, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_TIMER1_TIMER1_INT_H_
#define DRIVER_MCAL_TIMER1_TIMER1_INT_H_

ES_t Timer1_enuInit(void);
ES_t Timer1_enuSetPreloadValue(u16 Copy_u16Value);
ES_t Timer1_enuReadValue(u16 * Copy_u16PValue);
ES_t Timer1_enuICUSetTriggerEdge(u8 Copy_u8Edge);
ES_t  Timer1_u16ReadICR1Value(u16 * Copy_u16PValue);
ES_t Timer1_enuSetOCR1AValue(u16 Copy_u16Value);
ES_t Timer1_enuSetOCR1BValue(u16 Copy_u16Value);
ES_t Timer1_enuSetICR1Value(u16 Copy_u16Value);

ES_t Timer1_enuOVFInterruptEnable(void);
ES_t Timer1_enuOVFInterruptDisable(void);
ES_t Timer1_enuOC1AInterruptEnable(void);
ES_t Timer1_enuOC1AInterruptDisable(void);
ES_t Timer1_enuOC1BInterruptEnable(void);
ES_t Timer1_enuOC1BInterruptDisable(void);
ES_t Timer1_enuICUInterruptEnable(void);
ES_t Timer1_enuICUInterruptDisable(void);
//SetCallback Functions
ES_t Timer1_enuOVFSetCallBack(void (*Copy_pfNotification)(void));
ES_t Timer1_enuOC1ASetCallBack(void (*Copy_pfNotification)(void));
ES_t Timer1_enuOC1BSetCallBack(void (*Copy_pfNotification)(void));
ES_t Timer1_enuICUSetCallBack(void (*Copy_pfNotification)(void));



#endif /* DRIVER_MCAL_TIMER1_TIMER1_INT_H_ */
