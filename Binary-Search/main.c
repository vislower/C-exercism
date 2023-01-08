#include "binary_search.h"
#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int length = sizeof(arr)/sizeof(int);
    const int *index = binary_search(arr, 7, length);
    printf("%d\n", *index);
    return 0;
}
