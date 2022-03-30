#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>

// function dedicated to user selection of initial pattern the game of life will start with

//coder 2 and coder 3
int selectPattern(int y, int x){
	// to avoid quitting the game by pressing 's'
	int ch;
	if ((ch = getch()) != ERR) {
            while (ch != '1'|ch != '2'|ch != '3'){
		if(ch == 's')
                	return 0;
	    	else
			return 1;}}

	mvprintw(y-(LINES/2)+1, x-16, "Please Select Structure 1, 2 or 3");
	mvprintw(y+2, x-(COLS/3)-8, "1-The R-pentomino");
	mvaddch(y, x-(COLS/3), '*');
    	mvaddch(y-1, x-(COLS/3), '*');
    	mvaddch(y-2, x-(COLS/3), '*');
    	mvaddch(y-1, x-(COLS/3)-1, '*');
	mvaddch(y-2, x-(COLS/3)+1, '*');

	mvprintw(y+2, x-6, "2-The Diehard");
   	mvaddch(y, x-2, '*');
       	mvaddch(y-1, x-2, '*');
        mvaddch(y-1, x-3, '*');
	mvaddch(y, x+2, '*');
	mvaddch(y, x+3, '*');
	mvaddch(y, x+4, '*');
	mvaddch(y-2, x+3, '*');

	
	mvprintw(y+2, x+(COLS/3)-5, "3-The Acorn");
   	mvaddch(y, x+(COLS/3)-3, '*');
	mvaddch(y, x+(COLS/3)-2, '*');
	mvaddch(y, x+(COLS/3)+1, '*');	
	mvaddch(y, x+(COLS/3)+2, '*');
	mvaddch(y, x+(COLS/3)+3, '*');
	mvaddch(y-1, x+(COLS/3), '*');
	mvaddch(y-2, x+(COLS/3)-2, '*');

}

