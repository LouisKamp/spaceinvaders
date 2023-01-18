/*
 * fixed_point.c
 *
 *  Created on: 5. jan. 2023
 *      Author: louiss
 */

#include "fixed_point.h"


void print_fix(fix_t i) {

	// Prints a signed 11.5 fixed point number
	if ((i & 0b1 << 15) != 0) { // Handle negative numbers
		printf("-");
		i = ~i + 1;
	}

	printf("%ld.%04ld", i >> FIX_SHIFT, 1000 * (uint32_t)(i & 0b0000000000011111) >> 16);
	// Print a maximum of 4 decimal digits to avoid overflow
}
