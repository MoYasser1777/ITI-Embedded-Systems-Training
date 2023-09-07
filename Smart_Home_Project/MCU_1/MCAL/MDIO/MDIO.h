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

typedef enum
{
	MDIO_PORTA=0,
	MDIO_PORTB,
	MDIO_PORTC,
	MDIO_PORTD,
}port;

typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}pin;


// FUNCTIONS PROTOTYPES

void MDIO_voidSetPinDirection             (port A_PortName,pin A_PinNO,u8 A_u8Direction);
void MDIO_voidSetPinValue                 (port A_PortName,pin A_PinNO,u8 A_u8Value);
u8 MDIO_U8ReadPinValue                    (port A_PortName,pin A_PinNO);
void MDIO_voidTogglePinValue              (port A_PortName,pin A_PinNO);

void MDIO_voidSetPortDirection            (port A_PortName,u8 A_u8PortDirection);
void MDIO_voidSetPortValue                (port A_PortName,u8 A_u8PortValue);
u8 MDIO_U8ReadPortValue                   (port A_PortName);

void MDIO_voidSetLowNibbleDirection       (port A_PortName);
void MDIO_voidSetHighNibbleDirection      (port A_PortName);
void MDIO_voidSetLowNibble                (port A_PortName,u8 A_u8Value);
void MDIO_voidSetHighNibble               (port A_PortName,u8 A_u8Value);


#endif /* MDIO_H_ */
