/*
 * STD_Macros.h
 *
 *  Created on: 11 Aug 2023
 *      Author: ehab
 */

#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SET_BIT(reg,bit)        reg|=(1<<bit)
#define CLR_BIT(reg,bit)        reg&=~(1<<bit)
#define TOG_BIT(reg,bit)        reg^=(1<<bit)
#define READ_BIT(Reg, bit_num) (Reg >> bit_num) & 0x01

#endif /* STD_MACROS_H_ */
