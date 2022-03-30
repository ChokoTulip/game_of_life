#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <signal.h>

// function for resizing the terminal window once user chooses so

//coder 3
void resize(int sig){
int nh,nw;
getmaxyx(stdscr,nh,nw); //get new window size
}

