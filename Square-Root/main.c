#include <stdio.h>
#include "square_root.h"

int main(void)
{
    int n = 2;
    float result = babylonian_method(n);
    float result2 = exponetial_method(n);
    printf("Babylonian method  : %d² = %f\n", n, result);
    printf("Exponential method : %d² = %f\n", n, result2);
    return 0;
}
