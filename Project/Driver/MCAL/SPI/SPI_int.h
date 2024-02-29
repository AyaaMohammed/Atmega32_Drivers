/*
 * SPI_int.h
 *
 *  Created on: Aug 31, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_SPI_SPI_INT_H_
#define DRIVER_MCAL_SPI_SPI_INT_H_

ES_t SPI_enuMasterInit(void);

ES_t SPI_enuMasterTransmit(char Copy_u8Data);

ES_t SPI_enuSlaveInit(void);

ES_t SPI_enuSlaveReceive(char * Copy_u8Data);



#endif /* DRIVER_MCAL_SPI_SPI_INT_H_ */
