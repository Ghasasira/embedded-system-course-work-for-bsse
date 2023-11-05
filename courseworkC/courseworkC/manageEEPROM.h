/*
 * manageEEPROM.h
 *
 * Created: 05/11/2023 13:31:31
 *  Author: HP
 */ 


#ifndef MANAGEEEPROM_H_
#define MANAGEEEPROM_H_

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

void write_data(uint16_t address, uint16_t data);
uint8_t read_data(uint16_t address);

char* read_string_from_eeprom(uint16_t address);
void write_string_to_eeprom(uint16_t address, const char *str);



#endif /* MANAGEEEPROM_H_ */