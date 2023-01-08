#include <stdbool.h>
#include <string.h>

bool is_isogram(const char *str)
{
    int word_length = strlen(str);
    char c;

    for (int i = 0; i < word_length; i++)
    {
        c = str[i];

        if(c == ' ' || c == '-')
            continue;

        for (int j = i+1; j < word_length; j++)
        {
            if(str[i] == str[j])
                return false;
        }
    }
    return true;
}