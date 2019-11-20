#The $@ CONSTANT SUSTITUTE THE NAME OF ACTION

PROGRAM = ../bin/Gtkapp.out

SOURCE = ../src/main.c

LIB = gtk+-3.0

LIBS = $(shell pkg-config --libs $(LIB))

CFLAGS = $(shell pkg-config --cflags $(LIB))

CC = gcc

OPTION = -Wall 

#PERM =	$(shell chmod ugo+x $(PROGRAM))

Gtkapp:
	$(CC) $(OPTION) $(SOURCE) $(LIBS) $(CFLAGS) -o $(PROGRAM)

all:
	chmod ugo+x $(PROGRAM)

clean:
	rm $(PROGRAM)


