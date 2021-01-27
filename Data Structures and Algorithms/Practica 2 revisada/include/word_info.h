#ifndef WORDINFO_H
#define WORDINFO_H

#define MAX_WORD_LENGTH 30
#define MAX_DEFINITION_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char definition[MAX_DEFINITION_LENGTH];
    char pos;     // Part of speech
} WordInfo;

void create_word_info(WordInfo* wi, char* word, char* definition, char pos);
void print_word_info(WordInfo wi);

#endif
