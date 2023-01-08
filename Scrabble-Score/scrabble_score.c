#include "scrabble_score.h"
#include <ctype.h>
#include <stddef.h>

unsigned int score(const char *word)
{
    int SCORES[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    unsigned int score = 0;
    char c;
    for (size_t i = 0; (c = tolower(word[i])) != '\0'; i++)
    {
        score += SCORES[c-'a'];
    }
    return score;
}