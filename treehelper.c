#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treehelper.h"
#include "bstree.h"

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
    printnode(root);
    inorder(root->right);
}

void
preorder(Node* root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->length);
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