#include "../HAL/LCD/LCD.h"
#include <util/delay.h>

int main()
{
	ay_HLCD_void8bitInit();
	HLCD_voidSendString("Test");
	_delms(200);
	HLCD_voidSetCursor(2,1);
	HLCD_voidSendString("Test2");
    while (1)
    {}
    return 0;
}
