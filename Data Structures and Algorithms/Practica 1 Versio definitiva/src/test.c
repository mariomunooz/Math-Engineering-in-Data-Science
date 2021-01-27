#include "test.h"

#define DICTIONARY_FILEPATH "../data/data_dict.tsv"
#define DICTIONARY_TEST_FILEPATH "../data/test_dict.tsv"

void load_dictionary_test(HashTable *dictionary, char *filepath) {
    if (dictionary->size > 0) clear_table(dictionary); // clear if dictionary is not empty
    init_table(dictionary); // reset it

    WordInfo wi;
    FILE *fd = fopen(filepath, "r");
    if (fd != NULL) {
        int count = 0;
        char line[MAX_LENGTH];
        while (fgets(line, MAX_LENGTH, fd) != NULL) {
            char *ptr = line;
            char *w = mystrsep(&ptr, "\t");
            char *d = mystrsep(&ptr, "\t");
            char c = ptr[0]; //there's a '\n' after that which we just ommit
            str_to_lowercase(w);
            wi = create_word_info(w, d, c);
            if (insert_word_info(dictionary, wi)) count++;
        }
        fclose(fd);
    }
}

void print_test_result(char *str, bool status) {
    if (status == true) {
        printf("%s : %s \n", str, "passed!");
    } else {
        printf("%s : %s \n", str, "failed!");
    }
}

void test_hash_function() {
    printf("__________________________________________________\n");
    //We have added these bars to clearly see the development of the program
    int status = true;
//    printf("%d\n", hash_function("0"));
    if (hash_function("a") != 0) status = false;
    if (hash_function("hello") != 7) status = false;
    if (hash_function("z") != 25) status = false;
    if (hash_function("0") != -1) status = false;
    print_test_result("Test hash_function", status);
}

void test_init_table() {
    printf("__________________________________________________\n");
    HashTable dictionary;
    init_table(&dictionary);
    int status = true;
    if (dictionary.size != 0) status = false;
    for (int i = 0; i < N; ++i) {
        if (dictionary.list[i].start != NULL) status = false;
    }
    print_test_result("Test init_table", status);
}

void test_clear_table() {
    printf("__________________________________________________\n");
    HashTable dictionary;
    init_table(&dictionary);

    clear_table(&dictionary);
    int status = true;
    if (dictionary.size != 0) status = false;
    for (int i = 0; i < N; ++i) {
        if (dictionary.list[i].start != NULL) status = false;
    }
    print_test_result("Test clear_table", status);
}

void test_find_word_info() {
    printf("__________________________________________________\n");
    HashTable dictionary;
    load_dictionary_test(&dictionary, DICTIONARY_FILEPATH);
    int old_size = dictionary.size;
    int status = true;
    WordInfo wi;
    strcpy(wi.word, "stigmatizationxxx");
    wi.category = 'N';
    strcpy(wi.definition, "Testing");
    insert_word_info(&dictionary, wi);

    if (dictionary.size != old_size + 1) status = false;
    WordInfo *word = find_word_info(dictionary, "stigmatizationxxx");
    if(word == NULL) status = false;
    print_test_result("Test find_word_info", status);
}

void test_insert_word_info() {
    printf("__________________________________________________\n");
    HashTable dictionary;
    load_dictionary_test(&dictionary, DICTIONARY_FILEPATH);
    int old_size = dictionary.size;
    int status = true;
    WordInfo wi;
    strcpy(wi.word, "stigmatizationxxx");
    wi.category = 'N';
    strcpy(wi.definition, "Testing");
    insert_word_info(&dictionary, wi);

    if (dictionary.size != old_size + 1) status = false;
    WordInfo *word = find_word_info(dictionary, "stigmatizationxxx");
    if(word == NULL) status = false;
    print_test_result("Test insert_word_info", status);
}

void test_delete_word_info() {
    printf("__________________________________________________\n");
    HashTable dictionary;
    load_dictionary_test(&dictionary, DICTIONARY_FILEPATH);
    int status = true;
    WordInfo wi;
    strcpy(wi.word, "stigmatizationxxx");
    wi.category = 'N';
    strcpy(wi.definition, "Testing");
    insert_word_info(&dictionary, wi);

    WordInfo *word = find_word_info(dictionary, "stigmatizationxxx");
    if(word == NULL) status = false;

    if (word && strcmp(word->word, "stigmatizationxxx") != 0) status = false;

    int dict_size = dictionary.size;
    delete_word_info(&dictionary, "stigmatizationxxx");
    if(dictionary.size != dict_size - 1) status = false;
    //Here we have changed the +1 for -1 because we think it was a mistake

    WordInfo *word2 = find_word_info(dictionary, "stigmatizationxxx");
    if (word2 != NULL) status = false;
    print_test_result("Test delete_word_info", status);
}
void test_save_dictionary_to_file(){
    printf("__________________________________________________\n");
    HashTable dictionary;
    load_dictionary_test(&dictionary, DICTIONARY_FILEPATH);
    int status = true;
    WordInfo wi;
    strcpy(wi.word, "stigmatizationxxx");
    wi.category = 'N';
    strcpy(wi.definition, "Testing");
    insert_word_info(&dictionary, wi);
    int dict_size = dictionary.size;

    save_dictionary_to_file(dictionary, DICTIONARY_TEST_FILEPATH);
    load_dictionary_test(&dictionary, DICTIONARY_TEST_FILEPATH);
    if(dictionary.size != dict_size) status = false;

    WordInfo *word = find_word_info(dictionary, "stigmatizationxxx");
    if(word == NULL) status = false;

    if (word && strcmp(word->word, "stigmatizationxxx") != 0) status = false;

    remove(DICTIONARY_TEST_FILEPATH); // remove file after testing

    print_test_result("Test save_dictionary_to_file", status);
    printf("__________________________________________________\n");
}
void run_testing() {
    test_hash_function();
    test_init_table();
    test_clear_table();
    test_find_word_info();
    test_insert_word_info();
    test_delete_word_info();
    test_save_dictionary_to_file();
}