/*
 * EXT_INT_private.h
 *
 *  Created on: Aug 19, 2023
 *      Author: lenovo
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#include "../../Lib/defines.h"

#define EXTINT_Int0	 0
#define EXTINT_Int1	 1
#define EXTINT_Int2  2

#define EXTINT_SenseControl_FallingEdge       0
#define EXTINT_SenseControl_RisingEdge        1
#define EXTINT_SenseControl_OnChange		  2
#define EXTINT_SenseControl_LowLevel		  3

#define EXTINT_ISC00 PIN0
#define EXTINT_ISC01 PIN1
#define EXTINT_ISC10 PIN2
#define EXTINT_ISC11 PIN3

#define EXTINT_ISC2 PIN6

#define EXTINT_Int0_GICR	PIN6
#define EXTINT_Int1_GICR	PIN7
#define EXTINT_Int2_GICR	PIN5

#define EXTINT_MCUCR  *((volatile u8*) 0X55)
#define EXTINT_MCUCSR *((volatile u8*) 0X54)
#define EXTINT_GICR   *((volatile u8*) 0X5B)
#define EXTINT_GIFR   *((volatile u8*) 0X5A)
#define EXTINT_SREG   *((volatile u8*) 0x5F)

#endif /* MCAL_EXT_INT_EXT_INT_PRIVATE_H_ */
