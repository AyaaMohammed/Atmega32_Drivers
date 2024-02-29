/*
 * LCD_prog.c
 *
 *  Created on: Feb 22, 2023
 *      Author: 00214
 */
#include  "../../LIB/stdTypes.h"
#include  "../../LIB/errorStates.h"
#include "../../MCAL/DIO/DIO_int.h"
#include  "LCD_config.h"
#include  "LCD_priv.h"
#include   "util/delay.h"

ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(RS_PORT,DIO_u8OUTPUT, RS_PIN);
	DIO_enuSetPinDirection(EN_PORT,DIO_u8OUTPUT, EN_PIN);
	DIO_enuSetPinDirection(RW_PORT,DIO_u8OUTPUT, RW_PIN);
	DIO_enuSetPinDirection(D7_PORT,DIO_u8OUTPUT, D7_PIN);
	DIO_enuSetPinDirection(D6_PORT,DIO_u8OUTPUT, D6_PIN);
	DIO_enuSetPinDirection(D5_PORT,DIO_u8OUTPUT, D5_PIN);
	DIO_enuSetPinDirection(D4_PORT,DIO_u8OUTPUT, D4_PIN);
	_delay_ms(35);

#if   LCD_MODE  == EIGHT_BIT

	DIO_enuSetPinDirection(D3_PORT,DIO_u8OUTPUT, D3_PIN);
	DIO_enuSetPinDirection(D2_PORT,DIO_u8OUTPUT, D2_PIN);
	DIO_enuSetPinDirection(D1_PORT,DIO_u8OUTPUT, D1_PIN);
	DIO_enuSetPinDirection(D0_PORT,DIO_u8OUTPUT, D0_PIN);
	// function set
	LCD_invidSendCommend(0x38);
#elif LCD_MODE == FOUR_BIT
	LCD_invidSendCommend(0x28);
#endif


	_delay_ms(1);
	LCD_invidSendCommend(0x0f);
	_delay_ms(1);
	LCD_invidSendCommend(0x01);
	_delay_ms(2);
	LCD_invidSendCommend(0X06);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8HIGH);
	LCD_voidLatch(Copy_u8Data);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
static void LCD_voidLatch(u8 Copy_u8Data)
{
	//set rw as write operation
	DIO_enuSetPinValue(RW_PORT,RW_PIN,DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);
	// write Data
	DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Data>>4)&1));
#if   LCD_MODE  == EIGHT_BIT
	DIO_enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Data>>0)&1));
#elif  LCD_MODE == FOUR_BIT

#endif
	// enable latch
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);
}
ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8LOW);
	LCD_voidLatch(Copy_u8Command);
	return Local_enuErrorState;
}
static inline void LCD_invidSendCommend(u8 Copy_u8Command)
{
	// set rs as command
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8LOW);
	//set rw as write operation
	DIO_enuSetPinValue(RW_PORT,RW_PIN,DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);
	// write Data
	DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Command>>7)&1));
	DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Command>>6)&1));
	DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Command>>5)&1));
	DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Command>>4)&1));
	DIO_enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Command>>3)&1));
	DIO_enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Command>>2)&1));
	DIO_enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Command>>1)&1));
	DIO_enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Command>>0)&1));

	// enable latch
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);
}

ES_t LCD_enuDisplayString(u8 *Copy_pu8String)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 i =0;
	while(Copy_pu8String[i]!='\0')
	{
		LCD_enuDisplayChar(Copy_pu8String[i]);
		i++;
	}
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_t LCD_enuConvertTostring(u8 Copy_pu8String[],s32 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 i ,Local_u8Length=0;
    s32 Local_s32Remanider,  Local_s32Number;
    Local_s32Number = Copy_u8Data;
    while (Local_s32Number != 0)
    {
    	Local_u8Length++;
    	Local_s32Number /= 10;
    }
    for (i = 0; i < Local_u8Length; i++)
    {
    	Local_s32Remanider = Copy_u8Data % 10;
        Copy_u8Data = Copy_u8Data / 10;
        Copy_pu8String[Local_u8Length - (i + 1)] = Local_s32Remanider + '0';
    }
    Copy_pu8String[Local_u8Length] = '\0';
    Local_enuErrorState = ES_OK;
    return Local_enuErrorState;
}




ES_t LCD_enuDisplayIntegerNum(s32 Copy_s32Num)
{
	ES_t Local_enuErrorState = ES_NOK;

	s32 Local_s32Reverse=0;
	u8 Local_u8Remainder=0 , Local_u8NumDigit=0;

	if(Copy_s32Num <0)
	{
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
		LCD_voidLatch('-');
		Copy_s32Num *= -1 ;
	}
	if(Copy_s32Num!=0)
	{
		while (Copy_s32Num)
		{
			Local_u8Remainder = Copy_s32Num % 10;
			Local_s32Reverse = Local_s32Reverse * 10 + Local_u8Remainder;
			Copy_s32Num /=10;
			Local_u8NumDigit ++;
		}

		while (Local_u8NumDigit)
		{
			Local_u8Remainder = Local_s32Reverse % 10;
			DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
			LCD_voidLatch(Local_u8Remainder + '0');
			Local_s32Reverse /= 10;
			Local_u8NumDigit --;
		}
	}
	else
	{
		LCD_voidLatch('0');
	}
	return Local_enuErrorState;
}






ES_t LCD_enuDisplayFloatNum(f32 Copy_f32Num)
{
	ES_t Local_enuErrorState = ES_NOK;

	f32 Local_f32FracNum = Copy_f32Num-(u32)Copy_f32Num;
	u32 Local_u32IntNum = Copy_f32Num - Local_f32FracNum;
	LCD_enuDisplayIntegerNum(Local_u32IntNum);
	LCD_enuDisplayChar('.');
	LCD_enuDisplayIntegerNum(Local_f32FracNum*100000);
	return Local_enuErrorState;
}
ES_t LCD_enuSetPosition(u8 Copy_u8Row , u8 Copy_u8Col)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8Row <=2 && Copy_u8Col <= 16)
	{
		DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8LOW);
		if(Copy_u8Row     ==    1)
		{
			LCD_invidSendCommend((0x80)+Copy_u8Col);
		}
		else if(Copy_u8Row == 2  )
		{
			LCD_invidSendCommend((0xc0)+Copy_u8Col);
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}





