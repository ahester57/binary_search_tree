
CC=gcc
CFLAGS=-Wall -g
#LDLIBS= -pthread
# or perhaps SOURCES= $(wildcard *.c)
DEPS = tree.h treehelper.h readfile.h writefile.h
OBJECTS = main.o tree.o treehelper.o readfile.o writefile.o

.PHONY: all clean

default: all

all: p0 

%.o: %.c $(DEPS)

p0: $(OBJECTS)
	gcc -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(OBJECTS)

destroy:
	$(RM) $(OBJECTS) p0
