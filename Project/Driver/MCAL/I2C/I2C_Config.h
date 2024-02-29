/*
 * I2C_Config.h
 *
 *  Created on: Sep 4, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_I2C_I2C_CONFIG_H_
#define DRIVER_MCAL_I2C_I2C_CONFIG_H_

#define IIC_MODE 				I2C_MASTER

#define IIC_CLOCK_SPEED			100000ul
// 0 1 16 64
#define IIC_PRES				1ul

#define IIC_NODE_ADDRESS		2

#define IIC_RECOG_GENERAL_CALL  0

#endif /* DRIVER_MCAL_I2C_I2C_CONFIG_H_ */
