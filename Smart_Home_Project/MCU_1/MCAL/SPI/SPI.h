/*
 * SPI.h
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../../Lib/STD_Types.h"

void SPI_voidInitMaster(void );
void SPI_voidInitSlave(void );
void SPI_voidTransmit(u8 Cpy_Data);
u8 SPI_u8Receive ();

#endif /* MCAL_SPI_SPI_H_ */
