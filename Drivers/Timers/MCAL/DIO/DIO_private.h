/*
 * DIO_private.h
 *
 *  Created on: Aug 18, 2023
 *      Author: lenovo
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#include "../../lib/STD_Types.h"

#define DIO_PORTA_REG *((volatile u8*) 0X3B)
#define DIO_DDRA_REG *((volatile u8*) 0X3A)
#define DIO_PINA_REG *((volatile u8*) 0X39)

#define DIO_PORTB_REG *((volatile u8*) 0X38)
#define DIO_DDRB_REG *((volatile u8*) 0X37)
#define DIO_PINB_REG *((volatile u8*) 0X36)

#define DIO_PORTC_REG *((volatile u8*) 0X35)
#define DIO_DDRC_REG *((volatile u8*) 0X34)
#define DIO_PINC_REG *((volatile u8*) 0X33)

#define DIO_PORTD_REG *((volatile u8*) 0X32)
#define DIO_DDRD_REG *((volatile u8*) 0X31)
#define DIO_PIND_REG *((volatile u8*) 0X30)

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
