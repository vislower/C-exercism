#include "nth_prime.h"
#include <stdbool.h>

uint32_t nth(uint32_t n)
{
    uint32_t prime_n = 0, k = 0; // k = prime numbers counter
    uint32_t i = 2;
    bool is_prime = true;
    while (k != n)
    {
        is_prime = true;
        for (uint32_t j = 2; j*j <= i; j++) // j*j because we search only up to sqrt(i)
        {
            if (i%j == 0)
            {
                is_prime = false;
                break;
            }
            
        }
        if (is_prime)
        {
            prime_n = i;
            k++;
        }
        i++;
    }
    
    return prime_n;
}