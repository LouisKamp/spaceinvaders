/*
 * lcd.h
 *
 *  Created on: 9. jan. 2023
 *      Author: louiss
 */

#ifndef LCD_H_
#define LCD_H_

#include "30010_io.h"
#include "charset.h"


void lcd_clear();
void lcd_write_char(char letter, int32_t x, int32_t y, uint8_t * buffer);
void lcd_write_string(char* str, int32_t x, int32_t y,  uint8_t * buffer);
void lcd_write_pixel(int32_t x, int32_t y,  uint8_t * buffer);

#endif /* LCD_H_ */
