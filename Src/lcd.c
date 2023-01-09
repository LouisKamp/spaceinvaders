/*
 * lcd.h
 *
 *  Created on: 9. jan. 2023
 *      Author: louiss
 */

#include "lcd.h"


void lcd_clear() {
	uint8_t buffer[64];
	memset(buffer,0x1,512);
	lcd_push_buffer(&buffer);
}

void lcd_write_string() {
	uint8_t buffer[64];
	memset(buffer,character_data[10],512);
	lcd_push_buffer(&buffer);
}

