#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>

// function containing starting patterns/configurations game of life will start with

// coder 2
int init_pattern(int y, int x,char structure, bool **game_board){
    // setting true = cell is alive

	// leaning the game board to start
	for (int i = 0; i < LINES; ++i) {
		for (int j = 0; j < COLS; ++j) {
			game_board[i][j] = false;}}

	// The R-pentomino
	if (structure =='1'){
		
		game_board[y][x] = true;
		mvaddch(y, x, '*');
		game_board[y-1][x] = true;
		mvaddch(y-1, x, '*');
		game_board[y-2][x] = true;
		mvaddch(y-2, x, '*');
		game_board[y-1][x-1] = true;
		mvaddch(y-1, x-1, '*');
		game_board[y-2][x+1] = true;
		mvaddch(y-2, x+1, '*');

	}

	// The Diehard
	if (structure =='2'){
		game_board[y][x-2] = true;
		mvaddch(y, x-2, '*');
		game_board[y-1][x-2] = true;
		mvaddch(y-1, x-2, '*');
		game_board[y-1][x-3] = true;
		mvaddch(y-1, x-3, '*');		
		game_board[y][x+2] = true;
		mvaddch(y, x+2, '*');
		game_board[y][x+3] = true;
		mvaddch(y, x+3, '*');
		game_board[y][x+4] = true;
		mvaddch(y, x+4, '*');
		game_board[y-2][x+3] = true;
		mvaddch(y-2, x+3, '*');

	}

	// The Acorn
	if (structure =='3'){
		game_board[y][x-3] = true;
		mvaddch(y, x-3, '*');
		game_board[y][x-2] = true;
		mvaddch(y, x-2, '*');		
		game_board[y][x+1] = true;
		mvaddch(y, x+1, '*');				
		game_board[y][x+2] = true;
		mvaddch(y, x+2, '*');
		game_board[y][x+3] = true;
		mvaddch(y, x+3, '*');
		game_board[y-1][x] = true;
		mvaddch(y-1, x, '*');
		game_board[y-2][x-2] = true;
		mvaddch(y-2, x-2, '*');

	}
return 1;
}

