/*
 * Switch_prog.c
 *
 *  Created on: Feb 6, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include  "../../LIB/errorStates.h"
#include "Switch_priv.h"
#include  "Switch_config.h"


#include  "../../MCAL/DIO/DIO_int.h"


ES_t Switch_enuInit(SW_t * Copy_AstrSwitchs){
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8Iterator = 0;
	if(Copy_AstrSwitchs != NULL){

		for(Local_u8Iterator =0; Local_u8Iterator<SW_NUM ;Local_u8Iterator++){
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_AstrSwitchs[Local_u8Iterator].SW_PortID,DIO_u8INPUT,Copy_AstrSwitchs[Local_u8Iterator].SW_PinID );
			Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrSwitchs[Local_u8Iterator].SW_PortID,Copy_AstrSwitchs[Local_u8Iterator].SW_PinID ,Copy_AstrSwitchs[Local_u8Iterator].SW_Status );

		}

	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState ;
}
ES_t Switch_enuGetState(SW_t * Copy_AstrSwitchs, u8 * Copy_pu8SwState){

	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_AstrSwitchs != NULL && Copy_pu8SwState != NULL){
		Local_enuErrorState = DIO_enuGetPinValue(Copy_AstrSwitchs ->SW_PortID ,Copy_pu8SwState,Copy_AstrSwitchs->SW_PinID);
	}
	else {
		Local_enuErrorState =ES_NULL_POINTER;
	}

    return Local_enuErrorState ;
}
