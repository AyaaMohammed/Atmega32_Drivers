/*
 * DC_MOTOR_Int.h
 *
 *  Created on: Aug 25, 2023
 *      Author: 00214
 */

#ifndef DRIVER_HAL_DC_MOTOR_DC_MOTOR_INT_H_
#define DRIVER_HAL_DC_MOTOR_DC_MOTOR_INT_H_

ES_t DC_MOTOR_enuInit(void);

ES_t DC_MOTOR_enuDirection(u8 Copy_u8Direction , u8 Copy_u8States);

ES_t DC_MOTOR_enuStop();

#endif /* DRIVER_HAL_DC_MOTOR_DC_MOTOR_INT_H_ */
