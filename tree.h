#ifndef TREE_H_
#define TREE_H_
#include "node.h"

node_t* buildtree(FILE* fp);
node_t* insert(node_t* root, char* word, int level);
node_t* search(node_t* root, char* word);
node_t* deletenode(node_t* root, int len);

#endif