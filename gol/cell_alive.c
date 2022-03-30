#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>

// every generation we check every coordinate on the
// game board if cell is dead or alive by its surrounding
// (implemented rules of game of life for cell state)

//coder 1 
bool cell_alive(int y, int x, bool **game_board)
{
    // apart from game of life rules, also position must be checked
    // (if cell is on the edge of the game board)
	int adjascent_cells = 0;
	if (y != 0 && x != 0 && game_board[y-1][x-1])
		adjascent_cells += 1;
	if (y != 0 && game_board[y-1][x])
		adjascent_cells += 1;
	if (y != 0 && x < COLS - 1 && game_board[y-1][x+1])
		adjascent_cells += 1;
	if (x != 0 && game_board[y][x-1])
		adjascent_cells += 1;
	if (x < COLS - 1 && game_board[y][x+1])
		adjascent_cells += 1;
	if (y < LINES - 1 && x != 0 && game_board[y+1][x-1])
		adjascent_cells += 1;
	if (y < LINES - 1 && game_board[y+1][x])
		adjascent_cells += 1;
	if (y < LINES - 1 && x < COLS - 1 && game_board[y+1][x+1])
		adjascent_cells += 1;

	if (game_board[y][x]) {
		if (adjascent_cells < 2 || adjascent_cells > 3)
			return false;
	} else if (adjascent_cells == 3) {
		return true;
	} else {
		return false;
	}

	return true;
}

