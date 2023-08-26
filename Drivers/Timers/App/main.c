#include <util/delay.h>
#include "../Lib/STD_Types.h"
#include "../Lib/defines.h"
#include "../MCAL/EXT_INT/GIE.h"
#include "../MCAL/TIMER/Timer.h"
#include "../MCAL/DIO/DIO.h"

#define F_CPU 8000000

volatile u8 led=1;



void Toggle_Led (void)
{
	led = !led ;
	MDIO_voidSetPinValue(PORTD,PIN0,led);

}

int main()
{
	    MDIO_voidSetPortDirection(PORTD,OUTPUT);
	    MDIO_voidSetPinValue(PORTD,PIN0,led);

	    MGIR_voidEnable();

	    //toggle led every 1 second
	    MTIMER_voidSetPreLoad(184);
	    MTIMER_voidSetCounts(489);

	    MTIMER_voidEnable(0);
	    MTimer_voidSetCallBack(0,Toggle_Led);
	    MTIMER_voidInit_start();

		while(1)
		{
		}

    return 0;
}
