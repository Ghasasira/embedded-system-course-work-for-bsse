/*
 * manageEEPROM.h
 *
 * Created: 05/11/2023 13:31:31
 *  Author: HP
 */ 


#ifndef MANAGEEEPROM_H_
#define MANAGEEEPROM_H_


void write_data(uint16_t address, uint8_t data);
uint8_t read_data(uint16_t address);



#endif /* MANAGEEEPROM_H_ */