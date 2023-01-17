/*
 * game.h
 *
 *  Created on: 12. jan. 2023
 *      Author: louiss
 */

#ifndef GAME_H_
#define GAME_H_

#include "explosion.h"
#include "types.h"
#include "bullet.h"
#include "spaceship.h"
#include "joystick.h"
#include "enemy.h"
#include "asteroid.h"
#include "powerup.h"
#include "interrupts.h"
#include "score.h"

void handle_user_input(game_state_t state);
void handle_bullet_enemy_interaction(game_state_t state);
void handle_bullet_asteroid_interaction(game_state_t state);
void handle_player_powerup_interaction(game_state_t state);

#endif /* GAME_H_ */
