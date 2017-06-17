CC=gcc

CFLAGS=-g -Wall -D_GNU_SOURCE=1 -D_REENTRANT -pedantic
#CFLAGS=-g -Wall -D_REENTRANT
IMAGE_FLAGS=-lSDL2_image
MIXER_FLAGS=-lSDL2_mixer
SFLAGS=-lSDL2
SOURCES=main.c functions.c global.c
#SOURCES=c/Breakout.c
OBJECTS=main.o functions.o global.o
BINARIES=main

#all: ex0 ex1 ex2 ex3 ex4 ex5 ex6 ex7 grafico texto
all: $(BINARIES)

main: main.o functions.o global.o 
	$(CC) -o main main.o functions.o global.o $(SFLAGS) $(MIXER_FLAGS) $(IMAGE_FLAGS) 

Juego: c/Breakout.c
	$(CC) -o Juego c/Breakout.c $(CFLAGS) $(SFLAGS) $(IMAGE_FLAGS) 

main.o: main.c
	$(CC) -c main.c

functions.o: c/functions.c
	$(CC) -c c/functions.c $(SFLAGS) $(MIXER_FLAGS) $(IMAGE_FLAGS) 
	
global.o: c/global.c
	$(CC) -c c/global.c

limpa:
	del *.o *.exe *.bak *.c~ $(BINARIES) core

clean:
	rm -rf *.o *.exe *.bak *.c~ $(BINARIES) core a.out