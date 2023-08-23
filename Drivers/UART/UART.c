/*
 * UART.c
 *
 *  Created on: Aug 23, 2023
 *      Author: lenovo
 */
#include "UART.h"
#include "UART_private.h"
#include "UART_config.h"
#include "../../Lib/Bit_Maths.h"

void MUART_voidInit()
{
	/* Enable RX and TX */
		SET_BIT(UCSRB , UCSRB_RXEN);
		SET_BIT(UCSRB , UCSRB_TXEN);

		/* Set to 8 bit mode
		 * No parity
	 	 * One stop bit */
		UCSRC = 0b10000110  ;

		/* Set buad rate to 9600 */
		UBRRL = 51 ;
}
void MUART_voidTransmitData(u8 A_u8Data)
{
	//wait for empty transmit buffer
	while (GET_BIT(UCSRA , UCSRA_UDRE) == 0){}

	//put data into the buffer (send data)
	UDR = A_u8Data ;
}
u8 MUART_u8RecieveData ()
{
	//wait for data to be recieved
	while (GET_BIT(UCSRA , UCSRA_RXC) == 0){}

	//get and return the return data from buffer
	return UDR ;

}
void MUART_voidSetBaudRate(u32 A_u32BaudRate)
{
	UBRRL=A_u32BaudRate;
}

void MUART_voidSendString (u8 *A_StrPtr)
{
	while (*A_StrPtr != '\0')
		{
		MUART_voidTransmitData(*A_StrPtr);
		A_StrPtr++;
		}
}
u8* MUART_voidRecieveString ()
{
	u8 ReceivedString[50]; // max length=50 chars
	u8 i = 0;
	u8 ReceivedChar;

	do {
		ReceivedChar = MUART_u8RecieveData();

		if (ReceivedChar != '\r' && ReceivedChar != '\n')
		{
			ReceivedString[i] = ReceivedChar;
			i++;
		}
	} while (ReceivedChar != '\r');

	ReceivedString[i] = '\0';
	return ReceivedString;
}

void MUART_voidSendNumber(u32 A_u32Number)
{
	if (A_u32Number == 0) {
	        MUART_voidTransmitData('0');
	        return;
	    }

	    u8 NumberString[11];
	    u8 i = 0;

	    while (A_u32Number > 0) {
	        u8 digit = A_u32Number % 10;
	        NumberString[i] = digit + '0';
	        A_u32Number /= 10;
	        i++;
	    }

	    while (i > 0) {
	        i--;
	        MUART_voidTransmitData(NumberString[i]);
	    }
}
