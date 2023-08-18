/*
 * Bit_Maths.h
 *
 *  Created on: Aug 11, 2023
 *      Author: lenovo
 */

#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_

#define SET_BIT(Reg, bit_num) Reg |= (1 << (bit_num))

#define CLR_BIT(Reg, bit_num) Reg &= ~(1 << (bit_num))

#define TOOGLE_BIT(Reg, bit_num) Reg ^= (1 << (bit_num))

#define GET_BIT(Reg, bit_num) (Reg >> bit_num) & 0x01

#define SET_BYTE(Reg,Value)    Reg=Value

#endif /* BIT_MATHS_H_ */
