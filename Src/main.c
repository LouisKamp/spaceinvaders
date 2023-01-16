#include "explosion.h"
#include "types.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "gpio.h"
#include "led.h"
#include "lcd.h"
#include "spaceship.h"
#include "interrupts.h"
#include "screens.h"
#include "asteroid.h"
#include "enemy.h"
#include "bullet.h"
#include "asteroid.h"

uint8_t render_buffer[512] = {};
uint8_t waiting_for_render = 0;



// Tactic: do all the calculations in while and the push the local buffer to the render buffer, that is updated ever xx seconds.

int main(void) {
	init_pins();
	lcd_init();
	uart_init(9600);
	init_interupts();

	set_led(0b000);


	spaceship_t player_spaceship;
	initialize_spaceship(&player_spaceship);


	asteroid_t asteroid[NASTEROID] = {};
	uint8_t num_asteroid = 0;

	bullet_t bullets[NBULLETS] = {};
	uint8_t num_bullets = 0;


	enemy_t enemies[NENEMY] = {};
	uint8_t num_enemy = 0;

	enemy_t explosions[NEXPLOSIONS] = {};
	uint8_t num_explosions = 0;


	uint8_t screen = 0;

	joystick_input_t joystick_input;

	uint8_t local_buffer[512] = {};

	game_state_t game_state;
	game_state.buffer = local_buffer;
	game_state.player = &player_spaceship;
	game_state.bullets = bullets;
	game_state.num_bullet = &num_bullets;

	game_state.asteroid = asteroid;
	game_state.num_asteroid = num_asteroid;

	game_state.enemies = enemies;
	game_state.num_enemy = &num_enemy;

	game_state.screen = &screen;
	game_state.joystick_input = &joystick_input;

	game_state.explosions = explosions;
	game_state.num_explosions = &num_explosions;

	initialize_enemy(&enemies[0]);
	initialize_asteroid(TO_FIX(10), TO_FIX(80),&asteroid[0]);

	while (1) {
		if (!waiting_for_render) {
			waiting_for_render = 1;
			lcd_clear(&local_buffer);
			joystick_input = read_joystick();

			switch (screen) {
			case 0:
				make_start_screen("Press down to start", game_state);
				break;
			case 1:
				make_game_screen(game_state);
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



