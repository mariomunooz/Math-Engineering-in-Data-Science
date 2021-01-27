#include "word_info.h"


void init_data(WordInfo* data){
    strcpy(data->word, "");
    strcpy(data->definition, "");
    data->category = ' ';
}
/*
 * TODO: OK create object WordInfo from these infos
 */


WordInfo create_word_info(char *word, char *definition, char category) {
    // creates a WordInfo object and initializes it by copying the introduced word, definition and category.
    WordInfo info;
    strcpy(info.word, word);
    strcpy(info.definition, definition);
    info.category = category;
    return info;

}

/*
 * Print WordInfo to the screen.
 */
void print_word_info(WordInfo wi) {
    printf("%s (%c): %s\n", wi.word, wi.category, wi.definition);
}

void print_word_info_in_file(FILE* fa, WordInfo wi){
    //Function used to print in the file one Node of the linked list
    fprintf(fa, "%s\t%s\t%c\n", wi.word, wi.definition, wi.category);

}