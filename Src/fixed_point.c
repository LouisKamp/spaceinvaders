/*
 * fixed_point.c
 *
 *  Created on: 5. jan. 2023
 *      Author: louiss
 */

#include "fixed_point.h"


#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )


#define FIX_SHIFT 5
#define FIX_MULT(a, b) (int16_t)( ((int32_t) a)*((int32_t) b) >> FIX_SHIFT )
#define FIX_MULT(a, b) (int16_t)( ((int32_t) a)/((int32_t) b) << FIX_SHIFT )


void print_fix(fix_t i) {

	// Prints a signed 11.5 fixed point number
	if ((i & 0b1 << 15) != 0) { // Handle negative numbers
		printf("-");
		i = ~i + 1;
	}

	printf("%ld.%04ld", i >> FIX_SHIFT, 1000 * (uint32_t)(i & 0b0000000000011111) >> 16);
	// Print a maximum of 4 decimal digits to avoid overflow
}

fix_t convert_2_14_to_11_5(fix_2_14_t i) {
	// Converts an 2.14 fixed point number to 11.5
	return i >> 9;
}

fix_t fixed_point_sin(int32_t angle) {
	fix_2_14_t res;

	if (angle < 0) {
		res = -SIN[-angle & 0x1FF]; // format 2.14
	}
	else {
		res = SIN[angle & 0x1FF]; // format 2.14
	}


	return convert_2_14_to_11_5(res); // format 16.16
}

fix_t fixed_point_cos(int32_t angle) {
	return fixed_point_sin(angle + 128);
}

void rotate_vector(vector_t* vector, int32_t angle) {
	int32_t x = vector->x;
	int32_t y = vector->y;
	vector->x = x * fixed_point_cos(angle) - y * fixed_point_sin(angle);
	vector->y = x * fixed_point_sin(angle) + y * fixed_point_cos(angle);
}



