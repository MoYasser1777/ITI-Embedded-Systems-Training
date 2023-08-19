/*
 * EXT_INT_private.h
 *
 *  Created on: Aug 19, 2023
 *      Author: lenovo
 */

#ifndef MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_EXT_INT_PRIVATE_H_

#define EXTINT_MCUCR  *((volatile u8*) 0X55)
#define EXTINT_MCUCSR *((volatile u8*) 0X54)
#define EXTINT_GICR   *((volatile u8*) 0X5B)
#define EXTINT_GIFR   *((volatile u8*) 0X5A)
#define EXTINT_SREG   *((volatile u8*) 0x5F)

#endif /* MCAL_EXT_INT_EXT_INT_PRIVATE_H_ */
