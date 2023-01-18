
#include "spaceship.h"

void initialize_spaceship(spaceship_t* spaceship) {
	spaceship->x = TO_FIX(20);
	spaceship->y = TO_FIX(20);
	spaceship->vx = TO_FIX(2);
	spaceship->vy = TO_FIX(5);
	spaceship->life = 3;
	spaceship->weapon = spaceship->y + 2;
	spaceship->countdown = 0;
}
void draw_spaceship(spaceship_t spaceship, uint8_t* buffer) {
	if (spaceship.state == 0) {
		int32_t mat[10][5] = { {0,1,0,1,0}, {0,0,0,0,0}, {0,1,0,1,0}, {1,0,1,0,1}, {1,1,0,1,1},{1,1,1,1,1},{1,1,1,1,1},{0,1,0,1,0}, {0,0,1,0,0} };
		lcd_write_custom(10, 5, mat, TO_INT(spaceship.x), TO_INT(spaceship.y), buffer);
	}
	else {
		int32_t mat[11][7] = { {0,0,1,0,1,0,0},{0,0,0,0,0,0,0},{0,0,1,0,1,0,0},{0,0,0,1,0,0,0},{0,1,0,0,0,1,0},{0,1,1,0,1,1,0},{0,1,1,1,1,1,0},{1,1,1,1,1,1,1},{1,0,1,0,1,0,1},{1,0,0,1,0,0,1},{1,0,0,0,0,0,1} };
		lcd_write_custom(11, 7, mat, TO_INT(spaceship.x), TO_INT(spaceship.y), buffer);
	}
}

void draw_spaceship_health(spaceship_t spaceship, uint8_t* buffer) {
	if (spaceship.life > 0) {
		int32_t mat[9][7] = { {0,1,1,0,0,0,0}, {1,1,1,1,0,0,0},{1,1,1,1,1,0,0},{0,1,1,1,1,1,0},{0,0,1,1,1,1,1},{0,1,1,1,1,1,0},{1,1,1,1,1,0,0},{1,1,1,1,0,0,0},{0,1,1,0,0,0,0} };

		for (int8_t i = 0; i < spaceship.life; i++) {
			lcd_write_custom(9, 7, mat, 0, 0 + 11 * i, buffer);
		}
	}
}

void update_spaceship(joystick_input_t input, spaceship_t* spaceship) {

	// UPDATE POSITION
	uint8_t spaceship_pos_x = TO_INT(spaceship->x);
	uint8_t spaceship_pos_y = TO_INT(spaceship->y);
	uint8_t top_most_value = 0;
	uint8_t bottom_most_value = 25;
	uint8_t right_most_value = 122;
	uint8_t left_most_value = 0;

	// UP
	if (is_input(input, JOYSTICK_UP) && top_most_value < spaceship_pos_x) {
		spaceship->x -= TO_FIX(1);
	}

	// DOWN
	if (is_input(input, JOYSTICK_DOWN) && spaceship_pos_x < bottom_most_value) {
		spaceship->x += TO_FIX(1);
	}

	// LEFT
	if (is_input(input, JOYSTICK_LEFT) && left_most_value < spaceship_pos_y) {
		spaceship->y -= TO_FIX(1);
	}

	// RIGHT
	if (is_input(input, JOYSTICK_RIGHT) && spaceship_pos_y < right_most_value) {
		spaceship->y += TO_FIX(1);
	}

	// HANDLE SPACESHIP POWERUP STATE
	// when countdown is done, switch back to normal state
	if (spaceship->state == SPACESHIP_POWERUP_STATE && spaceship->countdown == 0) {
		spaceship->state = SPACESHIP_NORMAL_STATE;
	}
	else if (spaceship->countdown != 0) {
		// else keep on counting down
		spaceship->countdown -= 1;
	}

}


void spaceship_shoot(spaceship_t spaceship, game_state_t state) {
	if (spaceship.state == 0) {
		create_bullet(spaceship.x + TO_FIX(2), spaceship.y + TO_FIX(10), TO_FIX(0), TO_FIX(1), state);
	}
	else {
		create_bullet(spaceship.x + TO_FIX(0), spaceship.y + TO_FIX(15), TO_FIX(0), TO_FIX(1), state);
		create_bullet(spaceship.x + TO_FIX(6), spaceship.y + TO_FIX(15), TO_FIX(0), TO_FIX(1), state);
	}
}


