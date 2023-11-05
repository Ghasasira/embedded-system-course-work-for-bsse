/*
 * virtualMonitor.h
 *
 * Created: 28/10/2023 19:32:48
 *  Author: HP
 */ 


#ifndef VIRTUALMONITOR_H_
#define VIRTUALMONITOR_H_


void UART_init();
void transmit_char(char data);
char receive_char();
void intro_text();
void listen_to_uart();
void clear_terminal();
void transmit_string(const char *str);
#endif /* VIRTUALMONITOR_H_ */