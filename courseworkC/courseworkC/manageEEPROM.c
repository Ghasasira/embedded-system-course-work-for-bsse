/*
 * attendant.c
 *
 * Created: 26/10/2023 18:01:18
 *  Author: HP
 */ 
#include <avr/io.h>
#include <avr/eeprom.h>
#include <util/delay.h>

// Define memory addresses for the 4 variables in EEPROM
#define EEPROM_ADDRESS_VISITORS 0
#define EEPROM_ADDRESS_WATER 1
#define EEPROM_ADDRESS_CARS 2
#define EEPROM_ADDRESS_MONEY 3
#define EEPROM_ADDRESS_PWD 4  



void write_data(uint16_t address, uint8_t data) {
	while (EECR & (1 << EEPE)); // Wait for previous write to complete
	EEAR = address; // Set the address
	EEDR = data;    // Set data to write
	EECR |= (1 << EEMPE); // Enable EEPROM write
	EECR |= (1 << EEPE);  // Start EEPROM write
}

// Function to read data from EEPROM
uint8_t read_data(uint16_t address) {
	while (EECR & (1 << EEPE)); // Wait for previous write to complete
	EEAR = address; // Set the address to read
	EECR |= (1 << EERE); // Start EEPROM read
	return EEDR; // Return the read data
}