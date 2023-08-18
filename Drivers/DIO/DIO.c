/*
 * DIO.c
 *
 *  Created on: Aug 11, 2023
 *      Author: lenovo
 */
#include "DIO.h"
#include "DIO_private.h"
#include "../../lib/Bit_Maths.h"
#include "../../lib/defines.h"

void MDIO_voidSetPinDirection(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinDirection)
{
	switch(A_u8PortNum)
	{
		case PORTA:
					switch(A_u8PinDirection)
					{
						case INPUT: CLR_BIT(DIO_DDRA_REG,A_u8PinNum); break;
						case OUTPUT: SET_BIT(DIO_DDRA_REG,A_u8PinNum); break;
					} break;
		case PORTB:
					switch(A_u8PinDirection)
					{
						case INPUT: CLR_BIT(DIO_DDRB_REG,A_u8PinNum); break;
						case OUTPUT: SET_BIT(DIO_DDRB_REG,A_u8PinNum); break;
					} break;
		case PORTC:
					switch(A_u8PinDirection)
					{
						case INPUT: CLR_BIT(DIO_DDRC_REG,A_u8PinNum); break;
						case OUTPUT: SET_BIT(DIO_DDRC_REG,A_u8PinNum); break;
					} break;
		case PORTD:
					switch(A_u8PinDirection)
					{
						case INPUT: CLR_BIT(DIO_DDRD_REG,A_u8PinNum); break;
						case OUTPUT: SET_BIT(DIO_DDRD_REG,A_u8PinNum); break;
					} break;
	}
}

void MDIO_voidSetPinValue (u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinValue)
{
	switch(A_u8PortNum)
		{
			case PORTA:
						switch(A_u8PinValue)
						{
							case INPUT: CLR_BIT(DIO_PORTA_REG,A_u8PinNum); break;
							case OUTPUT: SET_BIT(DIO_PORTA_REG,A_u8PinNum); break;
						} break;
			case PORTB:
						switch(A_u8PinValue)
						{
							case INPUT: CLR_BIT(DIO_PORTB_REG,A_u8PinNum); break;
							case OUTPUT: SET_BIT(DIO_PORTB_REG,A_u8PinNum); break;
						} break;
			case PORTC:
						switch(A_u8PinValue)
						{
							case INPUT: CLR_BIT(DIO_PORTC_REG,A_u8PinNum); break;
							case OUTPUT: SET_BIT(DIO_PORTC_REG,A_u8PinNum); break;
						} break;
			case PORTD:
						switch(A_u8PinValue)
						{
							case INPUT: CLR_BIT(DIO_PORTD_REG,A_u8PinNum); break;
							case OUTPUT: SET_BIT(DIO_PORTD_REG,A_u8PinNum); break;
						} break;
		}
}

u8 MDIO_u8GetPinValue (u8 A_u8PortNum,u8 A_u8PinNum)
{
	u8 L_u8PinValue;
	switch(A_u8PortNum)
	{
		case PORTA: L_u8PinValue=GET_BIT(DIO_PINA_REG,A_u8PinNum); break;
		case PORTB: L_u8PinValue=GET_BIT(DIO_PINB_REG,A_u8PinNum); break;
		case PORTC: L_u8PinValue=GET_BIT(DIO_PINC_REG,A_u8PinNum); break;
		case PORTD: L_u8PinValue=GET_BIT(DIO_PIND_REG,A_u8PinNum); break;
	}
	return L_u8PinValue;
}

void MDIO_voidTogglePin(u8 A_u8PortNum,u8 A_u8PinNum)
{
	switch(A_u8PortNum)
		{
			case PORTA: TOOGLE_BIT(DIO_PORTA_REG,A_u8PinNum); break;
			case PORTB: TOOGLE_BIT(DIO_PORTB_REG,A_u8PinNum); break;
			case PORTC: TOOGLE_BIT(DIO_PORTC_REG,A_u8PinNum); break;
			case PORTD: TOOGLE_BIT(DIO_PORTD_REG,A_u8PinNum); break;
		}
}

void MDIO_voidSetPortDirection (u8 A_u8PortNum,u8 A_u8PortDirection)
{
	switch(A_u8PortNum)
		{
			case PORTA:
				switch(A_u8PortDirection)
				{
				case OUTPUT:DIO_DDRA_REG=0XFF;; break;
				case INPUT:DIO_DDRA_REG=0X00; break;
				default: DIO_DDRA_REG=A_u8PortDirection; break;
				}
				break;

			case PORTB:
				switch(A_u8PortDirection)
				{
				case OUTPUT:DIO_DDRB_REG=0XFF;; break;
				case INPUT:DIO_DDRB_REG=0X00; break;
				default: DIO_DDRB_REG=A_u8PortDirection; break;
				}
				break;

			case PORTC:
				switch(A_u8PortDirection)
				{
				case OUTPUT:DIO_DDRC_REG=0XFF;; break;
				case INPUT:DIO_DDRC_REG=0X00; break;
				default: DIO_DDRC_REG=A_u8PortDirection; break;
				}
				break;

			case PORTD:
				switch(A_u8PortDirection)
				{
				case OUTPUT:DIO_DDRD_REG=0XFF;; break;
				case INPUT:DIO_DDRD_REG=0X00; break;
				default: DIO_DDRD_REG=A_u8PortDirection; break;
				}
				break;

		}

}

void MDIO_voidSetPortValue (u8 A_u8PortNum,u8 A_u8PortValue)
{
	switch(A_u8PortNum)
		{
			case PORTA: DIO_PORTA_REG=A_u8PortValue; break;
			case PORTB: DIO_PORTB_REG=A_u8PortValue; break;
			case PORTC: DIO_PORTC_REG=A_u8PortValue; break;
			case PORTD: DIO_PORTD_REG=A_u8PortValue; break;
		}
}

u8 MDIO_u8GetPortValue(u8 A_u8PortNum)
{
	u8 L_u8PortValue;
	switch(A_u8PortNum)
			{
				case PORTA: L_u8PortValue=DIO_PINA_REG; break;
				case PORTB: L_u8PortValue=DIO_PINB_REG; break;
				case PORTC: L_u8PortValue=DIO_PINC_REG; break;
				case PORTD: L_u8PortValue=DIO_PIND_REG; break;
			}
	return L_u8PortValue;
}

