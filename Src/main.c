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
#include "i2c.h"
#include "powerup.h"
#include "score.h"

uint8_t render_buffer[512] = {};
uint8_t waiting_for_render = 0;
uint32_t time = 0;


// Tactic: do all the calculations in while and the push the local buffer to the render buffer, that is updated ever xx seconds.

int main(void) {
	init_pins();
	lcd_init();
	init_interrupts();
	I2C_init();
	I2C_Write(0b10011000, 0x07, 0x01); // INIT accelerometer


	spaceship_t player_spaceship;
	initialize_spaceship(&player_spaceship);


	asteroid_t asteroid[NASTEROIDS] = {};
	uint8_t num_asteroid = 0;

	bullet_t bullets[NBULLETS] = {};
	uint8_t num_bullets = 0;


	enemy_t enemies[NENEMIES] = {};
	uint8_t num_enemy = 0;

	enemy_t explosions[NEXPLOSIONS] = {};
	uint8_t num_explosions = 0;

	powerup_t powerups[NPOWERUPS] = {};
	uint8_t num_powerups = 0;

	uint8_t screen = START_SCREEN;

	joystick_input_t joystick_input;

	joystick_input_t accelerometer_input;

	uint32_t score = 0;

	uint8_t local_buffer[512] = {};

	game_state_t game_state;
	game_state.buffer = local_buffer;
	game_state.player = &player_spaceship;

	game_state.powerups = powerups;
	game_state.num_powerups = &num_powerups;

	game_state.bullets = bullets;
	game_state.num_bullet = &num_bullets;

	game_state.asteroids = asteroid;
	game_state.num_asteroid = &num_asteroid;

	game_state.enemies = enemies;
	game_state.num_enemy = &num_enemy;

	game_state.screen = &screen;
	game_state.joystick_input = &joystick_input;
	game_state.accelerometer_input = &accelerometer_input;

	game_state.explosions = explosions;
	game_state.num_explosions = &num_explosions;

	game_state.score = &score;

	game_state.time = &time;

	initialize_powerup(TO_FIX(10), TO_FIX(10), &powerups[0]);



	while (1) {
		if (!waiting_for_render) {
			waiting_for_render = 1;
			lcd_clear(&local_buffer);
			joystick_input = read_joystick();
			accelerometer_input = read_accelerometer();

			switch (screen) {
			case START_SCREEN:
				make_start_screen("Press down to start", game_state);
				break;
			case GAME_SCREEN:
				make_game_screen(game_state);
				break;
			case HELP_SCREEN:
				make_help_screen(game_state);
				break;
			case BOSS_SCREEN:
				make_boss_screen(game_state);
				break;
			case GAMEOVER_SCREEN:
				make_gameover_screen(game_state);
				break;
			}

			memcpy(render_buffer, local_buffer, sizeof(render_buffer));
		}
	}
}

void TIM2_IRQHandler(void) {
	lcd_push_buffer(&render_buffer);
	waiting_for_render = 0;
	time += 1;
	TIM2->SR &= ~0x0001; // Clear interrupt bit
}




