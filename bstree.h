#ifndef BSTREE_H_
#define BSTREE_H_
#include "treestring.h"

typedef struct node Node;

struct node {
    TreeString value[64];
    Node* left;
    Node* right;
};

Node* insert(Node* root, int val);
Node* search(Node* root, int val);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
void testtree();

#endif