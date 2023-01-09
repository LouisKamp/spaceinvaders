#ifndef FIXED_POINT_H_
#define FIXED_POINT_H_

#include <stdio.h>
#include "LUTsin.h"

typedef struct {
    int32_t x, y;
} vector_t;


typedef uint32_t fix_16_16_t;
typedef uint32_t fix_2_14_t;

void print_fix(int32_t i);
fix_16_16_t convert_2_14_to_16_16(fix_2_14_t i);
fix_16_16_t fixed_point_cos(int32_t angle);
fix_16_16_t fixed_point_sin(int32_t angle);

void rotate_vector(vector_t* vector, int32_t angle);


#endif /* FIXED_POINT_H_ */