/*
 * Therm_config.c
 *
 *  Created on: May 6, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"
#include  "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "Therm_config.h"
#include "Therm_priv.h"



THERM_t THERM_AstrThermistorConfig[NUM_LM]=
{{DIO_u8PIN2 ,NOT_CONNECTED}};
