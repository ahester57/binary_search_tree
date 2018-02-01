#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bstree.h"

Node*
insert(Node* root, int val)
{
    if (root == NULL) {
        root = malloc(sizeof(Node));
        root->value = val;
        root->left = NULL;
        root->right = NULL;
    } else if (val < root->value) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

Node*
search(Node* root, int val)
{
    if (root == NULL || root->value == val)
        return root;

    if (root->value < val)
        return search(root->right, val);

    return search(root->left, val);
}

void
inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\n", root->value);
    inorder(root->right);
}

void
preorder(Node* root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->value);
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
    printf("%d\n", root->value);
}

void
testtree()
{
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
}
