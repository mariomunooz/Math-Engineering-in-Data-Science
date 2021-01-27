#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "utils.h"
#include "word_info.h"

/*
 * Element of the LinkedList containing: WordInfo, pointer to previous and next nodes.
 */
typedef struct _Node {
    WordInfo data;
    struct _Node* next;
    struct _Node* prev;
} Node;

/*
 * LinkedList data structure containing a start Node
 */
typedef struct {
    Node* start;
} LinkedList;

/*
 * Initialize the start Node pointer so that the list is empty.
 */
void init_list(LinkedList *l);

/*
 * Clear all the nodes of the list, freeing the memory and leaving the list as
 * it would have just been initialized.
 */
void clear_list(LinkedList *l);

/*
 * Reserve memory for a new Node and inserts it in the given linked list,
 * changing the start pointer as well as the prev/next pointers accordingly.
*/
void insert_into_list(LinkedList *l, WordInfo c);

/*
 * Iterate over the different nodes searching for a WordInfo that contains the given word.
 * Return: A pointer to the node if found or NULL otherwise.
*/
Node* find_in_list(LinkedList* l, char* word);

/*
 * Given a node and the list it belongs to, remove it from the list freeing
 * its memory. It accounts for the start, and the prev/next pointers.
*/
void delete_node(LinkedList* l, Node* p);

/*
 * If a node in the list contains a WordInfo with the given word, delete it.
 * Return true if a node is deleted and false otherwise.
*/
bool delete_from_list(LinkedList* l, char* word);

/*
 * Print all word infos of the list using print_word_info.
*/
void print_list(LinkedList* l);

void print_list_in_file(FILE* fa, LinkedList* l);

#endif
