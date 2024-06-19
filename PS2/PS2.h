#ifndef INC_PS2_PS2_H_
#define INC_PS2_PS2_H_

#include "main.h"
#include "datatypes.h"
typedef struct {
	uint8_t SELECT;
	uint8_t L3;
	uint8_t R3;
	uint8_t START;
	uint8_t UP;
	uint8_t RIGHT;
	uint8_t DOWN;
	uint8_t LEFT;
	uint8_t L2;
	uint8_t R2;
	uint8_t L1;
	uint8_t R1;
	uint8_t TRIANGLE;
	uint8_t CIRCLE;
	uint8_t CROSS;
	uint8_t SQUARE;
	uint8_t RX;
	uint8_t RY;
	uint8_t LX;
	uint8_t LY;
} PS2Buttons;

void delay_us(uint16_t);
uint8_t PS2_SendByte(uint8_t);
void PS2_Cmd(uint8_t *, uint8_t *, uint8_t );
void PS2_Poll(void);
void PS2_EnterConfig(void);
void PS2_AnalogMode(void);
void PS2_ExitConfig(void);
void PS2_Init(TIM_HandleTypeDef*, PS2Buttons*);
void PS2_Update(void);

#endif /* INC_PS2_PS2_H_ */
