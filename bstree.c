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

// Check if word in node, return:
// 1 - yes
// 0 - no
int
isinnode(Node* node, char* word)
{
    int i;
    for (i = 0; i < node->count; i++) {
        if (!strcmp(node->words[i], word)) 
            return 1;
    } 
    return 0;
}

void
inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\n", root->length);
    inorder(root->right);
    printnode(root);
}

void
preorder(Node* root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->length);
    preorder(root->left);
    preorder(root->right);
    printnode(root);
}

void
postorder(Node* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->length);
    printnode(root);
}

void
printnode(Node* node)
{
    int i;
    for (i = 0; i < node->count; i++) {
        printf("%s\n", node->words[i]);
    }
}