
#include <stdlib.h>
#include <string.h>

#include "commons.h"
#include "tree.h"



// NODE

void clearPostOrder(Node* node)
{
    if (node == NULL){
        return;
    }
    else {
        clearPostOrder(node->left_child);
        clearPostOrder(node->right_child);
        printf("The word %s has been removed\n", node->data.word);
        free(node);
        printf("Without errors\n");
    }
        printf("________________________________________________\n");
    }

Node *createNode(WordInfo wi)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = wi;
    newNode->left_child = newNode->right_child = NULL;
    return newNode;
}

Node* insertNode(Node* node, WordInfo wi){

    if (node == NULL){
        node = createNode(wi);
    } else {

        if (strcmp(wi.word, node->data.word) > 0){
            node->right_child = insertNode(node->right_child, wi);

        } else if (strcmp(wi.word, node->data.word) < 0){
            node->left_child = insertNode(node->left_child, wi);
        }
    } return node;
}

Node* findNode(Node* node, char* word) {
    if (node == NULL|| strcmp(node->data.word, word) == 0)
        return node;

    if (strcmp(word, node->data.word) > 0)
        return findNode(node->right_child, word);

    return findNode(node->left_child, word);

}
void printInOrder(Node* node)
{
    if (node == NULL){
        return;
    }
    else
    {
        printInOrder(node->left_child);
        print_word_info(node->data);
        printInOrder(node->right_child);
    }

}
// TREE

void init_tree(Tree* t){
    Node* first = NULL;
    t->root = first;
    t->size = 0;

}

void clear_tree(Tree* t){
    Node* current = t->root;
    clearPostOrder(current);
    init_tree(t);

}



void insert_into_tree(Tree* t, WordInfo wi){
    if(!findNode(t->root, wi.word)){
        t->root = insertNode(t->root, wi);
        t->size++;
    }
}

WordInfo* find_in_tree(Tree* t, char* word){

    Node* finding = findNode(t->root, word);
    if (finding == NULL) return NULL;

    return &(finding->data);
}

int size_tree(Tree* t){

    return t->size;
}

void print_tree(Tree* t){
    Node* current = t->root;
    printInOrder(current);

}

