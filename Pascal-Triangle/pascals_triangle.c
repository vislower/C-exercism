#include "pascals_triangle.h"
#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(triangle[i]);
        triangle[i] = NULL;
    }

    free(triangle);
    triangle = NULL;
}



uint8_t **create_triangle(size_t rows)
{
    // MEMORY ALLOCATION
    uint8_t **triangle = NULL;
    triangle = malloc(rows * sizeof(uint8_t*));
    if (triangle == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < rows; i++)
    {
        triangle[i] = malloc(rows * sizeof(uint8_t));
        if (triangle[i] == NULL)
        {
            exit(EXIT_FAILURE);
        }
    }

    // FILLING THE TRIANGLE WITH NUMBERS
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < rows ; j++)
        {
            if (j == 0 || j == i)
            {
                triangle[i][j] = 1;
            }
            else if (j > i)
            {
                triangle[i][j] = 0;
            }
            else
            {
                triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
            }
        }
    }
    
    return triangle;
}