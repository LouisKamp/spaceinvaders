/*
 * MakeScreens.c
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#include "lcd.h"
#include "MakeScreens.h"

void make_start_screen(char* str) {
	lcd_init();
	lcd_clear();
	uint8_t buffer[512] = {};

	int n=1;
	while( n <= 54 ) {
		lcd_write_string("_",8,32+n,&buffer);
		lcd_write_string("_",21,32+n,&buffer);
		n++;
	}
	lcd_write_string("*",1,120, &buffer);
	lcd_write_string("*",1,1, &buffer);
	lcd_write_string("*",23,1, &buffer);
	lcd_write_string("*",23,120, &buffer);
	lcd_write_string(str,16,38, &buffer);
	lcd_push_buffer(&buffer);
}
void make_help_screen(char* str) {
	lcd_init();
	lcd_clear();
	uint8_t buffer[512] = {};
	lcd_write_string(str,1,38, &buffer);
	lcd_push_buffer(&buffer);
}
void help_info_screen() {
	lcd_init();
	lcd_clear();
	uint8_t buffer[512] = {};
	lcd_write_string("Shoot on center",1,3, &buffer);
	lcd_write_string("Move Down ",20,3, &buffer);
	lcd_push_buffer(&buffer);
}



