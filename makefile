.PHONY: all compile clean
CC = gcc
CFLAGS = -Wall -W -std=c99 -g
LIBS =
LDFLAGS = `sdl2-config --cflags --libs`
EXEC = main
SRC = main.c joueur/Joueur.c graphismes/Graphismes.c monde/Monde.c systemes/EventHandler.c systemes/Math.c systemes/Fps.c sprite/Sprite.c
OBJ = $(SRC:.c=.o)

all: compile clean

compile: $(EXEC)
	@./main

main: $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf */*.o *.o $(EXEC)