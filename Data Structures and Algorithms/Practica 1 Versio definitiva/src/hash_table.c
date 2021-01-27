#include "hash_table.h"

/**
 * TODO: OK Compute the hash key of a word by mapping the first letter to an integer.
 * There are N=26 possible keys (only low-case letters are considered, it is
 * assumed that all capital letters have been changed using lower_case). If a
 * character not in [a-z] is given, -1 is returned.
 * 
 * Return the hash key (0-25) or -1.
*/
int hash_function(char* word) {
    // Gets the first letter of the word and considering it is a lower case, we substract a value of 97 in order to know
    //its equivalent from 0 to 26. Then this last value is returned. In any other case, -1 is returned.
    int hash_key = -1;
    int first_letter = word[0];

    if (first_letter >= 97 && first_letter <= 122){
        hash_key = first_letter -97;
    }
    return hash_key;
}

/**
 * TODO: OK Initialize the members of the HashTable struct: its size and all the lists
*/
void init_table(HashTable* dictionary) {
    // For every position in the dictionary out of 26 (N), the list is initialized through init_list
    dictionary->size = 0;
    for (int i = 0; i < N; i++){
        init_list(&(dictionary->list[i]));
    }

}

/**
 * TODO: OK Clear all lists leaving the HashTable struct as if it was just initialized.
*/
void clear_table(HashTable* dictionary) {
    // For every position in the dictionary out of 26 (N), the list is cleared through clear_list
    for (int i = 0; i < N; i++){
        clear_list(&(dictionary->list[i]));
        dictionary->size = 0;
    }


}

/**
 * TODO: OK Look for the WordInfo corresponding to a word by checking which list to search
 * and calling find_in_list.
 * 
 * Return a pointer to the WordInfo if found or NULL otherwise.
*/
WordInfo* find_word_info(HashTable dictionary, char* word) {
    // knowing the word, we find the hash key through hash_function(). If it is not -1,we find the node with find_in_list()
    //If the data exists we return it. For any other case, NULL is returned
    int hash_key = hash_function(word);
    if  (hash_key != -1){
        Node* n = find_in_list(&dictionary.list[hash_key], word);
        if (n != NULL) return &(n->data);
    }

    return NULL;
}

/**
 * TODO: OK Insert a WordInfo into the dictionary except if a WordInfo with the same word
 * already exists in the dictionary.
 * 
 * Return true if insertion was succesful or false otherwise.
*/
bool insert_word_info(HashTable* dictionary, WordInfo wi) {
    // With the word we got on wi we find the hash key needed for the specific word using  hash_function().
    //Then we do the same to find the node using find_in_list(). If the nude is NULL as it should, we insert there the info
    //got on wi using insert_into_list.mAfter that we increment +1 the dictionary's size.
    int hash_key = hash_function(wi.word);
    if  (hash_key != -1){
        Node* n = find_in_list(&dictionary->list[hash_key], wi.word);
        if (n == NULL){
            insert_into_list(&(dictionary->list[hash_key]), wi);
            ++dictionary->size;
            return true;
        }
    }

    return false;

}

/**
 * TODO: OK Delete the WordInfo corresponding to word from the dictionary by checking from
 * which list to delete it and calling delete_from_list.
 * 
 * Return true if a WordInfo for the given word was present in the dictionary
 * and could be deleted succesfully or false otherwise.
*/
bool delete_word_info(HashTable* dictionary, char* word) {
    // Knowing the word we find the hash key using hash_function(). f it is not -1 we delete that word's information
    //through delete_from_list(). After that we decrement -1 the size of the dictionary.
    bool deleted = false;
    int hash_key = hash_function(word);
    if(hash_key != -1){
        deleted = delete_from_list(&(dictionary->list[hash_key]), word);
        if (deleted) --dictionary->size;
    }
    return deleted;
}

/**
 * TODO: OK Print the number of words in the dictionary followed by the information of
 * each word, one per line. In the case that there are no words in the
 * dictionary it prints "The dictionary is empty".
*/
void print_table(HashTable dictionary) {
    //We check firstly that the dictionary is not empty. Then, if it is not, its size is printed. After it, for every
    //of the 26 hash keys, it's list is printed using print_list
    if (dictionary.size){
        printf("The dictionary has %d words\n", dictionary.size);
        for(int i = 0; i < N; ++i){
            print_list(&dictionary.list[i]);
        }
    } else{
        printf("the dictionary is empty. \n");
    }

}

/*
 * TODO: Save content of the dictionary to file
 * write line: fprintf(fd, "%s\t%s\t%c\n", wi.word, wi.definition, wi.category);
 */
void save_dictionary_to_file(HashTable dictionary, char *filepath){
    // Here we have taken the same structure as for print table but instead of print in the terminal,
    // we have created a file from the filepath and we have printed the hash table inside the file
    if (dictionary.size){
        FILE *fd = fopen(filepath, "w");
        for (int i = 0; i < N; i++){
            print_list_in_file(fd, &dictionary.list[i]);
        }
        printf("Dictionary has %i words.\n", dictionary.size);
        printf("Completed! Saved the dictionary to \"%s\"\n", filepath);
        fclose(fd);
    }else{
        printf("Error! the dictionary is empty. \n");
    }

}