/*
 * EEPROM_Int.h
 *
 *  Created on: Sep 5, 2023
 *      Author: 00214
 */

#ifndef DRIVER_HAL_EEPROM_EEPROM_INT_H_
#define DRIVER_HAL_EEPROM_EEPROM_INT_H_

ES_t EEPROM_enuInit(void);

ES_t EEPROM_WriteData(u16 Copy_u16Address , u8 Copy_u8Data);

ES_t EEPROM_enuReadData(u16 Copy_u16Address , u8 * Copy_u8Data);


#endif /* DRIVER_HAL_EEPROM_EEPROM_INT_H_ */
