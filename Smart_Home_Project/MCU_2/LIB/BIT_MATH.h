/*
 *  Created on: 11 Aug 2023
 *      Author: Youssef
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

///////////////////////

#define Set_Bit(Reg,bit_number)     Reg |= 1<<bit_number
#define Clr_Bit(Reg,bit_number)     Reg &= ~(1<<bit_number)
#define Toggel_Bit(Reg,bit_number)  Reg ^= 1<<bit_number
#define Get_Bit(Reg,bit_number)     (Reg>>bit_number) & 0x01
#define Set_Byte(Reg,Value)         (Reg = Value)

//////////////////////


#endif /* BIT_MATH_H_ */
