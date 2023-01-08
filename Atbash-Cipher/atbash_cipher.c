#include "atbash_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define IS_LETTER(c) (c >= 97 && c <= 122 ? true:false)
#define IS_DIGIT(c) (c >= 48 && c <= 57 ? true:false)

char *atbash_encode(const char *input)
{
    size_t length = strlen(input);
    char *encoded_text = calloc(2*length+1, sizeof(char)); // arbitrary size of 2*length + '\0'

    char c = 0;
    size_t j = 0; // counter for encoded_text
    int count = 0;
    for (size_t i = 0; i <= length; i++)
    {
        if (count == 5 && i < length-1) // i < length - 1 because we dont want any spaces at the end of the word
        {
            encoded_text[j] = ' ';
            j++;
            count = 0;
        }

        c = tolower(input[i]);
        if (IS_LETTER(c))
        {
            encoded_text[j] = (122 - c%97);
            j++;
            count++;
        }
        else if (IS_DIGIT(c) || c == '\0')
        {
            encoded_text[j] = c;
            j++;
            count++;
        }
    }
    return encoded_text;
}


char *atbash_decode(const char *input)
{
    size_t length = strlen(input);
    char *decoded_text = calloc(2*length+1, sizeof(char)); // arbitrary size of 2*length + '\0'

    char c = 0;
    size_t j = 0; // counter for decoded_text
    for (size_t i = 0; i <= length; i++)
    {
        c = input[i];
        if (IS_LETTER(c))
        {
            decoded_text[j] = (122 - c%97);
            j++;
        }
        else if (IS_DIGIT(c) || c == '\0')
        {
            decoded_text[j] = c;
            j++;
        }
    }
    return decoded_text;
}