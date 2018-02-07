#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binarytree.h"
#include "treehelper.h"

Node*
initializenode(Node* root, int len)
{
    root = (Node*) malloc(sizeof(Node));
    root->words = (char**) malloc(64*sizeof(char*));
    root->length = len;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void
addwordtonode(Node* root, char* word)
{
    root->count++;
    root->words[root->count-1] = (char*) malloc(64*sizeof(char));
    strcpy(root->words[root->count-1], word);
}

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
    printnode(root);
    inorder(root->right);
}

void
preorder(Node* root)
{
    if (root == NULL)
        return;
    printnode(root);
    preorder(root->left);
    preorder(root->right);
}

void
postorder(Node* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printnode(root);
}

void
printnode(Node* node)
{
    printf("%d\n", node->length);
    int i;
    for (i = 0; i < node->count; i++) {
        printf("%s\n", node->words[i]);
    }
}