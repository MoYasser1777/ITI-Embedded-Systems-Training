/*
 * SPI.c
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */
#include "SPI.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../DIO/DIO.h"
#include "../../Lib/defines.h"
#include "../../Lib/Bit_Maths.h"

void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
MDIO_voidSetPortDirection(PORTB,INPUT);
MDIO_voidSetPinDirection(PORTB,PIN5,OUTPUT);
MDIO_voidSetPinDirection(PORTB,PIN7,OUTPUT);

/* Enable SPI, Master, set clock rate fck/64 */
SPCR = 0b01011110;
}

u8 SPI_MasterTrancieve(u8 A_u8Data)
{
/* Start transmission */
SPDR = A_u8Data;

/* Wait for transmission complete */
while(GET_BIT(SPSR,SPSR_SPIF) != 1){};

return SPDR;
}

void SPI_SlaveInit(void)
{
/* Set MISO output, all others input */
MDIO_voidSetPortDirection(PORTB,INPUT);
MDIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);
/* Enable SPI */
SPCR = 0b01001110;
}

