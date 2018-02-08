#ifndef TREEHELPER_H_
#define TREEHELPER_H_
#include "tree.h"

node_t* initializenode(node_t* root, int len, int level);
void addwordtonode(node_t* root, char* word);
int isinnode(node_t* node, char* word);
void inorder(node_t* root);
void preorder(node_t* root);
void postorder(node_t* root);
void printnode(node_t* node, int level);

#endif