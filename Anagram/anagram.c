#include "anagram.h"
#include <string.h>
#include <strings.h>
#include <ctype.h>


void find_anagrams(const char *subject, struct candidates *candidates)
{
    for (size_t i = 0; i < candidates->count; i++)
    {
        /* create a cand string for each candidate */
        char cand[MAX_STR_LEN];
        strcpy(&cand, candidates->candidate[i].word);

        /* cand isn't an anagram if it is longer than subject or if it is the same word as subject */
        candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        if (strlen(subject) != strlen(cand) || strcasecmp(subject, cand) == 0)
        {
            continue;
        }

        /* create letters repetition set for subject and cand */
        char subject_letters[26] = {0};
        for (size_t j = 0; j < strlen(subject); j++)
        {
            if (isalpha(subject[j]))
                subject_letters[toupper(subject[j]) - 'A']++;
        }
        char cand_letters[26] = {0};
        for (size_t j = 0; j < strlen(cand); j++)
        {
            if (isalpha(cand[j]))
                cand_letters[toupper(cand[j]) - 'A']++;
        }

        /* check if these two sets are the same */
        candidates->candidate[i].is_anagram = IS_ANAGRAM;
        for (size_t j = 0; j < 26; j++)
        {
            if (cand_letters[j] != subject_letters[j])
            {
                candidates->candidate[i].is_anagram = NOT_ANAGRAM;
                break;
            }
        }
    }
}