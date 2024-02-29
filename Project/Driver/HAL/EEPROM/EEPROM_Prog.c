/*
 * EEPROM_Prog.c
 *
 *  Created on: Sep 5, 2023
 *      Author: 00214
 */
#include"../../LIB/stdTypes.h"
#include"../../LIB/errorStates.h"

#include "../../MCAL/I2C/I2C_Int.h"

#include "EEPROM_Priv.h"
#include "EEPROM_Config.h"



ES_t EEPROM_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = IIC_enuInit();
	return Local_enuErrorState;
}

ES_t EEPROM_WriteData(u16 Copy_u16Address , u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	// BOUNDARY CHECK
#if EEPROM_TYPE == EIGHT_KBIT
	u8 Local_u8Address = ((0xA0	| (EEPROM_A2_STATE<<3) | ( ((Copy_u16Address>>8)&3) << 1))>>1);
	u8 	Local_ByteAddress = (u8)Copy_u16Address;
#endif

	if(ES_OK == IIC_enuStartCondition() )
	{
		if(ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address,0))
		{
			if(ES_OK == IIC_enuWriteData(Local_ByteAddress))
			{
				if(ES_OK == IIC_enuWriteData(Copy_u8Data))
				{
					IIC_enuStopCondition();
					Local_enuErrorState = ES_OK;
				}
			}
		}
	}

	return Local_enuErrorState;
}

ES_t EEPROM_enuReadData(u16 Copy_u16Address , u8 * Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
#if EEPROM_TYPE == EIGHT_KBIT
	u8 Local_u8Address = ((0xA0	| (EEPROM_A2_STATE<<3) | ( ((Copy_u16Address>>8)&3) << 1))>>1);
	u8 	Local_ByteAddress = (u8)Copy_u16Address;
#endif

	if(ES_OK == IIC_enuStartCondition() )
	{
		if(ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address,0))
		{
			if(ES_OK == IIC_enuWriteData(Local_ByteAddress))
			{
				if(ES_OK == IIC_enuRepeatedStartCondition())
				{
					if(ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address,1))
					{
						if(ES_OK == IIC_enuReadData(Copy_u8Data))
						{
							IIC_enuStopCondition();
							Local_enuErrorState = ES_OK;
						}
					}
				}
			}
		}
	}



	return Local_enuErrorState;
}
