/*
 * DC_Motor.c
 *
 *  Created on: Aug 16, 2023
 *      Author: lenovo
 */
#include "DC_Motor.h"
#include "../../MCAL/DIO/DIO.h"


void HDCM_voidInitPort(u8 A_u8PortNum)
{
	G_u8PortNum=A_u8PortNum;
	MDIO_voidSetPinDirection(G_u8PortNum , PIN0 , OUTPUT);
	MDIO_voidSetPinDirection(G_u8PortNum , PIN1 , OUTPUT);
}
void HDCM_voidRotateClockWise()
{
	MDIO_voidSetPinValue(G_u8PortNum , PIN0 , HIGH);
	MDIO_voidSetPinValue(G_u8PortNum , PIN1 , LOW);
}
void HDCM_voidRotateAntiClockWise()
{
	MDIO_voidSetPinValue(PORTD , PIN0 , LOW);
	MDIO_voidSetPinValue(PORTD , PIN1 , HIGH);
}
