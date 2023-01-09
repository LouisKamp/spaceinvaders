/*
 * led.h
 *
 *  Created on: 5. jan. 2023
 *      Author: louiss
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f30x_conf.h"
#include <stdio.h>

typedef uint8_t color_t;

void set_led(color_t color); // RGB

#endif /* LED_H_ */
