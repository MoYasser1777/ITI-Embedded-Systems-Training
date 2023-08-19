/*
 * GIE.c
 *
 *  Created on: Aug 19, 2023
 *      Author: lenovo
 */

#include "GIE.h"
#include "EXT_INT_private.h"

void MGIR_voidEnable()
{
	SET_BIT(EXTINT_SREG,7);
}

void MGIR_voidDisEnable()
{
	CLR_BIT(EXTINT_SREG,7);
}
