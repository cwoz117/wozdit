#include <stdio.h>
#include <stdlib.h>
#include <ncursus.h>
#include <panels.h>
#include "window.h"

void init_ncursus(){
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
}

void destroy_ncursus(){
	endwin();
}

void destroy_window(WINDOW * view){
	
}
