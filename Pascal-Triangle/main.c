#include <stdio.h>
#include "pascals_triangle.h"


int main(void)
{
    size_t rows = 1;
    uint8_t **triangle = create_triangle(rows);
    
    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            printf("[%ld][%ld] = %d\n", i, j, triangle[i][j]);
        }
        
    }

    free_triangle(triangle, rows);

    return 0;
}
