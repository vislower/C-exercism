#include "sum_of_multiples.h"
#include <stdlib.h>
#include <stdbool.h>


unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
    unsigned int *multiples = calloc(limit, sizeof(unsigned int));
    if (multiples == NULL)
    {
        exit(EXIT_FAILURE);
    }

    unsigned int sum = 0;
    unsigned int factor;
    size_t k = 0;
    bool exist = false;
    for (size_t i = 0; i < number_of_factors; i++)
    {
        factor = factors[i];
        if (factor == 0)
            continue;
        
        unsigned int multiple = 0;
        unsigned int j = 1;
        while ((multiple + factor) < limit)
        {
            exist = false;
            multiple = factor * j;
            for (size_t h = 0; h < k; h++)
            {
                if (multiple == multiples[h])
                {
                    exist = true;
                }
            }
            if (!exist)
            {
                multiples[k] = multiple;
                sum += multiple;
                k++;
            }
            j++;
        }
        
    }

    free(multiples);
    multiples = NULL;

    return sum;
}