#ifndef BINARYTREE_H_
#define BINARYTREE_H_

typedef struct node Node;

struct node {
    char** words;
    int length;
    int count;
    Node* left;
    Node* right;
};

Node* insert(Node* root, char* word);
Node* search(Node* root, char* word);
Node* deletenode(Node* root, int len);

#endif