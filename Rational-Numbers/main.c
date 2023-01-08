#include "rational_numbers.h"
#include <stdio.h>

int main(void)
{
    uint16_t x = 9;
    rational_t r = { -1, 2 };
    float actual = exp_real(x, r);
    printf("actual = %f\n", actual);

    return 0;
}
