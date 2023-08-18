/*
 * DC_Motor.h
 *
 *  Created on: Aug 16, 2023
 *      Author: lenovo
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_
#include "../../Lib/STD_Types.h"
#include "../../Lib/defines.h"

u8 G_u8PortNum;
void HDCM_voidInitPort(u8 A_u8PortNum);
void HDCM_voidRotateClockWise();
void HDCM_voidRotateAntiClockWise();

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */

