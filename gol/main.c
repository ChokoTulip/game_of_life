#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>
#include "lib/print_cells.h"
#include "lib/cell_alive.h"
#include "lib/gol.h"
#include "lib/init_pattern.h"
#include "lib/resize.h"

/*
Team-work strategy: coders 1 and 2 took care of the program main structure (selection of initial structure and the game itself) 
and presentation of the Game of Life with ncurses while coder 3 was solving bugs and added small features for the game to work better. 
Also, during the process, all 3 coders have been informing of things to improve in the code.
*/

/*
                  		* * * HOW TO CONTROL GoL * * *

1) once you run the program, select initial pattern by pressing *1*, *2* or *3*
2) for start press *s*, for additional pattern changing press *1*,*2* or *3* and press *s* for start
3) for stopping the game, press *q*
4) after stopping the game, press *q* one more time to quit the game, or press
   *1*, *2* or *3*, which returns you to the point 1)
*/

//coder 1 and coder 3
int main()
{
	int ch, y, x;
	bool **game_board;

	// set-up regarding ncurses
	initscr();
	cbreak();
	noecho();
	intrflush(stdscr, FALSE);
	nodelay(stdscr, TRUE);
	int nh,nw;
	signal(SIGWINCH, resize);

	game_board = malloc(LINES * sizeof(bool *));
	for (int i = 0; i < LINES; ++i)
		game_board[i] = calloc(COLS, sizeof(bool));

    // print out initial pattern in the middle of the game board grid
    y = LINES / 2;
    x = COLS / 2;

    // let user select initial pattern
    int selectdone;
    (selectdone)=selectPattern(y, x);

	refresh();

	while (true) {

        int stat;
	
		ch = getch();
		switch (ch) {
		
		case '1':
			erase();
			(selectdone)=init_pattern(y, x, '1', game_board);
			mvprintw(0,0,"To start the game, press 's'.");
			break;

		case '2':
			erase();
			(selectdone)=init_pattern(y, x, '2', game_board);
			mvprintw(0,0,"To start the game, press 's'.");
			break;

		case '3':
			erase();
			(selectdone)=init_pattern(y, x, '3', game_board);
			mvprintw(0,0,"To start the game, press 's'.");
			break;

		case 's':
			(stat) = gol(game_board);
			if (stat == 0 && selectdone==1)
				goto game_over;
			break;

		case 'q':
			goto end;
			break;
		
		game_over:
			mvprintw(1,0,"GAME OVER!");
			mvprintw(2,0,"Please, press 'q' again to quit the game or select a initial pattern with '1','2' or '3' to start over");
			
                	break;

		}

		refresh();
	}

// Clear allocated memory at the end of the program

end:
	for (int i = 0; i < LINES; ++i)
		free(game_board[i]);

	free(game_board);
	endwin();
	return 0;
}
