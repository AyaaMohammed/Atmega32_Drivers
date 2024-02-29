/*
 * EXTI_config.c
 *
 *  Created on: May 5, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"

EXTI_t EXTI_AstrEXTIConfig [3] =
{
		{ACTIVE, FALLING_EDGE},
		{DEACTIVE},
		{DEACTIVE}
};
