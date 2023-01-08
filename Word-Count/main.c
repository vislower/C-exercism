#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "word_count.h"


int main(void)
{
    char phrase[] = "\"That's the password: 'PASSWORD 123'!\", cried the Special Agent.\nSo I fled.";
    word *words = malloc(sizeof(word) * strlen(phrase));
    int number_of_words = 0;

    number_of_words = count_words(phrase, words);

    for (int i = 0; i < number_of_words; i++)
    {
        for (int j = 0; j < words[i].length; j++)
        {
            printf("%c", tolower(*(words[i].start+j)));
        }
        printf(": %d\n", words[i].count);
    }

    free(words);
    return 0;
}
