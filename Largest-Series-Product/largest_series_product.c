#include "largest_series_product.h"
#include <string.h>
#include <ctype.h>

int64_t largest_series_product(char *digits, size_t span)
{
    size_t length = strlen(digits);
    if (span > length) return -1;
    int64_t largest_product = 0;
    for (size_t i = 0; i <= length-span; i++)
    {
        int64_t tmp = 1;
        for (size_t j = i; j < span+i; j++)
        {
            if (isalpha(digits[j])) return -1;
            tmp *= (int64_t)(digits[j] - '0');
        }
        if (tmp > largest_product) largest_product = tmp;
    }
    return largest_product;
}