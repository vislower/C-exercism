#include "run_length_encoding.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define IS_DIGIT(c) ((c >= 48 && c <= 57) ? true : false)

char *encode(const char *text)
{
    size_t length = strlen(text);
    if (length == 0)
    {
        char *t = malloc(sizeof(char));
        t[0] = '\0';
        return t;
    }
        
    char *buffer = calloc(length * 2, sizeof(char));
    char *multi_digit_number = calloc(length, sizeof(char));
    char *encoded_text;
    char old_character = text[0];
    char character = 0;
    int count = 0;
    size_t k = 0;

    for (size_t i = 0; i <= length; i++)
    {
        character = text[i];

        if (old_character == character)
        {
            count++;
        }
        else
        {
            if (count > 1)
            {
                int count_length = sprintf(multi_digit_number, "%d", count);
                strncpy((buffer+k), multi_digit_number, count_length);
                k += count_length;
            }
            buffer[k] = old_character;
            k++;
            count = 1;
        }
        old_character = character;
    }

    encoded_text = malloc((k+1) * sizeof(char));
    strncpy(encoded_text, buffer, k);
    encoded_text[k] = '\0';

    free(buffer);
    free(multi_digit_number);

    return encoded_text;
}


char *decode(const char *data)
{
    size_t length = strlen(data);
    if (length == 0)
    {
        char *d = malloc(sizeof(char));
        d[0] = '\0';
        return d;
    }
    
    char *decoded_text = malloc(1024*sizeof(char));
    char character = 0;
    char old_character = 0;
    int count = 0;
    char *count_start;
    int k = 0;

    for (size_t i = 0; i <= length ; i++)
    {
        character = data[i];

        if (IS_DIGIT(character) && !IS_DIGIT(old_character))
        {
            count_start = (char *)(data + i);
        }
        else if (!IS_DIGIT(character) && IS_DIGIT(old_character))
        {
            char *count_end = &character;
            count = (int)strtol(count_start, &count_end, 10);
            int j = 0;
            while (j < count)
            {
                decoded_text[k] = character;
                k++;
                j++;
            }
        }
        else if (!IS_DIGIT(character) && !IS_DIGIT(old_character))
        {
            decoded_text[k] = character;
            k++;
        }
        old_character = character;
    }
    decoded_text[k] = '\0';

    return decoded_text;
}