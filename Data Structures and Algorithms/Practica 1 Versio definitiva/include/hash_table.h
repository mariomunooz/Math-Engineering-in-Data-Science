#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "utils.h"
#include "linked_list.h"

#define N 26          // number of slots in the hash dictionary (number of letters)

/*
 * HashTable data structure has 26 elements of LinkedList
 * Each LinkedList stores words corresponding to its alphabet order from a to z.
 * E.g.
 * list[0] stores words starting with a: apple, alpha, etc.
 * list[1] stores words starting with b: big, boy, etc.
 * .
 * .
 * list[25] z: zebra, zinc, etc.
 */
typedef struct {
    LinkedList list[N];
    int size;
} HashTable;

/*
 * Compute the hash key of a word by mapping the first letter to an integer.
 */
int hash_function(char *word);

/*
 * Initialize the members of the HashTable struct: its size and all the lists
 */
void init_table(HashTable* dictionary);

/*
 * Clear all lists leaving the HashTable struct as if it was just initialized.
 */
void clear_table(HashTable* dictionary);

/*
 * Insert a WordInfo into the dictionary except if a WordInfo with the same word
 * already exists in the dictionary.
 *
 * Return true if insertion was succesful or false otherwise.
*/
bool insert_word_info(HashTable* dictionary, WordInfo wi);

/*
 * Look for the WordInfo corresponding to a word by checking which list to search and calling find_in_list.
 * Return a pointer to the WordInfo if found or NULL otherwise.
 */
WordInfo* find_word_info(HashTable dictionary, char* word);

/**
 * Delete the WordInfo corresponding to a word from the dictionary by checking from
 * which list to delete it and calling delete_from_list.
 *
 * Return true if a WordInfo for the given word was present in the dictionary
 * and could be deleted successfully or false otherwise.
*/
bool delete_word_info(HashTable* dictionary, char* word);

/*
 * Print the number of words in the dictionary followed by the information of
 * each word, one per line. In the case that there are no words in the
 * dictionary it prints "The dictionary is empty".
*/
void print_table(HashTable dictionary);

/*
 * Save content of the dictionary to a file
 */
void save_dictionary_to_file(HashTable dictionary, char *filepath);
#endif
