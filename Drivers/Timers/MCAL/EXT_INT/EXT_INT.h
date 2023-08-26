/*
 * EXT_INT.h
 *
 *  Created on: Aug 17, 2023
 *      Author: lenovo
 */

#ifndef MCAL_EXT_INT_EXT_INT_H_
#define MCAL_EXT_INT_EXT_INT_H_

#include "../../Lib/STD_Types.h"
#include "../../Lib/Bit_Maths.h"
#include "../../Lib/defines.h"
#include "EXT_INT_config.h"

void MEXTINT_voidSenseControl(u8 A_u8IntNum, u8 A_u8SenseControl);
void MEXTINT_voidEnableInt(u8 A_u8IntNum);
void MEXTINT_voidDisableInt(u8 A_u8IntNum);

#endif /* MCAL_EXT_INT_EXT_INT_H_ */
