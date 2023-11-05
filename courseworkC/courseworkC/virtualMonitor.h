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


#endif /* VIRTUALMONITOR_H_ */