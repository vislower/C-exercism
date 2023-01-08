#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    size_t k = 0;
    for (size_t i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            factors[k++] = i;
            n /= i;
        }
    }
    return k;
}