CC = gcc
CFLAGS=-c -Wall -Werror
LDFLAGS = -lncurses

all: project

project: main.o print_cells.o cell_alive.o gol.o init_pattern.o selectPattern.o resize.o
	$(CC) main.o gol.o print_cells.o cell_alive.o init_pattern.o selectPattern.o resize.o -o project $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c

print_cells.o: print_cells.c
	$(CC) -c print_cells.c

cell_alive.o: cell_alive.c
	$(CC) -c cell_alive.c

gol.o: gol.c
	$(CC) -c gol.c

init_pattern.o: init_pattern.c
	$(CC) -c init_pattern.c

selectPattern.o: selectPattern.c
	$(CC) -c selectPattern.c

resize.o: resize.c
	$(CC) -c resize.c

clean:
	rm -rf *o project
