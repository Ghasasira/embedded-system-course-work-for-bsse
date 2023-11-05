#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>

#define rs PB2
#define rw PB1
#define enable PB0
#define dataline PORTA

void latch()
{
	PORTB |= (1 << enable);
	_delay_ms(10);
	PORTB &= ~(1 << enable);
	_delay_ms(10);
}

void lcd_cmd(unsigned char cmd)
{
	latch();
	PORTB &= ~(1 << rs);
	_delay_ms(5);
	PORTB &= ~(1 << rw);
	dataline = cmd;
	latch();
}

void lcd_init()
{
	// Configure the control pins (rs, rw, enable) as output
	//DDRB |= (1 << rs) | (1 << rw) | (1 << enable);
	// Configure the data lines (PORTA) as output
	//DDRA = 0xFF;

	_delay_ms(15); // Wait for LCD to power up
	lcd_cmd(0x38); // 8-bit mode, 2 lines, 5x7 font
	lcd_cmd(0x01); // Clear the display
	lcd_cmd(0x0F); // Display on, cursor on
	lcd_cmd(0x06); // Increment cursor
}

void lcd_clear()
{
	lcd_cmd(0x01); // Clear the display
	_delay_ms(2);      // Wait for clear command to complete
	lcd_cmd(0x02); // Return to home position
	_delay_ms(2);      // Wait for return command to complete
}


void lcd_data(unsigned char data)
{
	//latch();
	PORTB |= (1 << rs);
	_delay_ms(5);
	PORTB &= ~(1 << rw);
	dataline = data;
	latch();
}

void lcd_string(const char str[])
{
	for(int i=0;str[i]!='\0';i++){
	//while (*str) {
		lcd_data(str[i]);
		_delay_ms(100);
		//str++;
	}
}
