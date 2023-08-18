/*
 	 * DIO.h
 *
 *  Created on: Aug 11, 2023
 *      Author: lenovo
 */
#include "STD_Types.h"
#include "Bit_Maths.h"
#include "defines.h"

#ifndef DIO_H_
#define DIO_H_

void MDIO_voidSetPinDirection(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinDirection);
void MDIO_voidSetPinValue(u8 A_u8PortNum,u8 A_u8PinNum,u8 A_u8PinValue);
u8 MDIO_u8GetPinValue(u8 A_u8PortNum,u8 A_u8PinNum);

void MDIO_voidSetPortDirection(u8 A_u8PortNum,u8 A_u8PortDirection);
void MDIO_voidSetPortValue(u8 A_u8PortNum,u8 A_u8PortValue);

#endif /* DIO_H_ */
