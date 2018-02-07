#ifndef TREEHELPER_H_
#define TREEHELPER_H_
#include "binarytree.h"

Node* initializenode(Node* root, int len);
void addwordtonode(Node* root, char* word);
int isinnode(Node* node, char* word);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
void printnode(Node* node);

#endif