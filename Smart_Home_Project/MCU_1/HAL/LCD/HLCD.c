/*
 * HLCD.c
 *
 *  Created on: 16 Aug 2023
 *      Author: ehab
 */

#include "HLCD.h"

static void HLCD_voidGenerateBulse()
{
	MDIO_voidSetPinValue(LCD_Control_PORT,EN,HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_Control_PORT,EN,LOW);
	_delay_ms(2);
}

#if (LCD_MODE == EIGHT_BIT)

void HLCD_voidInit()
{
	_delay_ms(50);

	MDIO_voidSetPinDirection(LCD_Control_PORT,RS,OUTPUT);
	MDIO_voidSetPinDirection(LCD_Control_PORT,RW,OUTPUT);
	MDIO_voidSetPinDirection(LCD_Control_PORT,EN,OUTPUT);

	MDIO_voidSetPortDirection(LCD_Data_PORT,0xFF);

	// FunctionSet 0b00111000
	HLCD_voidSendCommand(LCD_FunctionSet);
	_delay_ms(1);

	// Display on/off control 0b00001110
	HLCD_voidSendCommand(LCD_Display);
	_delay_ms(1);

	// Clear display 0x01
	HLCD_voidClear();

	// Entry Mode 0b00000110
	HLCD_voidSendCommand(LCD_EntryMode);
	_delay_ms(1);

}

void HLCD_voidSendData(u8 A_u8Data)
{
	MDIO_voidSetPinValue(LCD_Control_PORT,RS,HIGH);
	MDIO_voidSetPinValue(LCD_Control_PORT,RW,LOW);
	MDIO_voidSetPortValue(LCD_Data_PORT,A_u8Data);
	HLCD_voidGenerateBulse();
}

void HLCD_voidSendCommand(u8 A_u8Command)
{
	MDIO_voidSetPinValue(LCD_Control_PORT,RS,LOW);
	MDIO_voidSetPinValue(LCD_Control_PORT,RW,LOW);
	MDIO_voidSetPortValue(LCD_Data_PORT,A_u8Command);
	HLCD_voidGenerateBulse();
}

#elif (LCD_MODE == FOUR_BIT)

void HLCD_voidInit()
{
	_delay_ms(50);

	MDIO_voidSetPinDirection(LCD_Control_PORT,RS,OUTPUT);
	MDIO_voidSetPinDirection(LCD_Control_PORT,RW,OUTPUT);
	MDIO_voidSetPinDirection(LCD_Control_PORT,EN,OUTPUT);

	MDIO_voidSetLowNibbleDirection(LCD_Data_PORT);

	// FunctionSet_2 0b00101000
	HLCD_voidReturnHome();
	HLCD_voidSendCommand(LCD_FunctionSet_2);
	_delay_ms(1);

	// Display on/off control 0b00001110
	HLCD_voidSendCommand(LCD_Display);
	_delay_ms(1);

	// Clear display 0x01
	HLCD_voidClear();

	// Entry Mode 0b00000110
	HLCD_voidSendCommand(LCD_EntryMode);
	_delay_ms(1);

}

void HLCD_voidSendData(u8 A_u8Data)
{
	MDIO_voidSetPinValue(LCD_Control_PORT,RS,HIGH);
	MDIO_voidSetPinValue(LCD_Control_PORT,RW,LOW);

	MDIO_voidSetLowNibble(LCD_Data_PORT,A_u8Data>>4);
	HLCD_voidGenerateBulse();

	MDIO_voidSetLowNibble(LCD_Data_PORT,A_u8Data);
	HLCD_voidGenerateBulse();
}

void HLCD_voidSendCommand(u8 A_u8Command)
{
	MDIO_voidSetPinValue(LCD_Control_PORT,RS,LOW);
	MDIO_voidSetPinValue(LCD_Control_PORT,RW,LOW);

	MDIO_voidSetLowNibble(LCD_Data_PORT,A_u8Command>>4);
	HLCD_voidGenerateBulse();

	MDIO_voidSetLowNibble(LCD_Data_PORT,A_u8Command);
	HLCD_voidGenerateBulse();
}

#endif


void HLCD_voidSendCharacter(u8 A_u8Character)
{
	HLCD_voidSendData(A_u8Character);
}

void HLCD_voidClear()
{
	HLCD_voidSendCommand(LCD_ClearDisplay);
	// command duration
	_delay_ms(2);
}

void HLCD_voidReturnHome()
{
	HLCD_voidSendCommand(LCD_ReturnHome);
	// command duration
	_delay_ms(2);
}

void HLCD_voidSendString(u8 *A_u8string)
{
	while(*A_u8string != NULL)
	{
		HLCD_voidSendData(*A_u8string);
		A_u8string++;
	}
}

void HLCD_voidMoveCursor(u8 A_u8Line,u8 A_u8Col)
{
	if(A_u8Line>2 || A_u8Col>16)
	{
		HLCD_voidReturnHome();
	}
	else
	{
		switch(A_u8Line)
			{
				case LINE_1: HLCD_voidSendCommand(LCD_LINE_1+A_u8Col); break;
				case LINE_2: HLCD_voidSendCommand(LCD_LINE_2+A_u8Col); break;
			}
	}
}

void HLCD_voidSaveCustomChar(u8 *A_u8CustomArray,u8 A_u8CGRAMIndex)
{
	HLCD_voidSendCommand(0x40 + (A_u8CGRAMIndex * 8));

	for(u8 L_u8Index ;L_u8Index<8; L_u8Index++)
	{
		HLCD_voidSendData(A_u8CustomArray[L_u8Index]);
	}
	HLCD_voidSendCommand(0x80);
}

void HLCD_voidDisplayCustomChar(u8 A_u8CGRAMIndex)
{
	if(A_u8CGRAMIndex < 8)
	{
		HLCD_voidSendData(A_u8CGRAMIndex);
	}
}

void HLCD_voidDisplayNumber(s32 A_s32Number)
{
	u32 L_u32Number=1;

	if(A_s32Number == 0){
		HLCD_voidSendData('0');
	}
	if(A_s32Number <0){
		HLCD_voidSendData('-');
		A_s32Number *=-1;
	}
	while(A_s32Number !=0 ){
		L_u32Number= ((L_u32Number*10)+(A_s32Number%10));
		A_s32Number= A_s32Number/10;
	}
	while (L_u32Number !=1){

	HLCD_voidSendData((L_u32Number%10)+'0');
		L_u32Number= L_u32Number/10;
	}
}
