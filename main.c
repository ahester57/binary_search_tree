#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "treehelper.h"
#include "writefile.h"

FILE* openinputfile(const char* fname);
char* getbasefilename(const char* arg);

int
main (int argc, char* argv[])
{
    char* fname;
    FILE* fp = stdin;
    // Parse arguments
    if (argc > 1) {
        fname = getbasefilename(argv[1]);
        if (fname == NULL) {
            perror("Input error");
            return 1;
        }
        fp = openinputfile(fname);
    }
    if (fp == NULL) {
        perror("Input error");
        return 1;
    }

    node_t* root = NULL;
    root = buildtree(fp);

    if (root != NULL && root->count > 0) {
        FILE* tmp;
        char temp[64];
        sprintf(temp, "%s.preorder", fname);
        tmp = fopen(temp, "w");
        traversepreorder(root, tmp);
    }

    // out-file
    free(fname);
    free(root);
    fclose(fp);
    return 0;
}

FILE*
openinputfile (const char* fname)
{
    char temp[64];
    

    // append .sp18 to base file name
    sprintf(temp, "%s%s", fname, ".sp18");
    if (temp == NULL)
        return (FILE*) -1;
    return fopen(temp, "r");
}

char*
getbasefilename (const char* arg)
{
    int len = strlen(arg);
    char* fname = (char*) malloc((len+1)*sizeof(char));

    if (fname == NULL)
        return (char*) -1;
    
    // Copy argument to fname
    strcpy(fname, arg);

    if (len > 4) {
        // Check if extension '.sp18' already provided
        // advocate for TAB completion 
        const char* ext = &fname[len-5];
        if (!strcmp(ext, ".sp18")) {
            // If .sp18 appended, take off.
            fname[len-5] = '\0';
        }
    }
    return fname;
}