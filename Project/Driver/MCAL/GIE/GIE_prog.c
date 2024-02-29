/*
 * GIE_prog.c
 *
 *  Created on: May 3, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorStates.h"
#include "GIE_priv.h"

ES_t GIE_enuEnable(void)
{
	ES_t Local_enuError = ES_NOK;

	SREG |=(1<<7);
	return Local_enuError;
}

ES_t GIE_enuDisable(void)
{
	ES_t Local_enuError = ES_NOK;
	SREG &=~(1<<7);
	return Local_enuError;
}
