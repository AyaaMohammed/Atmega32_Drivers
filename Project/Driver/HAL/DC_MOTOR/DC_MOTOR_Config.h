/*
 * DC_MOTOR_Config.h
 *
 *  Created on: Aug 25, 2023
 *      Author: 00214
 */

#ifndef DRIVER_HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_
#define DRIVER_HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_

#define MOTOR_PIN1_PORT   	DIO_u8PORTD
#define MOTOR_PIN2_PORT   	DIO_u8PORTD

#define MOTOR_PIN1_PIN   	DIO_u8PIN6
#define MOTOR_PIN2_PIN   	DIO_u8PIN7

#define MOTOR_STATES       	OFF

#define MOTOR_DIRECTION       	COUNTER_CLOCK_WISE

#define CLOCK_WISE    		 3
#define COUNTER_CLOCK_WISE   4

#define ON    7
#define OFF   9


#endif /* DRIVER_HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_ */
