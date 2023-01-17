

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "types.h"
#include "gpio.h"
#include "led.h"
#include "LUTsin.h"
#include "ansi.h"
#include "lcd.h"
#include "fixed_point.h"
#include "joystick.h"
#include "bullet.h"

#define SPACESHIP_NORMAL_STATE 0
#define SPACESHIP_POWERUP_STATE 1

void initialize_spaceship(spaceship_t* spaceship);
void draw_spaceship(spaceship_t spaceship, uint8_t* buffer);
void draw_spaceship_health(spaceship_t spaceship, uint8_t* buffer);
void update_spaceship(joystick_input_t input, spaceship_t* spaceship);
void spaceship_shoot(spaceship_t spaceship, game_state_t state);




#endif // SPACESHIP_H

