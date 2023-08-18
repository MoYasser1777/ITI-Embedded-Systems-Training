/*
 * LCD.h
 *
 *  Created on: Aug 15, 2023
 *      Author: lenovo
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "../../Lib/STD_Types.h"


void HLCD_voidSendCommand(u8 A_u8cmd);
void HLCD_voidSendData(u8 A_u8data);
void HLCD_void8bitInit();
void HLCD_voidClear();
void HLCD_voidSetCursor(u8 A_u8RowNum,u8 A_u8ColNum);
void HLCD_voidSendString(u8 *A_u8PtrString);
void HLCD_voidDisplayChar(u8 A_u8Char);
void HLCD_voidDisplayNum(s32 A_s32Number);
void HLCD_voidSaveCustomChar (u8 A_u8CGRAM_Index,u8 *A_u8CustomArray);
void HLCD_voidDisplayCustomChar (u8 A_u8CGRAM_Index);

#endif /* HAL_LCD_LCD_H_ */


