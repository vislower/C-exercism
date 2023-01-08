#include "crypto_square.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define IS_LETTER(c) (c >= 97 && c <= 122 ? true:false)
#define IS_DIGIT(c) (c >= 48 && c <= 57 ? true:false)

char *ciphertext(const char *input)
{
    size_t initial_length = strlen(input);
    char *normalized_text;
    if (initial_length == 0)
    {
        normalized_text = calloc(1, sizeof(char));
        normalized_text[0] = '\0';
        return normalized_text;
    }
    
    normalized_text = calloc(initial_length, sizeof(char));
    
    /* TEXT NORMALIZATION */
    char character = 0;
    size_t k = 0; // counter for normalized_text
    for (size_t i = 0; i < initial_length; i++)
    {
        character = tolower(input[i]);
        if (IS_LETTER(character) || IS_DIGIT(character))
        {
            normalized_text[k] = character;
            k++;
        }
    }
    
    /* FIND c AND r */
    int length = (int)k; // length of the normalized text
    int c = 0;
    int r = 0;
    bool stop = false;
    for (c = 0; c < length; c++)
    {
        for (r = 0; r <= c; r++)
        {
            if (r * c >= length && c-r <= 1)
            {
                stop = true;
                break;
            }
        }
        if(stop)
            break;
    }

    /* CREATE CIPHER TEXT */
    char *cipher_text = calloc((c*r+c), sizeof(char));
    int l = 0; // counter for cipher_text
    for (int i = 0; i < c; i++)
    {
        for (int j = i; j <= (c*(r-1)+i); j+=c)
        {
            if (j >= length)
            {
                cipher_text[l] = ' ';
                
            }
            else
            {
                cipher_text[l] = normalized_text[j];
            }
            l++;
        }
        cipher_text[l] = ' ';
        l++;
    }
    cipher_text[l-1] = '\0';

    return cipher_text;
}