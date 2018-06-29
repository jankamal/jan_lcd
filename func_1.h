#include <avr/io.h>
#include <util/delay.h>
void LCD_Init();
void LCD_cmd(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_str(char *str);
void func_1();