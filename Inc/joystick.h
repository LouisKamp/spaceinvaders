

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include "gpio.h"
#include "stm32f30x_conf.h"
#include <stdio.h>
#include <types.h>
#include "led.h"

#define JOYSTICK_UP (1 << 0) 
#define JOYSTICK_DOWN (1 << 1) 
#define JOYSTICK_LEFT (1 << 2) 
#define JOYSTICK_RIGHT (1 << 3) 
#define JOYSTICK_CENTER (1 << 4) 

joystick_input_t read_joystick();
color_t input_to_color(joystick_input_t joystick_input);

#endif /* JOYSTICK_H_ */
