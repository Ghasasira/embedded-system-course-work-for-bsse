/*
 * attendant.c
 *
 * Created: 26/10/2023 18:01:18
 *  Author: HP
 */ 
#include <avr/io.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include <string.h>


// Define memory addresses for the 4 variables in EEPROM
#define totalVisitors 0
#define pricePerBottle 1
#define maxPeople 2
#define adultsFee 3
#define childrenFee 4
#define PWD 5
#define fridgeTotal 6
#define entranceFeesTotal 7
#define children 8
#define adults 9
#define cars 10





void write_data(uint16_t address, uint16_t data) {
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
void write_string_to_eeprom(uint16_t address, const char *str) {
	for (uint8_t i = 0; i < strlen(str); i++) {
		write_data(address + i, (uint16_t)str[i]);
	}
	// Null-terminate the string
	write_data(address + strlen(str), (uint16_t)'\0');
}

char* read_string_from_eeprom(uint16_t address) {
	char str[256]; // Assuming a maximum string length of 255 characters
	int i = 0;

	while (1) {
		char data = read_data(address + i);
		if (data == '\0') {
			break; // End of the string
		}
		str[i] = data;
		i++;
	}
	str[i] = '\0'; // Null-terminate the string

	return str;

}