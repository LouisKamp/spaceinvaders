/*
 * ansi.h
 *
 *  Created on: 3. jun. 2022
 *      Author: Casper
 */

#ifndef _ANSI_H_
#define _ANSI_H_



void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void clear();
void getxy(int y, int x);
void clreol();
void underline(uint8_t on);

#endif

