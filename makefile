PHONY : clean
CC = gcc
CFLAGS = -Wall -W -std=c99 -g
LIBS =
LDFLAGS = `sdl2-config --cflags --libs`
EXEC = main
SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(EXEC)
	@./main
	clean

main: $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LDFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf *.o */*.o *~ $(EXEC)