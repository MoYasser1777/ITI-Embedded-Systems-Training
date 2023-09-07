#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/STD_Macros.h"

#include "../MCAL/MDIO/MDIO.h"
#include "../MCAL/ADC/ADC_Init.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/TIMERS/Timer_Init.h"



volatile u8 read = 8 ;

volatile u8 Sensed_Temp ;
volatile u8 Desired_Temp ;

int main()
{
	/* Room1 PINS */
	MDIO_voidSetPinDirection(MDIO_PORTA , PIN0 , OUTPUT) ; // Light
	MDIO_voidSetPinDirection(MDIO_PORTA , PIN1 , OUTPUT) ; // Fan Speed High
	MDIO_voidSetPinDirection(MDIO_PORTA , PIN2 , OUTPUT) ; // Fan Speed MID
	MDIO_voidSetPinDirection(MDIO_PORTA , PIN3 , OUTPUT) ; // Fan Speed Low
	MDIO_voidSetPinDirection(MDIO_PORTA , PIN4 , OUTPUT) ; // TV

	/* 	Room2 PINS */
	MDIO_voidSetPinDirection(MDIO_PORTA , PIN5 , OUTPUT) ; // Light
	MDIO_voidSetPinDirection(MDIO_PORTA , PIN6 , INPUT) ;  // Temp Sensor
	MDIO_voidSetPinDirection(MDIO_PORTA , PIN7 , OUTPUT) ; // A/C LED

	/* Bathroom PINS */
	MDIO_voidSetPinDirection(MDIO_PORTC , PIN0 , OUTPUT) ; // Light
	MDIO_voidSetPinDirection(MDIO_PORTC , PIN1 , OUTPUT) ; // Fan
	MDIO_voidSetPinDirection(MDIO_PORTC , PIN2 , OUTPUT) ; // Heater

	/*MCU2 initialization as a slave*/
	SPI_voidInitSlave();

	/*ADC initialization*/
	MADC_VoidADCInit();

    while (1)
    {
    	/*Recieve instruction as a character from Master*/
    	read = SPI_u8Receive();

		switch (read)
		{
			/* Room 1 ---> Port A */

			case '0': MDIO_voidSetPinValue(MDIO_PORTA , PIN0 , HIGH) ; break;  //light on
			case '1': MDIO_voidSetPinValue(MDIO_PORTA , PIN0 , LOW) ; break;  //light off

			case 'L':														   //fan low speed
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN1 , LOW) ;
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN2 , LOW) ;
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN3 , HIGH) ;
					 break;
			case 'M':														   //fan mideum speed

					 MDIO_voidSetPinValue(MDIO_PORTA , PIN1 , LOW) ;
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN2 , HIGH) ;
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN3 , LOW) ;
					 break;
			case 'H':														   //fan high speed
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN1 , HIGH) ;
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN2 , LOW) ;
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN3 , LOW) ;
					 break;
			case 'S':														   //fan stop
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN1 , LOW) ;
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN2 , LOW) ;
					 MDIO_voidSetPinValue(MDIO_PORTA , PIN3 , LOW) ;
					 break;

			case '2': MDIO_voidSetPinValue(MDIO_PORTA , PIN4 , HIGH); break;   //tv on
			case 'T': MDIO_voidSetPinValue(MDIO_PORTA , PIN4 , LOW); break;   //tv off

			/* Room 2 ---> Port A */

			case '3': MDIO_voidSetPinValue(MDIO_PORTA , PIN5 , HIGH); break;   //light on
			case '4': MDIO_voidSetPinValue(MDIO_PORTA , PIN5 , LOW); break;   //light off

			case 15 ... 40 :                                                   //a/c
				Desired_Temp = read ;
				Sensed_Temp = (MADC_U16AnalogRead(6)) * 0.5 ;
				if(Sensed_Temp > Desired_Temp)
				{
					MDIO_voidSetPinValue(MDIO_PORTA , PIN7 , HIGH);
				}
				else
				{
					MDIO_voidSetPinValue(MDIO_PORTA , PIN7 , LOW);
				}
				break;

			/* Bathroom ---> Port C */

			case '6': MDIO_voidSetPinValue(MDIO_PORTC , PIN0 , HIGH); break;  //light on
			case '5': MDIO_voidSetPinValue(MDIO_PORTC , PIN0 , LOW); break;  //light off

			case '7': MDIO_voidSetPinValue(MDIO_PORTC , PIN1 , HIGH); break;  //motor on
			case 'W': MDIO_voidSetPinValue(MDIO_PORTC , PIN1 , LOW); break;  //motor off

			case '8': MDIO_voidSetPinValue(MDIO_PORTC , PIN2 , HIGH); break;  //heater on
			case 'X': MDIO_voidSetPinValue(MDIO_PORTC , PIN2 , LOW); break;  //heater off

		}

		// Process received character as needed
		read = ' ';
    }

    return 0;
}
