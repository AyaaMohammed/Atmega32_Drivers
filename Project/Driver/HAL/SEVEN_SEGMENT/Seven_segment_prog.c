/*
 * Seven_segment_prog.c
 *
 *  Created on: Feb 8, 2023
 *      Author: 00214
 */
#include "../../LIB/stdTypes.h"
#include  "../../LIB/errorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Seven_segment_config.h"
#include "Seven_segment_priv.h"

extern SEG_t SEVSEG_AstrSegConfig [SEG_NUM];

ES_t Seven_Segment_enuInit(SEG_t *  Copy_pstrSegConfig)
{
	u32 Local_u32Check = 0;
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8Iter = 0;
	for(Local_u8Iter = 0 ; Local_u8Iter < SEG_NUM ; Local_u8Iter++)
	{
		Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8APort,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8APin)<<0);
		Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8BPort,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8BPin)<<2);
		Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8CPort,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8CPin)<<4);
		Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8DPort,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8DPin)<<6);
		Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8EPort,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8EPin)<<8);
		Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8FPort,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8FPin)<<10);
		Local_u32Check |= (DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8GPort,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8GPin)<<12);

		if(Copy_pstrSegConfig[Local_u8Iter].SEG_u8CMN_Port != NOT_CONNECTED && Copy_pstrSegConfig[Local_u8Iter].SEG_u8CMN_Pin != NOT_CONNECTED)
		{
			Local_enuErrorState =DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8CMN_Port,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8CMN_Pin);
		}
		if(Copy_pstrSegConfig[Local_u8Iter].SEG_u8DOT_Port != NOT_CONNECTED && Copy_pstrSegConfig[Local_u8Iter].SEG_u8DOT_Pin != NOT_CONNECTED)
		{
			Local_enuErrorState =DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_u8DOT_Port,DIO_u8OUTPUT,Copy_pstrSegConfig[Local_u8Iter].SEG_u8DOT_Pin);
		}

	}

	for(Local_u8Iter=0 ; Local_u8Iter < 12 ; Local_u8Iter +=2)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iter)&3) != ES_OK )
		{
			return Local_enuErrorState;
		}
	}
	Local_enuErrorState	 =	ES_OK;

	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8SegID ,u8 Copy_u8Num)
{
	u32 Local_u32Check = 0;
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8Num < 10 && Copy_u8SegID	 < SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin,((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1)) << 0);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1)) << 2);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1)) << 4);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1)) << 6);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1)) << 8);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1)) << 10);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1)) << 12);
		}
		else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin,!((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1)) << 0);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1)) << 2);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1)) << 4);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1)) << 6);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1)) << 8);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1)) << 10);
			Local_u32Check |= (DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,!((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1)) << 12);
		}
	}
	u8 Local_u8Iter = 0;
		for(Local_u8Iter=0 ; Local_u8Iter < 12 ; Local_u8Iter +=2)
	{
		if( ( ( (Local_u32Check)>>Local_u8Iter)&3) != ES_OK )
		{
			return Local_enuErrorState;
		}
	}
		Local_enuErrorState	 =	ES_OK;
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuEnableCommon(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port != NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin != NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState= DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin,DIO_u8LOW);
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState =DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin,DIO_u8HIGH);
			}
		}
	}
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableCommon(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port != NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin != NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin,DIO_u8HIGH);
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin,DIO_u8LOW);
			}
		}
	}
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuEnableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port != NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin != NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin,DIO_u8HIGH);
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin,DIO_u8LOW);
			}
		}
	}
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port != NOT_CONNECTED && SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin != NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin,DIO_u8LOW);
			}
			else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin,DIO_u8HIGH);
			}
		}
	}
	return Local_enuErrorState;
}

ES_t Seven_Segment_enuClearDisplay(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState = ES_NOK;
	if( Copy_u8SegID < SEG_NUM)
	{ ///if enable connect  dot clear added
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin,DIO_u8LOW);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,DIO_u8LOW);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,DIO_u8LOW);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,DIO_u8LOW);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,DIO_u8LOW);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,DIO_u8LOW);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,DIO_u8LOW);
		}
		else if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin,DIO_u8HIGH);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin,DIO_u8HIGH);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin,DIO_u8HIGH);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin,DIO_u8HIGH);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin,DIO_u8HIGH);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin,DIO_u8HIGH);
			Local_enuErrorState=DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin,DIO_u8HIGH);
		}
	}
	return Local_enuErrorState;
}




