#include <stdlib.h>

const int * binary_search(int array[], int element, int length)
{
    if(length == 0) return (int*) NULL;
    
    int start = 0;
    int end = length;
    int middle = 0;

    while ((end - start) > 1)
    {
        middle = (start + end)/2;
        if (element < array[middle])
            end = middle;
        else
            start = middle;
    }

    return (element == array[start] ? &array[start] : (int*) NULL);
}