#include <stdlib.h>
#include <stdio.h>
#include "readfile.h"

char*
getfilestring (FILE* fp)
{
    char* text = NULL;
    size_t size = 0;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    text = (char*) malloc((size+1) * sizeof(*text));

    fread(text, size, 1, fp);

    //text[size] = '\0';
    return text;
}