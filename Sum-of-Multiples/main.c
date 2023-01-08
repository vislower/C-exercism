#include "sum_of_multiples.h"
#include <stdio.h>


int main(void)
{
    const unsigned int factors[2] = { 3, 5 };
    unsigned int s = 0;

    s = sum(factors, 2, 20);
    printf("sum of multiples = %d\n", s);

    return 0;
}
