/*
 * virtualMonitor.c
 *
 * Created: 28/10/2023 19:32:25
 *  Author: HP
 */ 



#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Define baud rate for UART communication
#define F_CPU 8000000UL

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void UART_init() {
	UBRR0H = (unsigned char)(BAUD_PRESCALE >> 8);
	UBRR0L = (unsigned char)BAUD_PRESCALE;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
}

// Function to send a character over UART
void transmit_char(char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

char receive_char() {
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void intro_text(){
	char str[]="Hello\nwagwan\nnigga\nthis\ncrazy";
	for(int i=0;str[i]!='\0';i++)
	{
		transmit_char(str[i]);
	}
}





