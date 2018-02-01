#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bstree.h"
#include "readfile.h"

FILE* parse_arg(const char*);

int
main (int argc, char* argv[])
{
    FILE* fp = stdin;
    if (argc > 1) {
        // Parse argument
        fp = parse_arg(argv[1]);
    }
    if (fp == NULL) {
        perror("Input error");
        return 1;
    }
    char** wordlist = getwordlist(fp);
    // Do some tests
    testtree();
    fclose(fp);
    return 0;
}

FILE*
parse_arg (const char* arg)
{
    int len = strlen(arg);
    char* fname = malloc((len+1)*sizeof(char));
    strcpy(fname, arg);
    if (len > 4) {
        // Check if extension '.sp18' already provided
        // I like to press `TAB` so I don't have to type as much
        const char* ext = &fname[len-5];
        if (!strcmp(ext, ".sp18")) {
            // If .sp18 missing, append
            return fopen(fname, "r");
        }
    }
    sprintf(fname, "%s%s", fname, ".sp18");
    //printf("%s\n", fname);
    return fopen(fname, "r");
}
