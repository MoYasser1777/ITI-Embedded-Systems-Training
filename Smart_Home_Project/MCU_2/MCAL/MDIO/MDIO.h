/*
 * MDIO.h
 *
 *  Created on: 11 Aug 2023
 *      Author: ehab
 */

#ifndef MDIO_H_
#define MDIO_H_

#include "../../LIB/Memory_Map.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/STD_Macros.h"

#define MDIO_PORTA  0
#define MDIO_PORTB  1
#define MDIO_PORTC  2
#define MDIO_PORTD  3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


// FUNCTIONS PROTOTYPES

void MDIO_voidSetPinDirection             (u8 A_PortName, u8 A_PinNO,u8 A_u8Direction);
void MDIO_voidSetPinValue                 (u8 A_PortName,u8 A_PinNO,u8 A_u8Value);
u8 MDIO_U8ReadPinValue                    (u8 A_PortName,u8 A_PinNO);
void MDIO_voidTogglePinValue              (u8 A_PortName,u8 A_PinNO);

void MDIO_voidSetPortDirection            (u8 A_PortName,u8 A_u8PortDirection);
void MDIO_voidSetPortValue                (u8 A_PortName,u8 A_u8PortValue);
u8 MDIO_U8ReadPortValue                   (u8 A_PortName);

void MDIO_voidSetLowNibbleDirection       (u8 A_PortName);
void MDIO_voidSetHighNibbleDirection      (u8 A_PortName);
void MDIO_voidSetLowNibble                (u8 A_PortName,u8 A_u8Value);
void MDIO_voidSetHighNibble               (u8 A_PortName,u8 A_u8Value);


#endif /* MDIO_H_ */
