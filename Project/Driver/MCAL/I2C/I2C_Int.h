/*
 * I2C_Int.h
 *
 *  Created on: Sep 4, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_I2C_I2C_INT_H_
#define DRIVER_MCAL_I2C_I2C_INT_H_

ES_t IIC_enuInit(void);

ES_t IIC_enuStartCondition(void);

ES_t IIC_enuRepeatedStartCondition(void);

ES_t IIC_enuStopCondition(void);

ES_t IIC_enuWriteSlaveAddress(u8  Copy_u8SlaveAddress,u8 Copy_u8Operation);

ES_t IIC_enuWriteData(u8 Copy_u8Data);

ES_t IIC_enuCheckMyAddress(void);

ES_t IIC_enuReadData(u8 * Copy_u8Data);


#endif /* DRIVER_MCAL_I2C_I2C_INT_H_ */
