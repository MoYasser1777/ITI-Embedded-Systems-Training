#include "../HAL/DC_Motor/DC_Motor.h"
#include <util/delay.h>
#include "../Lib/STD_Types.h"
#include "../Lib/defines.h"

int main()
{
	HDCM_voidInitPort(PORTD);
		while(1)
		{
			HDCM_voidRotateClockWise();
			_delay_ms(3000);
			HDCM_voidRotateAntiClockWise();
			_delay_ms(3000);
		}
    return 0;
}
