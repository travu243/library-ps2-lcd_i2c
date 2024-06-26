#ifndef __LCD_I2C_H
#define __LCD_I2C_H

#include "stm32f1xx_hal.h"

#define LCD_COMMAND 	0x00
#define LCD_DATA 		0x01

#define LCD_EN 0x04  // Enable bit
#define LCD_RW 0x02  // Read/Write bit
#define LCD_RS 0x01  // Register select bit

#define LCD_COMMAND 			0x00
#define LCD_DATA 				0x01

// commands
#define LCD_CLEARDISPLAY 		0x01
#define LCD_RETURNHOME 			0x02

#define LCD_ENTRYMODESET 		0x04
#define LCD_DISPLAYCONTROL 		0x08
#define LCD_CURSORSHIFT 		0x10
#define LCD_FUNCTIONSET 		0x20
#define LCD_SETCGRAMADDR 		0x40
#define LCD_SETDDRAMADDR	 	0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 			0x00
#define LCD_ENTRYLEFT 			0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 			0x04
#define LCD_DISPLAYOFF 			0x00
#define LCD_CURSORON 			0x02
#define LCD_CURSOROFF 			0x00
#define LCD_BLINKON 			0x01
#define LCD_BLINKOFF 			0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 		0x08
#define LCD_CURSORMOVE 			0x00
#define LCD_MOVERIGHT 			0x04
#define LCD_MOVELEFT 			0x00

// flags for function set
#define LCD_8BITMODE 			0x10
#define LCD_4BITMODE 			0x00
#define LCD_2LINE 				0x08
#define LCD_1LINE 				0x00
#define LCD_5x10DOTS 			0x04
#define LCD_5x8DOTS 			0x00

#define LCD_BACKLIGHT 			0x08
#define LCD_NOBACKLIGHT 		0x00
typedef struct
{
	I2C_HandleTypeDef* I2C;
	uint8_t ADDRESS;
	uint8_t COLUMS;
	uint8_t ROWS;
	uint8_t ENTRYMODE;
	uint8_t DISPLAYCTRL;
	uint8_t CURSORSHIFT;
	uint8_t FUNCTIONSET;
	uint8_t BACKLIGHT;
}LCD_I2C;
void LCD_I2C_Init(LCD_I2C* LCD, I2C_HandleTypeDef* hi2c_LCD, uint8_t Address, uint8_t Colums, uint8_t Rows);
void LCD_I2C_SetCursor(LCD_I2C* LCD, uint8_t Xpos, uint8_t YPos);
void LCD_I2C_WriteChar(LCD_I2C* LCD, char character);
void LCD_I2C_WriteString(LCD_I2C* LCD, char *String);
void LCD_I2C_Clear(LCD_I2C* LCD);
void LCD_I2C_ReturnHome(LCD_I2C* LCD);
void LCD_I2C_CursorOn(LCD_I2C* LCD);
void LCD_I2C_CursorOff(LCD_I2C* LCD);
void LCD_I2C_BlinkOn(LCD_I2C* LCD);
void LCD_I2C_BlinkOff(LCD_I2C* LCD);
void I2C_LCD_setCursor(uint8_t col, uint8_t row);
void I2C_LCD_SendString(char *str);
#endif
