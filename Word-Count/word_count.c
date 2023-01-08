#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "word_count.h"

bool is_valid_c(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <=90) || (c >= 97 && c <= 122))
    {
        return true;
    }
    return false;
}

word new_word(char* start, int length)
{
    word w;
    w.start = start;
    w.length = length;
    w.count = 1;
    return w;
}

bool word_comparason(word words[], word w, int j)
{   
    char c;
    char c_w;
    bool same_words = true;
    for (int i = 0; i < j; i++) // loop to iterate through all the previous saved words
    {
        same_words = true;
        if (w.length == words[i].length)
        {
            for (int k = 0; k < w.length; k++) // loop to iterate through all the characters of each word
            {
                c = tolower(*(words[i].start + k)); // character of the word to which we are comparing w
                c_w = tolower(*(w.start + k)); // character of the word argument : w
                //printf("c : %c  c_w : %c\n", c, c_w);
                if (c != c_w)
                {
                    // the two words are not the same
                    same_words = false;
                    //printf("not same word\n");
                    break;
                }
            }
            if (same_words)
            {
                words[i].count++;
                //printf("same word\n");
                return true;
            }
        }
    }
    // add new word w to words[]
    words[j] = w;
    return false;
}

int count_words(char phrase[], word words[])
{
    int i = 0;
    int j = 0;
    char c;
    bool valid_c = false; // true if character before was a valid letter, otherwise false
    char* word_start = NULL;
    int word_length = 0;
    while (i < (int)strlen(phrase)+1)
    {
        c = phrase[i];

        if (is_valid_c(c))
        {
            // it's a valid letter
            if (!valid_c)
            {
                // begin of a word
                word_start = &phrase[i];
                word_length++;
                valid_c = true;
            }else
            {
                word_length++;
            }
        }
        else if (c == 39 && valid_c && is_valid_c(phrase[i+1]))
        {
            word_length++;
        }
        else
        {
            if (valid_c)
            {
                word w = new_word(word_start, word_length);
                bool res = word_comparason(words, w, j);
                if (!res)
                {
                    j++;
                }
                valid_c = false;
                word_length = 0;
                word_start = NULL;
            }
            
        }
        i++;
    }
    return j; // return the number of different words
}