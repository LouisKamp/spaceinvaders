#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "gpio.h"
#include "led.h"
#include "lcd.h"
#include "spaceship.h"
#include "interrupts.h"

uint8_t buffer[512] = {};
spaceship_t myspaceship;

int main(void) {
	init_pins();
	lcd_init();
	init_interupts();

	initialize_spaceship(&myspaceship);


	while(1) {}
}


void TIM2_IRQHandler(void) {


	lcd_clear(&buffer);
	joystick_input_t input = read_joystick();
	update_spaceship_postition(input, &myspaceship);
	draw_spaceship(&myspaceship, &buffer);
	lcd_push_buffer(&buffer);

	TIM2->SR &= ~0x0001; // Clear interrupt bit
}


