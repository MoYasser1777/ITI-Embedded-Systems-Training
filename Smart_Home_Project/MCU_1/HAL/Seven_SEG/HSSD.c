/*
 * HSSD.c
 *
 *  Created on: 13 Aug 2023
 *      Author: ehab
 */

// SSD: Seven Segment Display

#include "HSSD.h"

/* Following This Table For Common Cathode */
/***********************************************/
/* Decimal | Dot | g | f | e | d | c | b | a | */
/*    0    |  0  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    1    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 0 | */
/*    2    |  0  | 1 | 0 | 1 | 1 | 0 | 1 | 1 | */
/*    3    |  0  | 1 | 0 | 0 | 1 | 1 | 1 | 1 | */
/*    4    |  0  | 1 | 1 | 0 | 0 | 1 | 1 | 0 | */
/*    5    |  0  | 1 | 1 | 0 | 1 | 1 | 0 | 1 | */
/*    6    |  0  | 1 | 1 | 1 | 1 | 1 | 0 | 1 | */
/*    7    |  0  | 0 | 0 | 0 | 0 | 1 | 1 | 1 | */
/*    8    |  0  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | */
/*    9    |  0  | 1 | 1 | 0 | 1 | 1 | 1 | 1 | */
/***********************************************/

// Seven_SEG ARRAY
static const u8 G_u8NUMs[]={
		0x3f, // zero     (0)
		0x06, // one      (1)
		0x5b, // two      (2)
		0x4f, // three    (3)
		0x66, // four     (4)
		0x6d, // five     (5)
		0x7d, // six      (6)
		0x47, // seven    (7)
		0x7f, // eight    (8)
		0x6f, // nine     (9)
		0x77, // ten      (A=10)
		0x7f, // eleven   (B=11)
		0x39, // twelve   (C=12)
		0x3f, // thirteen (D=13)
		0x79, // fourteen (E=14)
		0x71};// fifteen  (F=15)




void HSSD_voidInit(port A_PortName)
{
	MDIO_voidSetPortDirection(A_PortName,0xFF);
}


void HSSD_voidDisplayNUM(port A_PortName,u8 A_u8NUM)
{
	#ifdef COM_Cathode
		MDIO_voidSetPortValue(A_PortName,G_u8NUMs[A_u8NUM]);
	#elif COM_Anode
		MDIO_voidSetPortValue(A_PortName,~G_u8NUMs[A_u8NUM]);
	#endif

}

void HSSD_voidTurnOff(port A_PortName)
{
	#ifdef COM_Cathode
		MDIO_voidSetPortValue(A_PortName,0x00);
	#elif COM_Anode
		MDIO_voidSetPortValue(A_PortName,0xFF);
	#endif
}

void HSSD_voidCountUP(port A_PortName,u8 A_u8NUM)
{
	for(u8 counter=A_u8NUM;counter<=9 ;counter++)
	{
		HSSD_voidDisplayNUM(A_PortName,counter);
		_delay_ms(1000);
	}
}

void HSSD_voidCountDown(port A_PortName,u8 A_u8NUM)
{
	for(u8 counter=A_u8NUM;counter>=0 ;counter--)
	{
		HSSD_voidDisplayNUM(A_PortName,counter);
		_delay_ms(1000);
	}
}












