#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readfile.h"

char**
getfilestring (FILE* fp)
{
    // words limited to 64 chars
    // char* word = (char*) malloc(64 * sizeof(char));
    char word[64];
    //char** list = (char**) malloc(256 * sizeof(char*));
    char* list[64];
    
    int c = 0;
    while (fscanf(fp, "%s", word) != EOF)
    {
        fprintf(stdout, "%s\n", word);
        strcpy(list[c], word);
        c++;
    }

    return list;
}

size_t
getfilesize (FILE* fp)
{
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);
    return size;
}