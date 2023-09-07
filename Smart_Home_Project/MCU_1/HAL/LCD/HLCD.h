/*
 * HLCD.h
 *
 *  Created on: 16 Aug 2023
 *      Author: ehab
 */

#ifndef HAL_LCD_HLCD_H_
#define HAL_LCD_HLCD_H_

#include "HLCD_Config.h"

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../MCAL/MDIO/MDIO.h"


// LCD line addresses
#define LINE_1       1
#define LINE_2       2
#define LCD_LINE_1   0x80-1
#define LCD_LINE_2   0xC0-1

// LCD Commands addresses
#define LCD_FunctionSet     0b00111000   // 8_bit
#define LCD_FunctionSet_2   0b00101000   // 4_bit
#define LCD_Display		    0b00001111
#define LCD_EntryMode	    0b00000110

#define LCD_ClearDisplay    0x01
#define LCD_ReturnHome      0x02


// FUNCTIONS PROTOTYPES
void HLCD_voidInit             ();
void HLCD_voidSendData         (u8 A_u8Data);
void HLCD_voidSendCommand      (u8 A_u8Command);
void HLCD_voidSendCharacter    (u8 A_u8Character);
void HLCD_voidClear            ();
void HLCD_voidReturnHome       ();
void HLCD_voidSendString       (u8 *A_u8string);
void HLCD_voidMoveCursor       (u8 A_u8Line,u8 A_u8Col);

void HLCD_voidSaveCustomChar   (u8 *A_u8CustomArray,u8 A_u8CGRAMIndex);
void HLCD_voidDisplayCustomChar(u8 A_u8CGRAMIndex);

void HLCD_voidDisplayNumber(s32 A_s32Number);

#endif /* HAL_LCD_HLCD_H_ */
