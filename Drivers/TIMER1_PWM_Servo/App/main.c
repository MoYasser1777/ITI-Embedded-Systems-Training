#include "../Lib/STD_Types.h"
#include "../Lib/defines.h"
#include "../MCAL/EXT_INT/GIE.h"
#include "../MCAL/TIMER1_PWM/TIMER1_PWM.h"
#include "../MCAL/DIO/DIO.h"
#include <util/delay.h>

int main()
{
    MDIO_voidSetPinDirection(PORTD, PIN5, HIGH);

    MTIMR1_voidTimer1Init();
    MTIMR1_voidSetICR(20000);

    while (1)
    {
        for (u16 i = 1000; i <= 2000; i+=10)
        {
            MTIMR1_voidTimer1SetCompMatchA(i);
            _delay_ms(100);
        }

        _delay_ms(1000);

        for (u16 i = 2000; i >= 1000; i-=10)
        {
            MTIMR1_voidTimer1SetCompMatchA(i);
            _delay_ms(100);
        }

        _delay_ms(1000);
    }

    return 0;
}
