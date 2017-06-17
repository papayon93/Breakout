CC=gcc

CFLAGS=-g -Wall -D_GNU_SOURCE=1 -D_REENTRANT -std=c90 -pedantic
#CFLAGS=-g -Wall -D_REENTRANT
IMAGE_FLAGS=-lSDL2_image -lSDL2_mixer
SFLAGS=-lSDL2
SOURCES=c/Breakout.c
BINARIES=Juego

#all: ex0 ex1 ex2 ex3 ex4 ex5 ex6 ex7 grafico texto
all: $(BINARIES)

Juego: c/Breakout.c
	$(CC) -o Juego c/Breakout.c $(CFLAGS) $(SFLAGS) $(IMAGE_FLAGS) 

clean:
	rm -rf *.o *.exe *.bak *.c~ $(BINARIES) core a.out
