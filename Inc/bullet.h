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

void initialize_bullet(fix_t x, fix_t y, fix_t vx, fix_t vy, bullet_t* bullet);
void draw_bullet(bullet_t bullet, uint8_t* buffer);
void remove_bullet(bullet_t* bullet);
void update_bullet(bullet_t* bullet);
void create_bullet(fix_t x, fix_t y, fix_t vx, fix_t vy, game_state_t state);
void draw_all_bullets(bullet_t* bullets, uint8_t* buffer);
void update_all_bullets(game_state_t state);


#endif /* BULLET_H_ */
