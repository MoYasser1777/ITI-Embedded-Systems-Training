/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: lenovo
 */

#include "../HAL/SevenSegment/SevenSegment.h"
#include <util/delay.h>


int main ()
{
	//To start clock use 4 ports for the four 7-segments
    //PORTA-->HL
	//PORTB-->HR
	//PORTC-->ML
	//PORTD-->MR

	H7seg_InitPort(PORTA);
	H7seg_InitPort(PORTB);
	H7seg_InitPort(PORTC);
	H7seg_InitPort(PORTD);
//	MDIO_voidSetPinDirection(PORTA,PIN7,OUTPUT);
//	MDIO_voidSetPinValue(PORTA,PIN7,HIGH);
//	_delay_ms(1000);

	while (1)
	{
//		H7seg_voidCountUp(PORTB,0);
//		_delay_ms(1000);
//
//		H7seg_voidCountDown(PORTB,9);
//		_delay_ms(1000);
		H7seg_voidStartClock();

//		MDIO_voidTogglePin(PORTA,PIN7);
//		_delay_ms(1000);
//		MDIO_voidTogglePin(PORTA,PIN7);
//		_delay_ms(1000);
	}
	return 0;
}
