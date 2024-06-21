# How to use

* LCD-I2C
- Use Hal library
- Define lcd variable
```
LCD_I2C lcd;
```
- Init lcd (call function in main())
```
LCD_I2C_Init(&lcd,&hi2c2,address,width,height);
```
address: address of pcf8574
width: width of lcd
height: height of lcd
- use function for your purpose:
```
LCD_I2C_SetCursor(&lcd, 0, 0);    //cursor on lcd, x is width, y is height
LCD_I2C_WriteString(&lcd,"hello world");
```

* PS2
- Use Hal library
- Define object PS2Buttons ps2;
- init 2 timer for ps2:
timer1 for delay_us: prescaler=64-1, period=0xff
timer2 for update: prescaler=6400-1, period=100-1 and enable interrupt for timer2
- In main(), call PS2_Init(&htim1,&ps2) for init ps2
- Overflow interrput timer for update buttons stage:
```
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  if(htim->Instance == TIM2) PS2_Update();
}
```
or go to file stm32f1xx_it.c
put PS2_Update() in TIM2_IRQHandler()
```
void TIM2_IRQHandler(void){
  PS2_Update();
}
```
