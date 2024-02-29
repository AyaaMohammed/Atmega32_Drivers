/*
 * I2C_Priv.h
 *
 *  Created on: Sep 4, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_I2C_I2C_PRIV_H_
#define DRIVER_MCAL_I2C_I2C_PRIV_H_

// I2C
#define TWAR      *((u8*)0x22)
#define TWBR      *((u8*)0x20)
#define TWCR      *((u8*)0x56)
#define TWDR      *((u8*)0x23)
#define TWSR      *((u8*)0x21)


#define BITRATE(IIC_SPEED)		((F_CPU-16ul*IIC_SPEED)/(2ul*IIC_SPEED*IIC_PRES))

#define I2C_MASTER			0
#define I2C_SLAVE			95

#endif /* DRIVER_MCAL_I2C_I2C_PRIV_H_ */
