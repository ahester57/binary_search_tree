#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binarytree.h"
#include "treehelper.h"

Node*
insert(Node* root, char* word)
{
    int len = strlen(word);
    if (root == NULL) {
        // initialize a new node
        root = initializenode(root, len);
        addwordtonode(root, word);
    } else if (len == root->length) {
        // add this word to this node
        if (!isinnode(root, word)) {
            addwordtonode(root, word);
        }
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
deletenode(Node* root, int len)
{
    // @TODO
    return root;
}