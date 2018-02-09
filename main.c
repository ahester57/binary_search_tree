#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "treehelper.h"
#include "readfile.h"
#include "writefile.h"

char* getbasefilename(const char* arg);

int
main (int argc, char* argv[])
{
    int keyboardin = 1;
    char* fname = "out";
    FILE* fp = stdin;
    // Parse arguments
    if (argc > 1) {
        keyboardin = 0;
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

    // Build the tree 
    // buildtree takes one argument:
    // a file containing text
    node_t* root = NULL;
    root = buildtree(fp);

    // write*order takes two arguments:
    // the root of the tree, and the base filename
    // 
    // out-file
    writeinorder (root, fname);
    writepreorder (root, fname);
    writepostorder (root, fname);

    // free fname if it was generated.
    if (!keyboardin) {
        free(fname);
    }
    fclose(fp);
    free(root);
    return 0;
}

char*
getbasefilename (const char* arg)
{
    int len = strlen(arg);
    char* fname = (char*) malloc((len+1)*sizeof(char));

    if (fname == NULL)
        return (char*) NULL;
    
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