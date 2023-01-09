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
void lcd_write_string(uint8_t row, uint8_t col);

#endif /* LCD_H_ */
