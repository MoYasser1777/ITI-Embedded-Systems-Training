#include "../HAL/SevenSegment/SevenSegment.h"
#include "../HAL/Keypad/Keypad.h"
#include <util/delay.h>

int main()
{
    H7seg_InitPort(PORTB); // 10
    H7seg_InitPort(PORTC); // 1
    H7seg_InitPort(PORTD); // 100
    HKPD_voidInit(PORTA);  // kPad

    u8 L_u8PressedKey = ' ';
    u16 L_u16op1 = 0;
    u16 L_u16op2 = 0;
    u8 L_u8operator = ' ';
    u16 L_u16res = 0;
    u8 flag = 0;

    H7seg_voidDisplayNum(PORTD, zero);
    H7seg_voidDisplayNum(PORTB, zero);
    H7seg_voidDisplayNum(PORTC, zero);
    _delay_ms(100);

    while (1)
    {
        L_u8PressedKey = HKPD_u8GetKeyPressed();

        if (L_u8PressedKey != ' ')
        {
            if (L_u8PressedKey >= '0' && L_u8PressedKey <= '9')
            {
                if (L_u8operator == ' ' && !flag)
                {
                    L_u16op1 = (L_u16op1 * 10) + (L_u8PressedKey - '0');
                    H7seg_voidDisplayNum(PORTD, L_u16op1 / 100);
                    H7seg_voidDisplayNum(PORTB, (L_u16op1 / 10) % 10);
                    H7seg_voidDisplayNum(PORTC, L_u16op1 % 10);
                }
                else
                {
                	 H7seg_voidDisplayNum(PORTD, zero);
					 H7seg_voidDisplayNum(PORTB, zero);
					 H7seg_voidDisplayNum(PORTC, zero);
                    L_u16op2 = (L_u16op2 * 10) + (L_u8PressedKey - '0');
                    H7seg_voidDisplayNum(PORTD, L_u16op2 / 100);
                    H7seg_voidDisplayNum(PORTB, (L_u16op2 / 10) % 10);
                    H7seg_voidDisplayNum(PORTC, L_u16op2 % 10);
                }
            }
            else if (L_u8PressedKey == 'c')
            {
                L_u16op1 = 0;
                L_u16op2 = 0;
                L_u8operator = ' ';
                L_u16res = 0;
                flag = 0;
                H7seg_voidDisplayNum(PORTD, zero);
                H7seg_voidDisplayNum(PORTB, zero);
                H7seg_voidDisplayNum(PORTC, zero);
            }
            else if (L_u8PressedKey == '+' || L_u8PressedKey == '-' || L_u8PressedKey == '*' || L_u8PressedKey == '/')
            {
                L_u8operator = L_u8PressedKey;
            }
            else if (L_u8PressedKey == '=')
            {
                switch (L_u8operator)
                {
                case '+':
                    L_u16res = L_u16op1 + L_u16op2;
                    break;
                case '-':
                    L_u16res = L_u16op1 - L_u16op2;
                    break;
                case '*':
                    L_u16res = L_u16op1 * L_u16op2;
                    break;
                case '/':
                    if (L_u16op2 != 0)
                    {
                        L_u16res = L_u16op1 / L_u16op2;
                    }
                    break;
                }

                H7seg_voidDisplayNum(PORTD, L_u16res / 100);
                H7seg_voidDisplayNum(PORTB, (L_u16res / 10) % 10);
                H7seg_voidDisplayNum(PORTC, L_u16res % 10);

                L_u16op1 = L_u16res;
                L_u16op2 = 0;
                L_u8operator = ' ';
                flag = 1;
            }
        }
    }

    return 0;
}
