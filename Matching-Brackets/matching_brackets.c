#include "matching_brackets.h"
#include <string.h>
#include <stdlib.h>

#define IS_OPEN_BRACKET(c) ((c == 40 || c == 91 || c == 123) ? true : false)

bool is_paired(const char *input)
{
    size_t length = strlen(input);
    char *stack = calloc(length, sizeof(char));
    int j = -1;

    for (size_t i = 0; i <= length; i++)
    {
        char c = input[i];

        if (c != 40 && c != 41 && c != 91 && c != 93 && c != 123 && c != 125)
        {
            continue;
        }
        else
        {
            if (IS_OPEN_BRACKET(c))
            {
                j++;
                stack[j] = c;
            }
            else
            {
                if (j < 0)
                {
                    free(stack);
                    return false;
                }
                else if (c == 41)
                {
                    if (stack[j] == 40)
                    {
                        stack[j] = 0;
                        j--;
                    }
                    else
                    {
                        free(stack);
                        return false;
                    }
                }
                else if (c == 93)
                {
                    if (stack[j] == 91)
                    {
                        stack[j] = 0;
                        j--;
                    }
                    else
                    {
                        free(stack);
                        return false;
                    }
                }
                else if (c == 125)
                {
                    if (stack[j] == 123)
                    {
                        stack[j] = 0;
                        j--;
                    }
                    else
                    {
                        free(stack);
                        return false;
                    }
                }
            }
        }
    }

    free(stack);

    if (j == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}