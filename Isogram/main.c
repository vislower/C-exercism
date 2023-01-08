#include <stdio.h>
#include "isogram.h"

int main(void)
{
    char str[] = "lumberjacks";
    printf("%s", is_isogram(str) ? "Is isogram\n" : "Isn't isogram\n"); 
    return 0;
}
