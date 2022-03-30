#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>

// prints current state of game board

//coder 1 
void print_cells(bool **game_board)
{
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < COLS; ++j) {
            // if coordinate is true = cell is alive
			if (game_board[i][j])
				mvaddch(i, j, '*');
			else
				mvaddch(i, j, ' ');
		}
	}
}

