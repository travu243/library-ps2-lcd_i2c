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
- 
