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
	 HLCD_voidSendCommand(0b00000000);
	 HLCD_voidSendCommand(0b00010000);
	 _delay_ms(5);
}
void HLCD_voidSetCursor(u8 A_u8RowNum,u8 A_u8ColNum)
{
	switch(A_u8RowNum)
	{
		case LCD_LINE_1: HLCD_voidSendCommand(LCD_ROW_1+A_u8ColNum); break;
		case LCD_LINE_2: HLCD_voidSendCommand(LCD_ROW_2+A_u8ColNum); break;
	}
}
void HLCD_voidSendString(u8 *A_u8PtrString)
{
	while (*A_u8PtrString > 0)
	{
		HLCD_voidSendData(*A_u8PtrString ++);
	}
}

