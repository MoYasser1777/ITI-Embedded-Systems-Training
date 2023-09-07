#include "../Lib/STD_Types.h"
#include "../Lib/defines.h"
#include "../MCAL/EXT_INT/GIE.h"
#include "../MCAL/TIMER/Timer.h"
#include "../MCAL/DIO/DIO.h"
#include <util/delay.h>


void PWM_Control0(void)
{
}


int main()
{


		MGIR_voidEnable();

		//Timer 0
	    MTIMER_voidInit(0);

	    MTIMER_voidEnable(0);

	    MDIO_voidSetPinDirection(PORTB, PIN3, OUTPUT);

	    MTimer_voidSetCallBack(0, PWM_Control0);

	    MTIMER_voidStart(0);


	    while (1)
	    {
	    	for (u8 i=1; i<255; i++)
	    			{
	    				MTIMR_voidSetCompareMatch(0, i);
	    				_delay_ms(200);
	    			}
	    		 _delay_ms(500);
	    		 for (u8 i=255; i>0; i--)
	    			{
	    				MTIMR_voidSetCompareMatch(0, i);
	    				_delay_ms(200);
	    			}
	    		 _delay_ms(500);
	    }

	    return 0;
}


