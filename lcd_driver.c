#include "lcd_driver.h"
void LCD_Init()
{
	DDRA|=0xF0;
	DDRB|=(0xE0);
	//init command
	_delay_ms(20);
	LCD_cmd(0x28);
	LCD_cmd(0x0C);
	LCD_cmd(0x06);
	LCD_cmd(0x01);
	_delay_ms(5);
}

void LCD_cmd(unsigned char cmd)
{
	PORTB&=~(0x20); //
	PORTB&=~(0x40);//reset RW to lcd
	PORTA=(PORTA&(0x0F))|(cmd&0xF0);//sending Upper nipple
	PORTB|=(0x80);//set enable 
	PORTB&=~(0x80);//reset enable
	PORTA=(PORTA&(0x0F))|(cmd<<4);//sending lower nipple
	PORTB|=(0x80);//set enable
	PORTB&=~(0x80);//reset enable
	_delay_us(40);
	
	
}

void LCD_data(unsigned char data)
{
	PORTB|=(0x20); //
	PORTB&=~(0x40);//reset RW to lcd
	PORTA=(PORTA&(0x0F))|(data&(0xF0));//sending Upper nipple
	PORTB|=(0x80);//set enable
	PORTB&=~(0x80);//reset enable
	
	PORTA=(PORTA&(0x0F))|(data<<4);//sending lower nipple
	PORTB|=(0x80);//set enable
	PORTB&=~(0x80);//reset enable
	
	_delay_us(40);

}
void LCD_str(char *str)
{
	while (*str)
	{
		LCD_data(*str++);
	}
}
