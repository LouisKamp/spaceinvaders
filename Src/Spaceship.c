
#include "spaceship.h"

void initialize_spaceship(spaceship_t* s) {
	s->x = TO_FIX(20);
	s->y = TO_FIX(20);
	s->vx = TO_FIX(2);
	s->vy = TO_FIX(5);
	s->life = 3;
	s->weapon = s->y + 2;
	s->countdown = 0;
}
void draw_spaceship(spaceship_t* s, uint8_t* buffer) {
	if (s->state == 0) {
		int32_t mat[10][5] = { {0,1,0,1,0}, {0,0,0,0,0}, {0,1,0,1,0}, {1,0,1,0,1}, {1,1,0,1,1},{1,1,1,1,1},{1,1,1,1,1},{0,1,0,1,0}, {0,0,1,0,0} };
		lcd_write_custom(10, 5, mat, TO_INT(s->x), TO_INT(s->y), buffer);
	}
	else {
		int32_t mat[11][7] = { {0,0,1,0,1,0,0},{0,0,0,0,0,0,0},{0,0,1,0,1,0,0},{0,0,0,1,0,0,0},{0,1,0,0,0,1,0},{0,1,1,0,1,1,0},{0,1,1,1,1,1,0},{1,1,1,1,1,1,1},{1,0,1,0,1,0,1},{1,0,0,1,0,0,1},{1,0,0,0,0,0,1} };
		lcd_write_custom(11, 7, mat, TO_INT(s->x), TO_INT(s->y), buffer);
	}
}

void draw_spaceship_health(game_state_t state) {
	if (0 < state.player->life) {
		int32_t mat[9][7] = { {0,1,1,0,0,0,0}, {1,1,1,1,0,0,0},{1,1,1,1,1,0,0},{0,1,1,1,1,1,0},{0,0,1,1,1,1,1},{0,1,1,1,1,1,0},{1,1,1,1,1,0,0},{1,1,1,1,0,0,0},{0,1,1,0,0,0,0} };

		for (int8_t i = 0; i < state.player->life; i++) {
			lcd_write_custom(9, 7, mat, 0, 0 + 11 * i, state.buffer);
		}

	}
}

void remove_spaceship(spaceship_t* s) {
	getxy(s->y, s->x);
	printf("%c", 32);
	getxy((s->y + 1), s->x);
	printf("%c", 32);
	getxy((s->y + 1), (s->x + 2));
	printf("%c", 32);
	getxy((s->y + 1), (s->x - 2));
	printf("%c", 32);
	getxy((s->y + 2), (s->x));
}


void update_spaceship(joystick_input_t input, spaceship_t* s) {
	// UP
	if ((input & JOYSTICK_UP) && (0 < TO_INT(s->x))) {
		s->x -= TO_FIX(1);
	}

	// DOWN
	if ((input & JOYSTICK_DOWN) && (TO_INT(s->x) < 25)) {
		s->x += TO_FIX(1);
	}

	// LEFT
	if ((input & JOYSTICK_LEFT) && (0 < TO_INT(s->y))) {
		s->y -= TO_FIX(1);
	}

	// RIGHT
	if ((input & JOYSTICK_RIGHT) && (TO_INT(s->y) < 122)) {
		s->y += TO_FIX(1);
	}

	if (s->state == 1 && s->countdown == 0) {
		s->state = 0;
	}
	else if (s->countdown != 0) {
		s->countdown--;
	}

}


void spaceship_shoot(spaceship_t* spaceship, game_state_t state) {
	if (spaceship->state == 0) {
		create_bullet(spaceship->x + TO_FIX(2), spaceship->y + TO_FIX(10), TO_FIX(0), TO_FIX(1), state);
	}
	else {
		create_bullet(spaceship->x + TO_FIX(0), spaceship->y + TO_FIX(15), TO_FIX(0), TO_FIX(1), state);
		create_bullet(spaceship->x + TO_FIX(6), spaceship->y + TO_FIX(15), TO_FIX(0), TO_FIX(1), state);
	}
}


