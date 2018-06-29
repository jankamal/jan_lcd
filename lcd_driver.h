#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void LCD_Init();
void LCD_cmd(unsigned char cmd);
void LCD_data(unsigned char data);
void LCD_str(char *str);