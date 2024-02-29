/*
 * EXTI_int.h
 *
 *  Created on: May 5, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_EXT_INT_EXTI_INT_H_
#define DRIVER_MCAL_EXT_INT_EXTI_INT_H_

ES_t EXTI_enuInit (EXTI_t * Copy_pstrEXTIConfig);

ES_t EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel);

ES_t EXTI_enuEnableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuDisableINT(u8 Copy_u8EXTI_ID);

ES_t EXTI_enuCallBack(void (*Copy_pfunAppFun)(void*), void * Copy_pvidParameter , u8 Copy_u8EXTI_ID);
#define RISING_EDGE			5
#define FALLING_EDGE		9
#define ANY_LOGIC			19
#define LOW_LEVEL			93

#endif /* DRIVER_MCAL_EXT_INT_EXTI_INT_H_ */
