#ifndef TREESTRING_H_
#define TREESTRING_H_

typedef struct treestring TreeString;

struct treestring {
    char word[64];
    int len;
};

#endif