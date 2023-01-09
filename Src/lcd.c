/*
 * lcd.h
 *
 *  Created on: 9. jan. 2023
 *      Author: louiss
 */

#include "lcd.h"


void lcd_clear() {
	uint8_t buffer[512];
	memset(buffer,0b00000000,512);
	lcd_push_buffer(&buffer);
}

void lcd_write_string(uint8_t row, uint8_t col) {
	uint8_t buffer[512] = {};
	uint8_t x = 30;



	for (uint8_t i = 0; i < 5; i++) {
//		uint8_t offset = 128*row+col+i;
		uint8_t offset = 0+i+0b10;
		memset(buffer+offset,(character_data[x][i]>>2),1);
	}

//	memset(buffer+128*row+col,character_data[x][0],1);
//	memset(buffer+1+128*row+col,character_data[x][1],1);
//	memset(buffer+2+128*row+col,character_data[x][2],1);
//	memset(buffer+3+128*row+col,character_data[x][3],1);
//	memset(buffer+4+128*row+col,character_data[x][4],1);


	lcd_push_buffer(&buffer);
}

