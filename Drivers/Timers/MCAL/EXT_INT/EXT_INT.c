/*
 * EXT_INT.c
 *
 *  Created on: Aug 17, 2023
 *      Author: lenovo
 */
#include "EXT_INT.h"
#include "../DIO/DIO.h"
#include "EXT_INT_private.h"

void MEXTINT_voidSenseControl(u8 A_u8IntNum, u8 A_u8SenseControl)
{
	switch(A_u8IntNum)
	{
		case EXTINT_Int0:
			switch(A_u8SenseControl)
			{
			case EXTINT_SenseControl_FallingEdge: CLR_BIT(EXTINT_MCUCR,EXTINT_ISC00);
												  SET_BIT(EXTINT_MCUCR,EXTINT_ISC01);
												  break;

			case EXTINT_SenseControl_RisingEdge:  SET_BIT(EXTINT_MCUCR,EXTINT_ISC00);
												  SET_BIT(EXTINT_MCUCR,EXTINT_ISC01);
												  break;

			case EXTINT_SenseControl_OnChange:    SET_BIT(EXTINT_MCUCR,EXTINT_ISC00);
												  CLR_BIT(EXTINT_MCUCR,EXTINT_ISC01);
												  break;

			case EXTINT_SenseControl_LowLevel:    CLR_BIT(EXTINT_MCUCR,EXTINT_ISC00);
												  CLR_BIT(EXTINT_MCUCR,EXTINT_ISC01);
												  break;
			}
			break;

		case EXTINT_Int1:
			switch(A_u8SenseControl)
			{
			case EXTINT_SenseControl_FallingEdge: CLR_BIT(EXTINT_MCUCR,EXTINT_ISC10);
											   	  SET_BIT(EXTINT_MCUCR,EXTINT_ISC11);
												  break;

			case EXTINT_SenseControl_RisingEdge:  SET_BIT(EXTINT_MCUCR,EXTINT_ISC10);
												  SET_BIT(EXTINT_MCUCR,EXTINT_ISC11);
												  break;

			case EXTINT_SenseControl_OnChange:    SET_BIT(EXTINT_MCUCR,EXTINT_ISC10);
												  CLR_BIT(EXTINT_MCUCR,EXTINT_ISC11);
												  break;

			case EXTINT_SenseControl_LowLevel:    CLR_BIT(EXTINT_MCUCR,EXTINT_ISC10);
												  CLR_BIT(EXTINT_MCUCR,EXTINT_ISC11);
												  break;
			}
			break;

	case EXTINT_Int2:
		switch(A_u8SenseControl)
			{
			case EXTINT_SenseControl_FallingEdge: CLR_BIT(EXTINT_MCUCR,EXTINT_ISC2);
												break;

			case EXTINT_SenseControl_RisingEdge:  SET_BIT(EXTINT_MCUCR,EXTINT_ISC2);
												break;
			}
			break;
	}
}

void MEXTINT_voidEnableInt(u8 A_u8IntNum)
{
	switch(A_u8IntNum)
		{
		case EXTINT_Int0:
			SET_BIT(EXTINT_GICR, EXTINT_Int0_GICR);
			break;
		case EXTINT_Int1:
			SET_BIT(EXTINT_GICR, EXTINT_Int1_GICR);
			break;
		case EXTINT_Int2:
			SET_BIT(EXTINT_GICR, EXTINT_Int2_GICR);
			break;
		}
}
void MEXTINT_voidDisableInt(u8 A_u8IntNum)
{
	switch(A_u8IntNum)
			{
			case EXTINT_Int0:
				CLR_BIT(EXTINT_GICR, EXTINT_Int0_GICR);
				break;
			case EXTINT_Int1:
				CLR_BIT(EXTINT_GICR, EXTINT_Int1_GICR);
				break;
			case EXTINT_Int2:
				CLR_BIT(EXTINT_GICR, EXTINT_Int2_GICR);
				break;
			}
}
