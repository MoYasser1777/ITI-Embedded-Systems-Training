/*
 * HLCD_Config.h
 *
 *  Created on: 19 Aug 2023
 *      Author: ehab
 */

#ifndef HAL_LCD_HLCD_CONFIG_H_
#define HAL_LCD_HLCD_CONFIG_H_

// LCD Modes
#define FOUR_BIT          0
#define EIGHT_BIT         1
#define LCD_MODE          FOUR_BIT

// LCD Control & Data PORT
#define LCD_Data_PORT     MDIO_PORTA
#define LCD_Control_PORT  MDIO_PORTA

// LCD Control Pins
#define EN 6
#define RW 5
#define RS 4

#endif /* HAL_LCD_HLCD_CONFIG_H_ */
