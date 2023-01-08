#include "largest_series_product.h"
#include <stdio.h>

int main()
{
    int64_t largest = largest_series_product("12345", -1);
    printf("largest = %ld\n", largest);
    return 0;
}
