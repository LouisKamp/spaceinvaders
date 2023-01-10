/*
 * lcd.h
 *
 *  Created on: 9. jan. 2023
 *      Author: louiss
 */

#include "lcd.h"


void lcd_clear(uint8_t * buffer) {
	memset(buffer,0b00000000,512);
}


// Writes one char to a LCD buffer on a x,y coordinate
void lcd_write_char(char letter,int32_t x, int32_t y, uint8_t * buffer) {

	// char to ascii
	uint32_t c = (int32_t) letter - 32;

	// calcs the row text is on
	int32_t row = x/8;

	uint32_t i = 0;
	// sets the correct offset so the text is partially rendered
	if (y < 0) {
		i = -y;
	}

	for (i; i < 5; i++) {

		// check if inside y-axis
		if (i+y > 128 || i < 0) {
			break;
		}

		// check if inside x-axis and if its above display
		if (x < 0 && -7 < x) {
			// The text is visible and above display
			uint32_t row_offset = (-1)*x % 8;
			uint32_t offset = row*128+i+y;
			memset(buffer+offset,(character_data[c][i]>>row_offset),1);
		} else if (row < 4) {
			// The text is inside the display
			uint32_t row_offset = x % 8;
			uint32_t offset = row*128+i+y;

			// sets the correct bits according to offset of line
			memset(buffer+offset,(character_data[c][i]<<row_offset),1);

			// if the offset is not on the rows, offset needs to be rendered too
			if (row_offset != 0 && row < 3) {
				// text is not completely outside display and can be rendered
				memset(buffer+offset+128,(character_data[c][i]>>8-row_offset),1);
			}
		}
	}
}

// Writes a string to a LCD buffer on a specific coordinate
void lcd_write_string(char* str,int32_t x, int32_t y,  uint8_t * buffer) {

	uint8_t len = strlen(str);
	for (uint8_t i = 0; i < len; i++) {
		lcd_write_char(str[i], x, y+5*i, buffer);
	}

}

void lcd_write_pixel(int32_t x, int32_t y,  uint8_t * buffer) {

	int32_t row = x/8;
	int32_t row_offset = x % 8;
	int32_t offset = 128*row+y;

	buffer[offset] |= (0b00000001 << row_offset);

}


