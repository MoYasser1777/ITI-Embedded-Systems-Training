#include "../MCAL/EXT_INT/EXT_INT.h"
#include "../MCAL/EXT_INT/GIE.h"
#include "../MCAL/DIO/DIO.h"

volatile u8 global_u8Flag;

int main() {

	MDIO_voidSetPinDirection(PORTD,PIN2, INPUT);
	MDIO_voidSetPinDirection(PORTD,PIN0, OUTPUT);
	MDIO_voidSetPinValue(PORTD, PIN2, HIGH);

	MGIR_voidEnable();
	MEXTINT_voidSenseControl(EXTINT_Int0, EXTINT_SenseControl_FallingEdge);

	MEXTINT_voidEnableInt(EXTINT_Int0);


	while(1){}

	return 0;

}



void __vector_1 (void) __attribute__ ((signal));

void __vector_1 (void)
{
	if (global_u8Flag==0)
		{
			MDIO_voidSetPinValue(PORTD,PIN0,LOW);
			global_u8Flag=1;
		}
		else
		{
			MDIO_voidSetPinValue(PORTD,PIN0,HIGH);
			global_u8Flag=0;
		}
}
