/*
 * LCD.c
 *
 *  Created on: Aug 15, 2023
 *      Author: lenovo
 */
#include "LCD.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO.h"

void HLCD_voidSendCommand(u8 A_u8cmd)
{
	//Rs and R/W
	MDIO_voidSetPinDirection(Control_Port,PIN0,OUTPUT);
	MDIO_voidSetPinDirection(Control_Port,PIN1,OUTPUT);

	MDIO_voidSetPinValue(Control_Port,PIN0,LOW);
	MDIO_voidSetPinValue(Control_Port,PIN1,LOW);

	//write data on data_port
	MDIO_voidSetPortDirection(Data_Port,OUTPUT);
	MDIO_voidSetPortValue(Data_Port,A_u8cmd);

	//Enable pin
	MDIO_voidSetPinDirection(Control_Port,PIN2,OUTPUT);

	MDIO_voidSetPinValue(Control_Port,PIN2,HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(Control_Port,PIN2,LOW);
	_delay_ms(1);
}

void HLCD_voidSendData(u8 A_u8data)
{
	//Rs and R/W
	MDIO_voidSetPinDirection(Control_Port,PIN0,OUTPUT);
	MDIO_voidSetPinDirection(Control_Port,PIN1,OUTPUT);

	MDIO_voidSetPinValue(Control_Port,PIN0,HIGH);
	MDIO_voidSetPinValue(Control_Port,PIN1,LOW);

	//write data on data_port
	MDIO_voidSetPortDirection(Data_Port,OUTPUT);
	MDIO_voidSetPortValue(Data_Port,A_u8data);

	//Enable pin
	MDIO_voidSetPinDirection(Control_Port,PIN2,OUTPUT);

	MDIO_voidSetPinValue(Control_Port,PIN2,HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(Control_Port,PIN2,LOW);
	_delay_ms(1);
}

void HLCD_void8bitInit()
{
	 //Delay on power on
	  _delay_ms(35);

	  //Set function
	  HLCD_voidSendCommand(LCD_FunctionSet);
	  _delay_ms(1);

	  //Display ON/OFF
	  HLCD_voidSendCommand(LCD_DisplayOnOff);
	  _delay_ms(1);

	  //Display Clear
	  HLCD_voidSendCommand(LCD_DisplayClear);
	  _delay_ms(2);

	  //Entry Mode Set
	  HLCD_voidSendCommand(LCD_EntryMode);

}

void HLCD_voidClear()
{
	 HLCD_voidSendCommand(LCD_DisplayClear);
	 _delay_ms(2);
}
void HLCD_voidSetCursor(u8 A_u8LineNum,u8 A_u8LinePos)
{
	switch(A_u8LineNum)
	{
		case LCD_LINE_1: HLCD_voidSendCommand(0x80 + 0 + A_u8LinePos); break;
		case LCD_LINE_2: HLCD_voidSendCommand(0x80 + 64 + A_u8LinePos); break;
	}
}
void HLCD_voidSendString(u8 *A_u8PtrString)
{
	while (*A_u8PtrString !='\0')
	{
		HLCD_voidSendData(*A_u8PtrString ++);
	}
}

void HLCD_voidDisplayChar(u8 A_u8Char)
{
	HLCD_voidSendData(A_u8Char);
}

void HLCD_voidDisplayNum(s32 A_s32Number)
{
	if(A_s32Number==0)
	{
		HLCD_voidDisplayChar('0');
		return;
	}
	u32 L_u32Num=0;
	u8 flag=0;
	if (A_s32Number < 0)
	{
		HLCD_voidDisplayChar('-');
		A_s32Number*=-1;
	}
	while ((A_s32Number % 10) == 0)
		{
			flag++;
			A_s32Number/=10;
		}
	while (A_s32Number !=0)
	{
		L_u32Num=((L_u32Num*10)+(A_s32Number%10));
		A_s32Number/=10;
	}
	while (L_u32Num >0)
	{
		HLCD_voidSendData((L_u32Num%10)+48);
		L_u32Num/=10;
	}
	while (flag !=0)
	{
		HLCD_voidDisplayChar('0');
		flag--;
	}
}

void HLCD_voidSaveCustomChar (u8 A_u8CGRAM_Index,u8 *A_u8CustomArray)
{
	HLCD_voidSendCommand(CGRAM_Init + (A_u8CGRAM_Index * CGRAM_AvailableChars));

	for (u8 L_u8Index=0; L_u8Index<CGRAM_AvailableChars; L_u8Index++)
	{
		HLCD_voidSendData(A_u8CustomArray[L_u8Index]);
	}
	HLCD_voidSendCommand(0x80);
}

void HLCD_voidDisplayCustomChar (u8 A_u8CGRAM_Index)
{
	if(A_u8CGRAM_Index<8)
	{
		HLCD_voidSendData(A_u8CGRAM_Index);
	}
}






