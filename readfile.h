#ifndef READFILE_H_
#define READFILE_H_
#include <stdio.h>

FILE* openinputfile (const char* fname);
char** getfilestring (FILE* fp);
int getnumwords ();
size_t getfilesize (FILE* fp);

#endif