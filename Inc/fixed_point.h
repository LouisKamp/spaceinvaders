#ifndef FIXED_POINT_H_
#define FIXED_POINT_H_

#include <stdio.h>
#include "types.h"
#include "LUTsin.h"

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )


#define FIX_SHIFT 5
#define FIX_MULT(a, b) (int16_t)( ((int32_t) a)*((int32_t) b) >> FIX_SHIFT )
#define FIX_MULT(a, b) (int16_t)( ((int32_t) a)/((int32_t) b) << FIX_SHIFT )
#define TO_FIX(a) (fix_t) (a << FIX_SHIFT)
#define TO_INT(a) (int16_t) (a >> FIX_SHIFT)


void print_fix(fix_t i);
fix_t convert_2_14_to_16_16(fix_2_14_t i);
fix_t fixed_point_cos(int32_t angle);
fix_t fixed_point_sin(int32_t angle);



void rotate_vector(vector_t* vector, int32_t angle);


#endif /* FIXED_POINT_H_ */
