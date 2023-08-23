/*
 * UART.h
 *
 *  Created on: Aug 23, 2023
 *      Author: lenovo
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../../Lib/STD_Types.h"

void MUART_voidInit();
void MUART_voidTransmitData(u8 A_u8Data);
u8 MUART_u8RecieveData ();
void MUART_voidSetBaudRate(u32 A_u32BaudRate);

void MUART_voidSendString (u8 *A_StrPtr);
u8* MUART_voidRecieveString ();

void MUART_voidSendNumber(u32 A_u32Number);
#endif /* MCAL_UART_UART_H_ */
