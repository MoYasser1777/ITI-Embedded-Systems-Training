/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: lenovo
 */

#include "DIO.h"
#include "SevenSegment.h"
#include "util/delay.h"
#include <stdio.h>

int main()
{

	MDIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	MDIO_voidSetPortDirection(PORTB,OUTPUT);
    u8 i=0;
	while(1)
	{
		if (i==10)
			i=0;
		M7Seg_voidSevenSegment(PORTB,i);
		MDIO_voidSetPinValue(PORTA,PIN0,HIGH);
		_delay_ms(1000);
		MDIO_voidSetPinValue(PORTA,PIN0,LOW);
		_delay_ms(1000);
		i++;
	}
	return 0;
}

