#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "gpio.h"
#include "led.h"
#include "lcd.h"
#include "spaceship.h"
#include "interrupts.h"
#include "screens.h"
#include "bullet.h"

uint8_t local_buffer[512] = {};
uint8_t render_buffer[512] = {};
uint8_t waiting_for_render = 0;



// Tactic: do all the calculations in while and the push the local buffer to the render buffer, that is updated ever xx seconds.

int main(void) {
	init_pins();
	lcd_init();
	init_interupts();
	set_led(0b000);


	uint8_t game_state = 0; // start screen


	spaceship_t myspaceship;
	initialize_spaceship(&myspaceship);
	bullet_t mybullet;

	// initialize_bullet(&myspaceship,&mybullet);

	// draw_bullet(input,&mybullet,&buffer);
	// remove_bullet(&myspaceship,&mybullet,&buffer);


	while (1) {
		if (!waiting_for_render) {
			waiting_for_render = 1;
			lcd_clear(&local_buffer);

			switch (game_state) {
			case 0:
				make_start_screen("Press down to start", &local_buffer, &game_state);
				break;




			case 1:
				make_game_screen(&myspaceship, &local_buffer, &game_state);
				break;
			}

			memcpy(render_buffer, local_buffer, sizeof(render_buffer));
		}
	}
}


void TIM2_IRQHandler(void) {
	lcd_push_buffer(&render_buffer);
	waiting_for_render = 0;
	TIM2->SR &= ~0x0001; // Clear interrupt bit
}




