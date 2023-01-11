/*
 * enemy.h
 *
 *  Created on: 11. jan. 2023
 *      Author: Casper
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#define NENEMY 5

#include "led.h"
#include "lcd.h"
#include "gpio.h"
#include "bullet.h"

typedef struct {
	uint8_t x;
	uint8_t y;
	uint8_t vx;
	uint8_t vy;
	uint8_t life;
	uint8_t active;

}enemy_t;

void initialize_enemy(enemy_t *e);
void draw_enemy(enemy_t *e, uint8_t *buffer);
void enemy_death( enemy_t *e,bullet_t *b, uint8_t *buffer);

#endif /* ENEMY_H_ */
