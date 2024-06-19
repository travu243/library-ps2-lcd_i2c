#include "PS2_SPI.h"
#include "stm32f1xx_hal.h"

#define CS_LOW HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET)
#define CS_HIGH HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET)
int dem=0;

uint8_t PS2buf[9] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t INDEX[9] = {0x00};
uint16_t status = 0;
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
uint8_t PS2_MODE;

void delay_us(uint16_t us) {
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

void testcase()
{
	GPIOC->ODR^=(1<<13);
	dem++;
	delay_us(500);
}

uint8_t PS2_RWByte(uint8_t transmit, uint8_t receive, uint8_t timeout)
{
	HAL_SPI_TransmitReceive(&hspi1, &transmit, &receive, sizeof(uint8_t), 1);
	return(receive);
}

uint8_t Get_PS2Data(uint8_t buf[])
{ 
		CS_LOW;
		delay_us(15);
    buf[0] = PS2_RWByte(0x01, buf[0], 9);delay_us(15);
    buf[1] = PS2_RWByte(0x42, buf[1], 9);delay_us(15);
    buf[2] = PS2_RWByte(0x00, buf[2], 9);delay_us(15);
    buf[3] = PS2_RWByte(0x00, buf[3], 9);delay_us(15);
    buf[4] = PS2_RWByte(0x00, buf[4], 9);delay_us(15);
    buf[5] = PS2_RWByte(0x00, buf[5], 9);delay_us(15);
    buf[6] = PS2_RWByte(0x00, buf[6], 9);delay_us(15);
    buf[7] = PS2_RWByte(0x00, buf[7], 9);delay_us(15);
    buf[8] = PS2_RWByte(0x00, buf[8], 9);delay_us(15);
    CS_HIGH;
    if((buf[0] == 0xFF) && (buf[1] == 0x41) && (buf[2] == 0x5A))
        return 1;
    if((buf[0] == 0xFF) && (buf[1] == 0x73) && (buf[2] == 0x5A))
        return 2;
    return 0;
}
void ReadP2()
{
	Get_PS2Data(INDEX);
	if(INDEX[1] == 0x73)
	{
		PS2_MODE = 1;
	}
	else if (INDEX[1] != 0x73)
	{
		PS2_MODE= 0;
	}
	if (INDEX[1] != 0x41 && INDEX[1] != 0x73) return;
	status = INDEX[3] | (INDEX[4] << 8); //16->8  65535[0][1]0x42
	SELECT = !((status >> 0) & 0x01);
	L3 = !((status >> 1) & 0x01);
	R3 = !((status >> 2) & 0x01);
	START = !((status >> 3) & 0x01);
	UP = !((status >> 4) & 0x01);
	RIGHT = !((status >> 5) & 0x01);
	DOWN = !((status >> 6) & 0x01);
	LEFT = !((status >> 7) & 0x01);
	status = (INDEX[4] << 8);
	L2 = !((status >> 8) & 0x01);
	R2 = !((status >> 9) & 0x01);
	L1 = !((status >> 10) & 0x01);
	R1 = !((status >> 11) & 0x01);
	TRIANGLE = !((status >> 12) & 0x01);
	CIRCLE = !((status >> 13) & 0x01);
	CROSS = !((status >> 14) & 0x01);
	SQUARE = !((status >> 15) & 0x01);
	if (INDEX[1] != 0x73) return;
	RX = INDEX[5];
	RY = INDEX[6];
	LX = INDEX[7];
	LY = INDEX[8];
	//if(INDEX[1] == 0x73) return;
	
}
 



