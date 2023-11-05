/*
 * virtualMonitor.c
 *
 * Created: 28/10/2023 19:32:25
 *  Author: HP
 */ 



#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include "manageEEPROM.h"
#include "global.h"

// Define baud rate for UART communication
#define F_CPU 8000000UL


#include <util/delay.h>



#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void UART_init() {
	UBRR0H = (unsigned char)(BAUD_PRESCALE >> 8);
	UBRR0L = (unsigned char)BAUD_PRESCALE;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
}

// Function to send a character over UART
void transmit_char(unsigned char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void clear_terminal() {
	// Send the escape sequence to clear the terminal
	transmit_char('C');
	transmit_char('L');
	transmit_char('S');
}

char receive_char() {
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void transmit_string(const char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		transmit_char(str[i]);
	}
}


void intro_text(){
	
	char str[] = "Hello!\n\r\r\rCommands\n\r\r1-Entry\n\r2-Check Out\n\r3-Total people\n\r4-Total children\n\r5-Total adults\n\r6-Total amount\n\r7-Total amount(fridge)\n\r8-Total amount(entrance)\n\r9-Capacity\n\r";
	
	for(int i=0; str[i] != '\0'; i++)
	{
		transmit_char(str[i]);
	}
	  
}


void listen_to_uart() {
	char* data_from_eeprom;
	while (1) {
		// Check if a character is available in the UART receive buffer
		if (UCSR0A & (1 << RXC0)) {
			// Read the received character
			char received_char = UDR0;
			
			// Process the received character
			switch (received_char) {
				case '1':
				_delay_ms(1000);
				clear_terminal();
				// Process entry command for option 1
				// ...
				transmit_char('t');
				break;
				case '2':
				// Process check-out command for option 2
				// ...
				transmit_char('e');
				break;
				// Add cases for other command options as needed
				case '5':
				// Process check-out command for option 2
				// ...
				data_from_eeprom = read_string_from_eeprom(PWD);
				transmit_string(data_from_eeprom);
				
				break;
				default:
				// Handle unrecognized command
				transmit_char('U'); // 'U' for "Unknown command"
				break;
			}
		}
		
		// Add any other background tasks or processing as needed
	}
}



