/*
 * asteroid.h
 *
 *  Created on: 12. jan. 2023
 *      Author: Casper
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_

#include <types.h>
#include "bullet.h"
#include "led.h"
#include "lcd.h"
#include "gpio.h"
#include "joystick.h"
#include "types.h"
#include "interrupts.h"

#define NASTEROIDS 255

void initialize_asteroid(fix_t x, fix_t y,fix_t vx, fix_t vy , asteroid_t* asteroid);
void draw_asteroid(asteroid_t asteroid, uint8_t* buffer);
void remove_asteoroid(asteroid_t* a);;
void draw_all_asteroids(asteroid_t* a, uint8_t* buffer);
void create_asteroid(fix_t x, fix_t y, game_state_t state);
void update_all_asteroids(game_state_t state);


#endif /* ASTEROID_H_ */
