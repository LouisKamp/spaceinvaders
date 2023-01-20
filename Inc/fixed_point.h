#ifndef FIXED_POINT_H_
#define FIXED_POINT_H_

#include <stdio.h>
#include "types.h"

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )

#define FIX_SHIFT 5
#define FIX_MULT(a, b) (int16_t)( ((int32_t) a)*((int32_t) b) >> FIX_SHIFT )
#define FIX_DIVD(a, b) (int16_t)( ((int32_t) a)/((int32_t) b) << FIX_SHIFT )
#define TO_FIX(a) (fix_t) ((a) << FIX_SHIFT)
#define TO_INT(a) (int16_t) ((a) >> FIX_SHIFT)


void print_fix(fix_t i);


#endif /* FIXED_POINT_H_ */
