#include "SevenSegment.h"

#define DIO_PORTA_REG *((volatile u8*) 0X3B)
#define DIO_DDRA_REG *((volatile u8*) 0X3A)
#define DIO_PINA_REG *((volatile u8*) 0X39)

#define DIO_PORTB_REG *((volatile u8*) 0X38)
#define DIO_DDRB_REG *((volatile u8*) 0X37)
#define DIO_PINB_REG *((volatile u8*) 0X36)

#define DIO_PORTC_REG *((volatile u8*) 0X35)
#define DIO_DDRC_REG *((volatile u8*) 0X34)
#define DIO_PINC_REG *((volatile u8*) 0X33)

#define DIO_PORTD_REG *((volatile u8*) 0X32)
#define DIO_DDRD_REG *((volatile u8*) 0X31)
#define DIO_PIND_REG *((volatile u8*) 0X30)

void M7Seg_voidSevenSegment (u8 A_u8PortNum,u8 A_u8number)
{
	if (A_u8PortNum<=PORTD)
	{
	switch(A_u8number)
	{
			case 0: MDIO_voidSetPortValue(A_u8PortNum,0b00111111); break;
			case 1: MDIO_voidSetPortValue(A_u8PortNum,0b00000110); break;
			case 2: MDIO_voidSetPortValue(A_u8PortNum,0b01011011); break;
			case 3: MDIO_voidSetPortValue(A_u8PortNum,0b01001111); break;
			case 4: MDIO_voidSetPortValue(A_u8PortNum,0b01100110); break;
			case 5: MDIO_voidSetPortValue(A_u8PortNum,0b01101101); break;
			case 6: MDIO_voidSetPortValue(A_u8PortNum,0b11111101); break;
			case 7: MDIO_voidSetPortValue(A_u8PortNum,0b00000111); break;
			case 8: MDIO_voidSetPortValue(A_u8PortNum,0B01111111); break;
			case 9: MDIO_voidSetPortValue(A_u8PortNum,0b11101111); break;
	}
	}
}

