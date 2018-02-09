#include <stdlib.h>
#include <stdio.h>
#include "writefile.h"
#include "tree.h"

int
writetofile (FILE* fp, node_t* root)
{
    return 0;
}

void
writenode (FILE* fp, node_t* node)
{
    if (node->depth > 0)
        fprintf(fp, "%*c", node->depth*2, ' ');
    fprintf(fp, "%d ", node->length);
    int i;
    for (i = node->count-1; i >= 0 ; i--) {
        fprintf(fp, "%s ", node->words[i]);
    }
    fprintf(fp, "\n");
}