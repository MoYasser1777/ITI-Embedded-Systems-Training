#include "../Lib/STD_Types.h"
#include <avr/io.h>
#include "../MCAL/ADC/ADC.h"
#include <util/delay.h>

int main ()
{
	DDRD=0xff;
	MADC_voidInit();
	while(1)
	{
		PORTD=MADC_u16ConvertToDigital(0);
		_delay_ms(500);
	}
}
