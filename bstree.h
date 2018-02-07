#ifndef BSTREE_H_
#define BSTREE_H_

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
Node* delete(Node* root, int len);
int isinwordlist(char** list, char* word);

#endif