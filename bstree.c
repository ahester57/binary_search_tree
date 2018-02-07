#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bstree.h"

Node*
insert(Node* root, char* word)
{
    int len = strlen(word);
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        root->words = (char**) malloc(64*sizeof(char*));
        root->count = 1;
        root->words[root->count-1] = (char*) malloc(64*sizeof(char));
        strcpy(root->words[root->count-1], word);
        root->length = len;
        root->left = NULL;
        root->right = NULL;
    } else if (len == root->length) {
        // add this word to this node   
        root->count++;
        root->words[root->count-1] = (char*) malloc(64*sizeof(char));
        strcpy(root->words[root->count-1], word);
    } else if (len < root->length) {
        root->left = insert(root->left, word);
    } else {
        root->right = insert(root->right, word);
    }
    return root;
}

Node*
search(Node* root, char* word)
{
    int len = strlen(word);
    if (root == NULL || root->length == len) {
        return root;
    }

    if (root->length < len) {
        return search(root->right, word);
    }

    return search(root->left, word);
}

Node*
delete(Node* root, int len)
{
    // @TODO
    return root;
}