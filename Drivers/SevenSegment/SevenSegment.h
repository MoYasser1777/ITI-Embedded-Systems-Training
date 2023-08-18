/*
 * SevenSegment.h
 *
 *  Created on: Aug 13, 2023
 *      Author: lenovo
 */

#ifndef HAL_SEVENSEGMENT_SEVENSEGMENT_H_
#define HAL_SEVENSEGMENT_SEVENSEGMENT_H_

#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>

void H7seg_InitPort(u8 A_u8PortNum);

void H7seg_voidDisplayNum(u8 A_u8PortNum,u8 A_u8Num);

void H7seg_voidCountUp(u8 A_u8PortNum,u8 A_u8Num);

void H7seg_voidCountDown(u8 A_u8PortNum,u8 A_u8Num);

void H7seg_voidStartClock ();

void H7seg_voidResetClock ();

void H7seg_voidTurnOffClock ();


#endif /* HAL_SEVENSEGMENT_SEVENSEGMENT_H_ */
