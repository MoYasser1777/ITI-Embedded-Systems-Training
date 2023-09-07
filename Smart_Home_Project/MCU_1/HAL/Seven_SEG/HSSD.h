/*
 * HSSD.h
 *
 *  Created on: 13 Aug 2023
 *      Author: ehab
 */

#ifndef HAL_SEVEN_SEG_HSSD_H_
#define HAL_SEVEN_SEG_HSSD_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../MCAL/MDIO/MDIO.h"

// Choose: COM_Cathode or COM_Anode
#define COM_Cathode

// Numbers
#define Zero   	 0
#define one   	 1
#define Two   	 2
#define Three 	 3
#define Four  	 4
#define Five     5
#define Six    	 6
#define Seven 	 7
#define eight    8
#define Nine     9
#define ten      A
#define eleven   B
#define twelve   C
#define thirteen D
#define fourteen E
#define fifteen  F

// FUNCTIONS PROTOTYPES
void HSSD_voidTurnOff(port A_PortName);
void HSSD_voidCountDown(port A_PortName,u8 A_u8NUM);
void HSSD_voidCountUP(port A_PortName,u8 A_u8NUM);
void HSSD_voidDisplayNUM(port A_PortName,u8 A_u8NUM);
void HSSD_voidInit(port A_PortName);



#endif /* HAL_SEVEN_SEG_HSSD_H_ */
