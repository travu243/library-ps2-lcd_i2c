#ifndef __PS2_SPI_H
#define __PS2_SPI_H
#include "main.h"


extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim1;


void delay_us(uint16_t us);
void testcase(void);
uint8_t PS2_RWByte(uint8_t transmit, uint8_t receive, uint8_t timeout);
uint8_t Get_PS2Dat(uint8_t buf[]);
void ReadP2(void);



#endif
