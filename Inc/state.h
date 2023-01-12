/*
 * state.h
 *
 *  Created on: 10. jan. 2023
 *      Author: louiss
 */

#ifndef STATE_H_
#define STATE_H_

#include "enemy.h"
#include "asteroid.h"
#include "bullet.h"
#include "spaceship.h"


typedef struct {
	spaceship_t * player;
	bullet_t * bullets;
	uint8_t *num_bullet;
	uint8_t * screen;
	uint8_t * buffer;
	enemy_t * enemy;
	uint8_t *num_enemy;
	asteroid_t *asteroid;
	uint8_t *num_asteroid;
	joystick_input_t * joystick_input;

} game_state_t;


#endif /* STATE_H_ */
