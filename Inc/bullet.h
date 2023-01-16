/*
 * bullet.h
 *
 *  Created on: 10. jan. 2023
 *      Author: Casper
 */

#ifndef BULLET_H_
#define BULLET_H_

#define NBULLETS 255


#include "spaceship.h"
#include "led.h"
#include "lcd.h"
#include "gpio.h"
#include "joystick.h"
#include "types.h"

void initialize_bullet(fix_t x, fix_t y, bullet_t *b);
void draw_bullet(bullet_t * b, uint8_t *buffer); //Update bullet
void update_bullet(bullet_t * b);
void create_bullet(fix_t x, fix_t y, game_state_t state);
void draw_all_bullets(game_state_t state);
void update_all_bullets(game_state_t state);

#endif /* BULLET_H_ */
