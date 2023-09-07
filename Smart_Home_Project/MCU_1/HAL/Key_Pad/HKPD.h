/*
 * HKPD.h
 *
 *  Created on: 15 Aug 2023
 *      Author: ehab
 */

#ifndef HAL_KEY_PAD_HKPD_H_
#define HAL_KEY_PAD_HKPD_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../MCAL/MDIO/MDIO.h"

//Choose port
#define HKPD_PORT MDIO_PORTC

// Macros
#define PRESSED       (u8)0x00
#define UNPRESSED     (u8)0x01

// FUNCTIONS PROTOTYPES
void HKPD_voidInit();
u8 HKPD_U8PressedKey();


#endif /* HAL_KEY_PAD_HKPD_H_ */
