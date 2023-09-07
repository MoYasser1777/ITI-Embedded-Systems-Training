#include <util/delay.h>

#include "../LIB/STD_Types.h"
#include "../LIB/STD_Macros.h"

#include "../MCAL/MDIO/MDIO.h"
#include "../MCAL/Timers/MTIMERS_Init.h"
#include "../MCAL/SPI/SPI.h"
#include "../HAL/Key_Pad/HKPD.h"
#include "../HAL/LCD/HLCD.h"

enum RoomComponentState {
    OFF,
    ON
};

enum RoomComponentState roomComponents[3][3] = {
    {OFF, OFF, OFF}, // Room 1
    {OFF, OFF, OFF}, // Room 2
    {OFF, OFF, OFF}  // Bathroom
};


int main()
{
    const u16 Password = 1234;
    /*
     User_Pass --> the password entered by the user
     Try_Again --> number of trials in case of wrong password
     */
    u16 User_Pass, Try_Again = 0;

    /*
     Temprature --> Temprature entered by the user
     Tempflag --> for checking number of digits of temprature
     */
	volatile u8 Temperature = 0 ,Tempflag  = 0;

	/*any pressed button by the user on the keypad*/
	volatile u8 L_u8PressedButton = ' ';

	/*for checking number of digits of password entered by the user*/
    u8 flag = 0;

    /*selected room by the user to control it*/
    u8 selectedRoom = 0;

    /*LCD,Keypad,Timer1 and SPI_Master initialization*/
    HLCD_voidInit();
    HKPD_voidInit();
    MTIMER1_voidInitFastPwm();
    SPI_voidInitMaster();

    /*buzzer pin*/
    MDIO_voidSetPinDirection(MDIO_PORTD, PIN3, OUTPUT);

    /*enterance light pin*/
    MDIO_voidSetPinDirection(MDIO_PORTA, PIN7, OUTPUT);


    HLCD_voidClear();
    HLCD_voidSendString("Welcome To ");
    HLCD_voidMoveCursor(LINE_2, 1);
    HLCD_voidSendString("Our Smart Home");
    _delay_ms(1000);


jump:
	 User_Pass = 0;
	 flag = 0;
	 Try_Again++;
    while(1)
    {
    	HLCD_voidClear();
        HLCD_voidSendString("Enter Password");
    	HLCD_voidMoveCursor(LINE_2, 1);
        while (1)
        {
            L_u8PressedButton = HKPD_U8PressedKey();

            if (L_u8PressedButton >= '0' && L_u8PressedButton <= '9')
            {
                flag++;
                User_Pass = (User_Pass * 10) + (L_u8PressedButton - '0');
                HLCD_voidSendData('*');
                _delay_ms(250);
            }

            if (flag == 4)
            {
                break;
            }
        }

        if ((User_Pass != Password) && (Try_Again < 3))
        {
            HLCD_voidClear();
            HLCD_voidSendString("Wrong Password");
            _delay_ms(1000);
            HLCD_voidClear();
            HLCD_voidSendString("Try again");
            _delay_ms(1000);
            goto jump;
        }
        else if ((User_Pass != Password) && (Try_Again == 3))
        {
            HLCD_voidClear();
            HLCD_voidSendString("No More Tries");
            _delay_ms(1000);
            HLCD_voidClear();
            HLCD_voidSendString("Alerts On");
            MDIO_voidSetPinValue(MDIO_PORTD, PIN3, HIGH); //buzzer on for wrong password 3 times
            _delay_ms(1000);
            break;
        }
        else if (User_Pass == Password)
        {

            HLCD_voidClear();
            HLCD_voidSendString("Welcome Home");
            _delay_ms(1000);

            HLCD_voidClear();
            MTIMER1_voidSetPinACompareMatch(1999);        //open the door
            HLCD_voidSendString("Door is opened");
            _delay_ms(500);

            HLCD_voidClear();
            MDIO_voidSetPinValue(MDIO_PORTA, PIN7, HIGH); //light system on
            HLCD_voidSendString("Light Sys ON");
            _delay_ms(500);

/*choose which room to control its components*/
 Rooms_Menu:
            HLCD_voidClear();
			HLCD_voidSendString("1.Room1 2.Room2");
			HLCD_voidMoveCursor(LINE_2, 1);
			HLCD_voidSendString("3.Bathroom");

            while (1)
            {
                L_u8PressedButton = HKPD_U8PressedKey();

                if (L_u8PressedButton >= '1' && L_u8PressedButton <= '3')
                {
                    selectedRoom = L_u8PressedButton - '0';
                    break;
                }
            }

/*select which component to control it*/
option_menu:   HLCD_voidClear();
			   switch (selectedRoom)
			   {
			   case 1:
				   HLCD_voidSendString("1.Light  2.Fan");
				   HLCD_voidMoveCursor(LINE_2, 1);
				   HLCD_voidSendString("3.TV    4.Back");
				   break;
			   case 2:
				   HLCD_voidSendString("1.Light  2.Back");
				   HLCD_voidMoveCursor(LINE_2, 1);
				   HLCD_voidSendString("3.Air Condition");
				   break;
			   case 3:
				   HLCD_voidSendString("1.Light  2.Motor");
				   HLCD_voidMoveCursor(LINE_2, 1);
				   HLCD_voidSendString("3.Heater 4.back");
				   break;

			   default:
				   break;
			   }

            while (1)
            {

                L_u8PressedButton = HKPD_U8PressedKey();

                if (L_u8PressedButton == '1')
                {
                	switch (selectedRoom)
                	{

                	case 1: roomComponents[0][0] = (roomComponents[selectedRoom - 1][0] == ON) ? OFF : ON; //room1 light
                            SPI_voidTransmit(roomComponents[0][0] ? '0' : '1');
                            break;
                	case 2: roomComponents[1][0] = (roomComponents[selectedRoom - 1][0] == ON) ? OFF : ON; //room2 light
                            SPI_voidTransmit(roomComponents[1][0] ? '3' : '4');
                            break;
                	case 3: roomComponents[2][0] = (roomComponents[selectedRoom - 1][0] == ON) ? OFF : ON; //room3 light
                            SPI_voidTransmit(roomComponents[2][0] ? '6' : '5');
                            break;
                	}
                	goto option_menu;
                }
                else if (L_u8PressedButton == '2')
                {
                	switch (selectedRoom)
					{
					case 1:                                                           		   //room1 fan
						   L_u8PressedButton = '9' ;
						   HLCD_voidClear();
						   HLCD_voidSendString("Control speed") ;
						   _delay_ms(250)  ;
						   HLCD_voidClear();
						   HLCD_voidSendString("1.L 2.M 3.H");
						   HLCD_voidMoveCursor(LINE_2, 1);
						   HLCD_voidSendString("4.Stop 5.back");
						   while(1)
						   {
						   L_u8PressedButton = ' ' ;
						   L_u8PressedButton = HKPD_U8PressedKey();
						   switch(L_u8PressedButton)
						   {
						   case '1' : SPI_voidTransmit('L')  ; break ;
						   case '2' : SPI_voidTransmit('M')  ; break ;
						   case '3' : SPI_voidTransmit('H')  ; break ;
						   case '4' : SPI_voidTransmit('S')  ; break ;
						   case '5' : goto option_menu       ; break ;
						   }
						   }
						   break;
					case 2:	goto Rooms_Menu; break;												//room2 back
					case 3: roomComponents[2][1] = (roomComponents[2][1] == ON) ? OFF : ON;		//room3 motor
							SPI_voidTransmit(roomComponents[2][1] ? '7' : 'W');
							break;
					}
                	goto option_menu;
                }
                else if (L_u8PressedButton == '3')
			   {
                	switch (selectedRoom)
					{
					case 1: roomComponents[0][2] = (roomComponents[0][2] == ON) ? OFF : ON;		//room1 tv
							SPI_voidTransmit(roomComponents[0][2] ? '2' : 'T');
							break;
					case 2:																		//room2 A/C
						Tempflag = 0 ;
						_delay_ms(100) ;
					    L_u8PressedButton = 'B' ;
					    HLCD_voidClear();
					    HLCD_voidSendString("Set Temperature:");
					    HLCD_voidMoveCursor(LINE_2, 7);
					    while (1)
					    {
					    	L_u8PressedButton = HKPD_U8PressedKey();

					    	if (L_u8PressedButton >= '0' && L_u8PressedButton <= '9')
					    	{
					    		Tempflag++;
					    		HLCD_voidSendData(L_u8PressedButton);
					    		Temperature = (Temperature*10) + (L_u8PressedButton - '0');
					    		_delay_ms(250);
					    	}
					    	if (Tempflag == 2)
					    	{
					    		HLCD_voidClear();
					    		HLCD_voidSendString("Temperature sent");
					    		_delay_ms(500);
					    		HLCD_voidClear();
					    		break;
					    	}
					    }
					    SPI_voidTransmit(Temperature); break;
					case 3: roomComponents[2][2] = (roomComponents[2][2] == ON) ? OFF : ON;			//room3 heater
							SPI_voidTransmit(roomComponents[2][2] ? '8' : 'X');
							break;
					}
                	goto option_menu;
			   }
                else if (L_u8PressedButton == '4')													//back to rooms selection
				{
					goto Rooms_Menu;
				}
            }
        }
    }
    return 0;
}
