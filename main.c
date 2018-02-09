#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "treehelper.h"
#include "metafile.h"
#include "writetree.h"

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