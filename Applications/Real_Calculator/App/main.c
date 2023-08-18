#include "../HAL/LCD/LCD.h"
#include "../HAL/KeyPad/KeyPad.h"
#include <util/delay.h>
#include "../Lib/STD_Types.h"
#include "../Lib/defines.h"

int main()
{
    HLCD_void8bitInit();
    HKPD_voidInit(PORTC);  // Keypad

    u8 L_u8PressedKey = ' ';
    s32 L_u16op1 = 0;
    s32 L_u16op2 = 0;
    u8 L_u8operator = ' ';
    s32 L_u16res = 0;
    u8 flag = 0;

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
                    HLCD_voidClear();
                    HLCD_voidSetCursor(1, 1);
                    HLCD_voidDisplayNum(L_u16op1);
                }
                else
                {
                    L_u16op2 = (L_u16op2 * 10) + (L_u8PressedKey - '0');
                    HLCD_voidClear();
                    HLCD_voidSetCursor(1, 1);
                    HLCD_voidDisplayNum(L_u16op1);
                    HLCD_voidSetCursor(1, 7);
                    HLCD_voidDisplayChar(L_u8operator);
                    HLCD_voidSetCursor(1, 9);
                    HLCD_voidDisplayNum(L_u16op2);
                }
            }
            else if (L_u8PressedKey == 'c')
            {
                L_u16op1 = 0;
                L_u16op2 = 0;
                L_u8operator = ' ';
                L_u16res = 0;
                flag = 0;
                HLCD_voidClear();
            }
            else if (L_u8PressedKey == '+' || L_u8PressedKey == '-' || L_u8PressedKey == '*' || L_u8PressedKey == '/')
            {
                L_u8operator = L_u8PressedKey;
                HLCD_voidClear();
                HLCD_voidSetCursor(1, 1);
                HLCD_voidDisplayNum(L_u16op1);
                HLCD_voidSetCursor(1, 7);
                HLCD_voidDisplayChar(L_u8operator);
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
                HLCD_voidClear();
                HLCD_voidSetCursor(1, 1);
                HLCD_voidDisplayNum(L_u16op1);
                HLCD_voidSetCursor(1, 7);
                HLCD_voidDisplayChar(L_u8operator);
                HLCD_voidSetCursor(1, 9);
                HLCD_voidDisplayNum(L_u16op2);
                HLCD_voidSetCursor(2, 1);
                HLCD_voidDisplayChar('=');
                HLCD_voidSetCursor(2, 3);
                HLCD_voidDisplayNum(L_u16res);

                L_u16op1 = L_u16res;
                L_u16op2 = 0;
                L_u8operator = ' ';
                flag = 1;
            }
        }
    }

    return 0;
}
