#include "utils.h"
#include "hash_table.h"
#include "test.h"

#define BASE_DATA_DIR "../data"

HashTable dictionary;
char dictionary_filepath[MAX_LENGTH];

void press_enter_to_continue(){
    char line[100];
    printf("\nPress Enter to continue...");
    fflush(stdout);
    fgets(line, sizeof(line), stdin);
}

void load_dictionary(HashTable *dictionary, char *filepath) {
    if(dictionary->size > 0) clear_table(dictionary); // clear if dictionary is not empty
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
        printf("Loaded! There are %d new entries.\n", count);
    } else {
        printf("Error! Could not load data, check file '%s' is not missing.\n", filepath);
    }
}

void menu_load_dictionary(HashTable *dictionary) {
    char filename[MAX_LENGTH];
    printf("*** Hint: enter file name or leave it empty for the default *** \n");
    scan_line("Enter dictionary file (default: data_dict.tsv): ", "%s", &filename);
    if (strlen(filename) == 0) {
        strcpy(filename, "data_dict.tsv");
    }
    join_path(dictionary_filepath, BASE_DATA_DIR, filename);

    if (exists(dictionary_filepath) == true) {
        load_dictionary(dictionary, dictionary_filepath);
    } else {
        printf("Error: file \"%s\" does not exist!\n", dictionary_filepath);
    }
}

void menu_find_word(HashTable dictionary) {
    if(dictionary.size > 0){
        char word[MAX_WORD_LENGTH];
        WordInfo *pwi;
        scan_line("Enter word: ", "%s", word);
        str_to_lowercase(word);
        pwi = find_word_info(dictionary, word);
        if (pwi) {
            printf("Found!\n");
            print_word_info(*pwi);
        } else{
            printf("Not found!\n");
        }
    }else{
        printf("The dictionary is empty!\n");
        printf("Choose option 1 to load a dictionary or option 3 to add more words.\n");
    }
}

void menu_add_new_word(HashTable *dictionary) {
    char word[MAX_WORD_LENGTH];
    char definition[MAX_DEFINITION_LENGTH];
    char category;

    scan_line("Enter word: ", "%s", word);
    scan_line("Enter definition: ", "%s", definition);
    scan_line("Enter category (N, V, ...): ", "%c", &category);
    str_to_lowercase(word);
    str_to_lowercase(definition);
    WordInfo wi = create_word_info(word, definition, category);
    if (insert_word_info(dictionary, wi)) {
        printf("New word is added!\n");
    } else {
        printf("Error! The word \"%s\" already exists.\n", word);
    }
}

void menu_delete_word(HashTable *dictionary) {
    if(dictionary->size > 0){
        char word[MAX_WORD_LENGTH];
        scan_line("Enter word: ", "%s", word);
        str_to_lowercase(word);
        bool deleted = delete_word_info(dictionary, word);
        if (deleted) {
            printf("Deleted!\n");
        } else {
            printf("Not found!\n");
        }
    }else{
        printf("Dictionary is empty!\n");
        printf("Choose option 1 to load a dictionary.\n");
    }
}

void menu_save_dictionary(HashTable dictionary){
    if(dictionary.size > 0){
        char filename[MAX_LENGTH];
        char filepath[MAX_LENGTH];
        scan_line("Enter file name (e.g.: es_dict.tsv): ", "%s", &filename);
        if(strlen(filename) > 0){
            join_path(filepath, BASE_DATA_DIR, filename);
            if (exists(filepath) == false) {
                save_dictionary_to_file(dictionary, filepath);
            } else {
                printf("File \"%s\" already exists!\n", filepath);
                char confirmation[5];
                scan_line("Do you want to overwrite? [Yes/No]:", "%s", &confirmation);
                str_to_lowercase(confirmation);
                if(strcmp(confirmation, "yes") == 0){
                    save_dictionary_to_file(dictionary, filepath);
                }else{
                    printf("The dictionary is not saved!\n");
                }
            }
        }else{
            printf("File name cannot be empty!\n");
        }
    }else{
        printf("The dictionary is empty. Nothing to save! \n");
    }
}

int main(int argc, char *argv[]) {
    printf("ENTRA");
    int option = -1;
    while (option != 0) {
        printf("\n========= Menu ===========\n");
        printf("1. Load dictionary\n");
        printf("2. Find a word\n");
        printf("3. Add a new word\n");
        printf("4. Delete a word\n");
        printf("5. Display dictionary\n");
        printf("6. Save dictionary to file\n");
        printf("7. Test\n");
        printf("0. Exit\n");
        printf("==========================\n");

//        printf("5. Find words listed in file.\n");
        option = -1;
        scan_line("Select an option: ", "%d", &option);
        printf("\n");
        switch (option) {
            case 1:
                // Load dictionary
                menu_load_dictionary(&dictionary);
                press_enter_to_continue();
                break;
            case 2: // Find a word
                menu_find_word(dictionary);
                press_enter_to_continue();
                break;
            case 3: // Add new word
                menu_add_new_word(&dictionary);
                press_enter_to_continue();
                break;
            case 4: // Delete a word
                menu_delete_word(&dictionary);
                press_enter_to_continue();
                break;
            case 5: // print the whole dictionary
                if(dictionary.size > 0){
                    print_table(dictionary);
                }else{
                    printf("The dictionary is empty!\n");
                }
                press_enter_to_continue();
                break;
            case 6:
                menu_save_dictionary(dictionary);
                press_enter_to_continue();
                break;
            case 7: // run testing
                run_testing();
                press_enter_to_continue();
                break;
            case 0: // Exit the program
                printf("Exited!\n");
                break;

            default:
                printf("Invalid option.\n");
                press_enter_to_continue();
        }
    }
    clear_table(&dictionary);
    return 0;
}