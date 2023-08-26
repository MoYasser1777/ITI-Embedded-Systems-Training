/*
 * SPI.h
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../../Lib/STD_Types.h"

void SPI_MasterInit(void);
u8 SPI_MasterTrancieve(u8 A_u8Data);
void SPI_SlaveInit(void);

#endif /* MCAL_SPI_SPI_H_ */
