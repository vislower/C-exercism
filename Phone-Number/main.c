#include "phone_number.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *cleaned = phone_number_clean("1 (123) 156-7890");
    printf("%s\n", cleaned);
    free(cleaned);
    return 0;
}
