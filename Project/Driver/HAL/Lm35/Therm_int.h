/*
 * Therm_int.h
 *
 *  Created on: May 6, 2023
 *      Author: 00214
 */

#ifndef DRIVER_LM35_THERM_INT_H_
#define DRIVER_LM35_THERM_INT_H_

ES_t THERMISTOR_enuInit(THERM_t*THERM_AstrThermistorConfig);

ES_t THERMISTOR_enuGetTemprtature(THERM_t*THERM_AstrThermistorConfig, u32 * Copy_pu8Temp);

#endif /* DRIVER_LM35_THERM_INT_H_ */
