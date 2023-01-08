#include "difference_of_squares.h"
#include <stdio.h>

int main(void)
{
    long n = 10;
    long a = square_of_sum(10);
    long b = sum_of_squares(10);
    long diff = difference_of_squares(10);

    printf("Square of sum          : %ld\n", a);
    printf("Sum of squares         : %ld\n", b);
    printf("Difference of squares  : %ld\n", diff);

    return 0;
}
