/*
 * UART_int.h
 *
 *  Created on: Jul 14, 2023
 *      Author: 00214
 */

#ifndef DRIVER_MCAL_UART_UART_INT_H_
#define DRIVER_MCAL_UART_UART_INT_H_

ES_t UART_enuInit(void);

ES_t UART_enuSendChar(u8 Copy_u8Data);

ES_t UART_enuRecieveChar(u8 * Copy_puData);

ES_t UART_enuSendString(const char * Copy_pcData);

ES_t UART_enuRecieveString(char * Copy_pcData);

#endif /* DRIVER_MCAL_UART_UART_INT_H_ */
