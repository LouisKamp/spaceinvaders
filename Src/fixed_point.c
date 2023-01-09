/*
 * fixed_point.c
 *
 *  Created on: 5. jan. 2023
 *      Author: louiss
 */

#include "fixed_point.h"

void print_fix(int32_t i) {

    // Prints a signed 16.16 fixed point number
	if ((i & 0x80000000) != 0) { // Handle negative numbers
		printf("-");
		i = ~i + 1;
	}

	printf("%ld.%04ld", i >> 16, 10000 * (uint32_t)(i & 0xFFFF) >> 16);
	// Print a maximum of 4 decimal digits to avoid overflow
}

fix_16_16_t convert_2_14_to_16_16(fix_2_14_t i) {
    // Converts an 18.14 fixed point number to 16.16
	return i << 2;
}

fix_16_16_t fixed_point_sin(int32_t angle) {
	int32_t value_2_14;

	if (angle < 0) {
		value_2_14 = -SIN[-angle & 0x1FF]; // format 2.14
	} else {
		value_2_14 = SIN[angle & 0x1FF]; // format 2.14
	}


	return convert_2_14_to_16_16(value_2_14); // format 16.16
}

fix_16_16_t fixed_point_cos(int32_t angle) {
	return fixed_point_sin(angle + 128);
}

void rotate_vector(vector_t* vector, int32_t angle) {
	int32_t x = vector->x;
	int32_t y = vector->y;
	vector->x = x*fixed_point_cos(angle)-y*fixed_point_sin(angle);
	vector->y = x*fixed_point_sin(angle)+y*fixed_point_cos(angle);
}



