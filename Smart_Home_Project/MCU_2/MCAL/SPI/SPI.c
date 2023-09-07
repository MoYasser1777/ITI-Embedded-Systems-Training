/*
 * SPI.c
 *
 *  Created on: Aug 24, 2023
 *      Author: lenovo
 */
#include "../../LIB/Memory_Map.h"
#include "../../LIB/STD_Macros.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "../MDIO/MDIO.h"

void SPI_voidInitMaster(void)
{
	/*Set MOSI, SS, and SCK pins as output*/
	MDIO_voidSetPinDirection(1 , 4 , 1); // SS
	MDIO_voidSetPinDirection(1 , 5 , 1); // MOSI
	MDIO_voidSetPinDirection(1 , 6 , 1); // MISO
	MDIO_voidSetPinDirection(1 , 7 , 1); // SCK

	/* Disable interrupt */
	CLR_BIT(SPCR , SPCR_SPIE);

	/* MSB First */
	CLR_BIT(SPCR , SPCR_DORD) ;

	/* Master select */
	SET_BIT(SPCR, SPCR_MSTR);

	/* Clk idle low |  Leading edge is rising */
	CLR_BIT(SPCR, SPCR_CPOL);

	/* Sample at leading edge */
	CLR_BIT(SPCR, SPCR_CPHA);

	/* Freq / 16 */
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);

	/*Write Logic High to SS pin*/
	MDIO_voidSetPinValue(1 , 4 , 1);
}

void SPI_voidInitSlave(void)
{
	/* Init pins for SPI */
	MDIO_voidSetPinDirection(MDIO_PORTB , PIN4 , INPUT);  //SS
	MDIO_voidSetPinDirection(MDIO_PORTB , PIN5 , INPUT);  // MOSI
	MDIO_voidSetPinDirection(MDIO_PORTB , PIN6 , OUTPUT); // MISO
	MDIO_voidSetPinDirection(MDIO_PORTB , PIN7 , INPUT);  // SCK

	/* Disable interrupt */
	CLR_BIT(SPCR , SPCR_SPIE);

	/* MSB First */
	CLR_BIT(SPCR , SPCR_DORD);

	/* Slave select */
	CLR_BIT(SPCR, SPCR_MSTR);

	/* Clk idle low |  Leading edge is rising */
	CLR_BIT(SPCR, SPCR_CPOL);

	/* Sample at leading edge */
	CLR_BIT(SPCR, SPCR_CPHA);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);
}

void SPI_voidTransmit(u8 Cpy_data)
{
	/*Clear SS pin to send data*/
	MDIO_voidSetPinValue(1 , 4 , 0);

    /* Send Data */
    SPDR = Cpy_data;

    /* Wait till data is sent */
    while (READ_BIT(SPSR, SPSR_SPIF) == 0);
}

/* Function to receive data over SPI */
u8 SPI_u8Receive()
{
    /* Wait till reception is complete */
    while (READ_BIT(SPSR, SPSR_SPIF) == 0);

    /* Return received data */
    return SPDR;
}

