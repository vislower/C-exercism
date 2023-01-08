#ifndef __WORD_COUNT__H__
#define __WORD_COUNT__H__
#include <stdbool.h>
typedef struct word
{
    int length;
    int count;
    char* start;
} word;

bool is_valid_c(char c);
word new_word(char* start, int length);
bool word_comparason(word words[], word w, int j);
int count_words(char phrase[], word words[]);

#endif