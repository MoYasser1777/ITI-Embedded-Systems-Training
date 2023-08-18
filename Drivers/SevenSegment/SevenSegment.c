/*
 * SevenSegment.c
 *
 *  Created on: Aug 13, 2023
 *      Author: lenovo
 */

#include "SevenSegment.h"
#include "SevenSegment_config.h"
#include "../../Lib/defines.h"
u8 G_NumArr[10]={
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01101101,
		0b11111101,
		0b00000111,
		0b01111111,
		0b11101111,
};

void H7seg_InitPort(u8 A_u8PortNum)
{
	MDIO_voidSetPortDirection(A_u8PortNum,OUTPUT);
}

void H7seg_voidDisplayNum(u8 A_u8PortNum,u8 A_u8Num)
{
	if (A_u8Num<=9){
#if SSD_Type==0
	MDIO_voidSetPortValue(A_u8PortNum,G_NumArr[A_u8Num]);
#elif SSD_Type==1
	MDIO_voidSetPortValue(A_u8PortNum,~G_NumArr[A_u8Num]);
#endif
	}
}

void H7seg_voidCountUp(u8 A_u8PortNum,u8 A_u8Num) //starts from Num
{
	for (u8 counter=A_u8Num; counter<=nine; counter++)
	{
		MDIO_voidSetPortValue(A_u8PortNum,G_NumArr[counter]);
		_delay_ms(1000);
		if (counter==9)
			counter=A_u8Num-1;
	}
}
void H7seg_voidTurnOff(u8 A_u8PortNum){

#if SSD_Type==0
	MDIO_voidSetPortValue(A_u8PortNum,0x00);
#elif SSD_Type==1
	MDIO_voidSetPortValue(A_u8PortNum0xff);
#endif

}

void H7seg_voidCountDown(u8 A_u8PortNum,u8 A_u8Num) //starts from Num
{
	for (u8 counter=A_u8Num; counter>=zero; counter--)
		{
			MDIO_voidSetPortValue(A_u8PortNum,G_NumArr[counter]);
			_delay_ms(1000);
			if (counter==0)
				counter=A_u8Num+1;
		}
}

void H7seg_voidStartClock()
{
    u8 L_u8Seconds = 0;
    u8 L_u8Minutes = 0;
    u8 L_u8Hours = 0;

    while (1)
    {
        u8 hours_left = L_u8Hours / 10;
        u8 hours_right = L_u8Hours % 10;
        u8 min_left = L_u8Minutes / 10;
        u8 min_right = L_u8Minutes % 10;

        H7seg_voidDisplayNum(PORTA, hours_left);
        H7seg_voidDisplayNum(PORTB, hours_right);
        H7seg_voidDisplayNum(PORTC, min_left);
        H7seg_voidDisplayNum(PORTD, min_right);

        if (L_u8Seconds % 2 == 0)
                {
                    MDIO_voidSetPinValue(PORTA, PIN7, HIGH); // Turn on the LED
                }
                else
                {
                	MDIO_voidSetPinValue(PORTA, PIN7, LOW);  // Turn off the LED
                }

        L_u8Seconds++;

        if (L_u8Seconds >= 60)
        {
            L_u8Seconds = 0;
            L_u8Minutes++;

            if (L_u8Minutes >= 60)
            {
                L_u8Minutes = 0;
                L_u8Hours++;

                if (L_u8Hours >= 24)
                {
                    L_u8Hours = 0;
                }
            }
        }

        _delay_ms(1000);
    }
}
