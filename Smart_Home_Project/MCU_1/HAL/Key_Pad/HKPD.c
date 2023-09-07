/*
 * HKPD.c
 *
 *  Created on: 15 Aug 2023
 *      Author: ehab
 */

#include "HKPD.h"

// KPD_Array
static const u8 GKPD_u8NUM[4][4]={{'7','8','9','/'},
								  {'4','5','6','*'},
								  {'1','2','3','-'},
								  {'C','0','=','+'}
};


void HKPD_voidInit()
{
	MDIO_voidSetPortDirection(HKPD_PORT,0x0F);
	MDIO_voidSetPortValue(HKPD_PORT,0xFF);
}


u8 HKPD_U8PressedKey()
{
	u8 L_u8ButtonValue=3;
	u8 L_u8ButtonNO=' ';

	for(u8 row=0;row<4;row++)
	{
		MDIO_voidSetPinValue(HKPD_PORT,row,LOW);

		for(u8 col=0;col<4;col++)
		{
			L_u8ButtonValue=MDIO_U8ReadPinValue(HKPD_PORT,col+4);

			if(L_u8ButtonValue == PRESSED)
			{
				L_u8ButtonNO=GKPD_u8NUM[row][col];

				break;
			}
		}
		MDIO_voidSetPinValue(HKPD_PORT,row,HIGH);

		if(L_u8ButtonValue == PRESSED)
			break;

	}return L_u8ButtonNO;
}
