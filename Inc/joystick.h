

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

#include "gpio.h"
#include "stm32f30x_conf.h"
#include <stdio.h>
#include <types.h>
#include "led.h"

joystick_input_t read_joystick();
color_t input_to_color(joystick_input_t joystick_input);

#endif /* JOYSTICK_H_ */
