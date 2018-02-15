
CC=gcc
CFLAGS=-Wall -g
#LDLIBS= -pthread
# or perhaps SOURCES= $(wildcard *.c)
DEPS = tree.h treehelper.h metafile.h readfile.h writetree.h
# change to patsubt
OBJECTS = main.o tree.o treehelper.o metafile.o readfile.o writetree.o

.PHONY: all clean

default: all

all: P0 

%.o: %.c $(DEPS)

P0: $(OBJECTS)
	gcc -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

destroy:
	$(RM) $(OBJECTS) p0 *.inorder *.preorder *.postorder
