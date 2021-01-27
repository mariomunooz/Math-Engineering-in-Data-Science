#include "linked_list.h"

/**
 * TODO: OK Initialize the start Node pointer so that the list is empty.
*/
void init_list(LinkedList* l) {
    Node* first = NULL;
    l->start = first;
}

/**
 * TODO: OK Clear all the nodes of the list, freeing the memory and leaving the list as
 * it would have just been initialized.
*/
void clear_list(LinkedList *l) {
    // It starts from the first node on the list and advances clearing the nodes through free() function until it founds
    //a non initialized node
    Node* current = l->start;
    Node* aux = NULL;
    while (current != NULL){
        aux = current->next;
        free(current);
        current = aux;
    }
    l->start = NULL;
}

/**
 * TODO: OK Reserve memory for a new Node and inserts it in the given linked list,
 * changing the start pointer as well as the prev/next pointers accordingly.
*/
void insert_into_list(LinkedList* l, WordInfo c) {
    // Reserves the memory using a malloc of Node size. Then initializes the node's data with the info entered when calling
    //this function. After that, it changes the pointers as it's needed to advance on the list properly.
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = c;

    newNode->next = l->start;
    if (l->start != NULL){
        l->start->prev = newNode;
    }
    newNode->prev = NULL;
    l->start = newNode;

}

/**
 * TODO: OK Iterate over the different nodes searching for a WordInfo that contains the given word.
 * Return: A pointer to the node if found or NULL otherwise.
*/
Node* find_in_list(LinkedList* l, char* word) {
    // We have changed the first parameter from value to reference here and on their declaration linkedlist.h for using this function
    // in the function delete from the list
    Node *current = l->start;
    bool equal;
    while (current != NULL) {
        if (strcmp(current->data.word, word) == 0) {
            equal = true;
            printf("The word %s is in the dictionary\n", word);
            return current;
        } else {
            equal = false;
        }
        current = current->next;

    }
    printf("The word %s is not in the dictionary\n", word);
    return NULL;
}
/**
 * TODO: OK Given a node and the list it belongs to, it removes it from the list freeing
 * its memory. It accounts for the start, and the prev/next pointers.
*/
void delete_node(LinkedList* l, Node* p) {
    // The node is cleared using function free(). Before that, it changes the pointers of its previous and next nodes so
    //they become consecutive in the list. A printf() is added to corroborate the operation has been successful
    if (p->prev != NULL){
        p->prev->next = p->next;
    }
    else{
        l->start = p->next;
    }
    if (p->next != NULL){
        p->next->prev = p->prev;
    }
    free(p);
    printf("The word has been removed\n");
}

/**
 * TODO: OK If a node in the list contains a WordInfo with the given word, it deletes it.
 * Return true if a node was deleted and false otherwise.
*/
bool delete_from_list(LinkedList* l, char* word) {
    // To delete the node parting from the word, first we identify the node the word corresponds to through find_in_list()
    //function. Once knowing the node we delete it using delete_node() and the function returns true. If there's no node
    //with that word, it returns false
    Node* supr = find_in_list(l, word);
    if (supr != NULL){
        printf("And it's going to be removed\n");
        delete_node(l, supr);
        return true;
    } else{
        return false;
    }
}

/**
 * TODO: OK Print all word infos of the list using print_word_info.
*/
void print_list(LinkedList* l) {
    //We have changed the first parameter to a pointer here and on the declaration
    Node* current = l->start;
    while (current != NULL){
        print_word_info(current->data);
        current = current->next;
    }

}

void print_list_in_file(FILE* fa, LinkedList* l){
    //We use this function to print each linkedlist of the hash table in the file
    Node* current = l->start;
    while (current != NULL){
        print_word_info_in_file(fa, current->data);
        current = current->next;
    }
}