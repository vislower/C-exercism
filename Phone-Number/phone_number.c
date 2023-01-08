#include "phone_number.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define IS_DIGIT(c) (c >= 48 && c <= 57 ? true:false)

char *phone_number_clean(const char *input)
{
    char *output = calloc(11, sizeof(char));
    char digit = 0;
    size_t index = 0;
    for (size_t i = 0; (digit = input[i]) && digit!='\0'; i++)
    {
        if (!IS_DIGIT(digit) || (index == 0 && digit == '1'))
            continue;
        if ((index == 0 && digit < '2') || (index == 3 && digit < '2') || index > 10)
            break;
        output[index++] = digit;
    }
    if (index != 10)
        strcpy(output, "0000000000");
    else
        output[index] = '\0';
    return output;
}    