/*
 * Therm_config.h
 *
 *  Created on: May 6, 2023
 *      Author: 00214
 */

#ifndef DRIVER_LM35_THERM_CONFIG_H_
#define DRIVER_LM35_THERM_CONFIG_H_

#define NUM_LM  2

typedef struct
{
	u8 THERM_u8PostivePinChannel;
	u8 THERM_u8NegativePinChannel;
}THERM_t;


#endif /* DRIVER_LM35_THERM_CONFIG_H_ */
