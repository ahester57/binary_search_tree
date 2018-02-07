#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binarytree.h"
#include "treehelper.h"
#include "readfile.h"
#include "writefile.h"

FILE* parse_arg(const char*);

int
main (int argc, char* argv[])
{
    FILE* fp = stdin;
    // Parse arguments
    if (argc > 1) {
        fp = parse_arg(argv[1]);
    }
    if (fp == NULL) {
        perror("Input error");
        return 1;
    }

    char** wordlist = getfilestring(fp);
    int n = getnumwords();

    Node* root = NULL;
    root = insert(root, wordlist[0]);
    int i;
    for (i = 1; i < n; i++)
        insert(root, wordlist[i]);
        //fprintf(stdout, "%s\n", wordlist[i]);


    inorder(root);

    // out-file

    fclose(fp);
    return 0;
}

FILE*
parse_arg (const char* arg)
{
    int len = strlen(arg);
    char* fname = (char*) malloc((len+1)*sizeof(char));

    if (fname == NULL)
        return (FILE*) -1;

    // Copy argument to fname
    strcpy(fname, arg);

    // Didn't wanna break TAB completion
    if (len > 4) {
        // Check if extension '.sp18' already provided
        const char* ext = &fname[len-5];
        if (!strcmp(ext, ".sp18")) {
            // If .sp18 appended, don't edit.
            return fopen(fname, "r");
        }
    }

    // add extension .sp18 if we are advocates against TAB completion 
    sprintf(fname, "%s%s", fname, ".sp18");
    //printf("%s\n", fname);
    return fopen(fname, "r");
}
