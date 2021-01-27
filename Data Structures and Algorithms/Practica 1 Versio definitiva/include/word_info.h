#ifndef WORDINFO_H
#define WORDINFO_H

#include "utils.h"

/*
 * WordInfo data structure containing: word, part of speech, and definition
 */
typedef struct {
    char word[MAX_WORD_LENGTH];
    char definition[MAX_DEFINITION_LENGTH];
    char category; // Part of speech
} WordInfo;

/*
 * Create object WordInfo from the given word, part of speech and definition.
 */
WordInfo create_word_info(char* word, char* definition, char pos);

/*
 * Print WordInfo to the screen.
 */
void print_word_info(WordInfo wi);

void init_data(WordInfo* data);

void print_word_info_in_file(FILE* fa, WordInfo wi);

#endif
