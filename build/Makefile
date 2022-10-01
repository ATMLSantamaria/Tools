IDIR =../include
CC=g++
CFLAGS=-std=c++11 -ggdb -pthread -I$(IDIR)

ODIR=../src
LDIR =../lib

LIBS=-lm

_OBJ = *.cpp 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

build: $(OBJ)
	$(CC) -o ejecutable $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f ejecutable