/*
 * KeyPad.h
 *
 *  Created on: Aug 14, 2023
 *      Author: lenovo
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>

u8 G_u8PortNum;


void HKPD_voidInit(u8 A_u8PortNum);
u8 HKPD_u8GetKeyPressed();

#endif /* HAL_KEYPAD_KEYPAD_H_ */
