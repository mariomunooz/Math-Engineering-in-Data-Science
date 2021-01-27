#include <stdio.h>
#include <string.h>
#include "word_info.h"
#include "file_utils.h"

void print_word_info(WordInfo wi) {
    printf("-> %s (%c): %s\n", wi.word, wi.pos, wi.definition);
}

// Returns the word to be used for hashing
void create_word_info(WordInfo* wi, char* word, char* definition, char pos) {
    // creates a WordInfo object and initializes it by copying the introduced word, definition and category.
    strcpy(wi->word, word);
    strcpy(wi->definition, definition);
    wi->pos = pos;

}
