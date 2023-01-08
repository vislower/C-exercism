#include "rail_fence_cipher.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

char *encode(char *text, size_t rails)
{
    if (rails == 0)
    {
        return NULL;
    }
    
    size_t length = strlen(text);
    char **cipher_array = malloc(rails*sizeof(char*));
    for (size_t k = 0; k < rails; k++)
    {
        cipher_array[k] = calloc(length, sizeof(char));
    }
    char *encoded_text = malloc(length*sizeof(char));

    bool go_down = true;
    int i = 0;
    size_t j;
    int l = 0;
    for (j = 0; j < length; j++)
    {
        if (go_down)
        {
            cipher_array[i][j] = text[j];
            if (i < (int)rails - 1)
            {
                i++; // go down
            }
            else
            {
                go_down = !go_down; // change direction
                i--;
            }
        }
        else // go up
        {
            cipher_array[i][j] = text[j];
            if (i > 0)
            {
                i--; // go up
            }
            else
            {
                go_down = !go_down; // change direction
                i++;
            }
        }
    }

    for (size_t y = 0; y < rails; y++)
    {
        for (size_t x = 0; x < length; x++)
        {
            if (cipher_array[y][x] != 0)
            {
                encoded_text[l] = cipher_array[y][x];
                l++;
            }
        }
        
    }
    
    for (size_t k = 0; k < rails; k++)
    {
        free(cipher_array[k]);
    }
    free(cipher_array);
    return encoded_text;
}

char *decode(char *ciphertext, size_t rails)
{   
    if (rails == 0)
    {
        return NULL;
    }

    size_t length = strlen(ciphertext);
    char **cipher_array = malloc(rails*sizeof(char*));
    for (size_t k = 0; k < rails; k++)
    {
        cipher_array[k] = calloc(length, sizeof(char));
    }
    char *decoded_text = malloc(length*sizeof(char));

    bool go_down = true;
    int i = 0;
    size_t j;
    for (j = 0; j < length; j++)
    {
        if (go_down)
        {
            cipher_array[i][j] = '*';
            if (i < (int)rails - 1)
            {
                i++; // go down
            }
            else
            {
                go_down = !go_down; // change direction
                i--;
            }
        }
        else // go up
        {
            cipher_array[i][j] = '*';
            if (i > 0)
            {
                i--; // go up
            }
            else
            {
                go_down = !go_down; // change direction
                i++;
            }
        }
    }

    int l = 0;
    for (size_t y = 0; y < rails; y++)
    {
        for (size_t x = 0; x < length; x++)
        {
            if (cipher_array[y][x] == '*')
            {
                cipher_array[y][x] = ciphertext[l];
                l++;
            }
            
        }
        
    }
    
    go_down = true;
    i = 0;
    int m = 0;
    for (j = 0; j < length; j++)
    {
        if (go_down)
        {
            decoded_text[m] = cipher_array[i][j];
            m++;
            if (i < (int)rails - 1)
            {
                i++; // go down
            }
            else
            {
                go_down = !go_down; // change direction
                i--;
            }
        }
        else // go up
        {
            decoded_text[m] = cipher_array[i][j];
            m++;
            if (i > 0)
            {
                i--; // go up
            }
            else
            {
                go_down = !go_down; // change direction
                i++;
            }
        }
    }

    for (size_t k = 0; k < rails; k++)
    {
        free(cipher_array[k]);
    }
    free(cipher_array);
    return decoded_text;
}