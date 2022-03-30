#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>
#include "lib/print_cells.h"
#include "lib/cell_alive.h"

// Game of life itself

//coder 1 and coder 3
int gol(bool **game_board)
{
	int ch;
	int gen=0;
	int deadgame = 0;
	bool *prev_game_board[LINES];
	for (int i = 0; i < LINES; ++i)
		prev_game_board[i] = calloc(COLS, sizeof(bool));

	// check if user is not quitting the game
	while (true) {
		if ((ch = getch()) != ERR) {
            if(ch == 'q'){
                break;
            }
		}

        // copy previous state of game, since we need to check alive/not alive condition while
        // changing the next generation. also crucial for continuous memory freeing
		for (int i = 0; i < LINES; ++i)
			for (int j = 0; j < COLS; ++j)
				prev_game_board[i][j] = game_board[i][j];
		
		// filling the new state of game of life
		for (int i = 0; i < LINES; ++i) {
			for (int j = 0; j < COLS; ++j) {
				if (cell_alive(i, j, prev_game_board))
					game_board[i][j] = true;
				else
					game_board[i][j] = false;
			}
		}

		// checking whether changes in the game board happened to know if the game should be ended automatically
		deadgame=0;
		for (int i = 0; i < LINES; ++i){
			for (int j = 0; j < COLS; ++j){
				if (prev_game_board[i][j] != game_board[i][j]){
					deadgame++;}}}
				
		if(deadgame==0){
			break;
		}
			
		
		gen++;
		print_cells(game_board);
		refresh();
		mvprintw(0,0,"gen: %d",gen);
		refresh();
        sleep(1);
	}

    // prev_game_board created in this function, must be freed here to avoid memory leakage
	for (int i = 0; i < LINES; ++i)
		free(prev_game_board[i]);
    return 0;
}

