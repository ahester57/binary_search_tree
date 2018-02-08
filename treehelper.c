#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treehelper.h"
#include "tree.h"

node_t*
initializenode(node_t* root, int len, int level)
{
    root = (node_t*) malloc(sizeof(node_t));
    root->words = (char**) malloc(64*sizeof(char*));
    root->length = len;
    root->depth = level;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void
addwordtonode(node_t* root, char* word)
{
    root->count++;
    root->words[root->count-1] = (char*) malloc(64*sizeof(char));
    strcpy(root->words[root->count-1], word);
}

// 1 - yes
// 0 - no
int
isinnode(node_t* node, char* word)
{
    int i;
    for (i = 0; i < node->count; i++) {
        if (!strcmp(node->words[i], word)) 
            return 1;
    } 
    return 0;
}

void
inorder(node_t* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printnode(root, 1);
    inorder(root->right);
}

void
preorder(node_t* root)
{
    if (root == NULL)
        return;
    printnode(root, 1);
    preorder(root->left);
    preorder(root->right);
}

void
postorder(node_t* root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printnode(root, 1);
}

void
printnode(node_t* node, int level)
{
    printf("%*c", node->depth*4, ' ');
    printf("%d ", node->length);
    int i;
    for (i = 0; i < node->count; i++) {
        printf("%s ", node->words[i]);
    }
    printf("\n");
}