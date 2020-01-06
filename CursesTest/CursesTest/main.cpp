/*
 * File:   main.c
 * Author: Harijs
 *
 * Created on December 27, 2019, 4:13 AM
 */

 //#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>    //  for sleep()
//

int main() 
{
    printf("this works fine\n");

	sleep(2);

	WINDOW* mainwin;

	if ((mainwin = initscr()) == 0) {
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}

	int maxX, maxY;
	getmaxyx(mainwin, maxY, maxX);
	// ^- these variables are filled with right values, you can see it with setting brakepoint in next line

	char printString[128];
	int size = sprintf(printString, "Console size: %d x %d;", maxX, maxY);
	// ^- Yet this does not show in VS Linux Console Window, but works when running from putty
	mvaddstr(1, 1, printString);

	refresh();

	sleep(2);

	   	  
	delwin(mainwin);
	endwin();
	refresh();

	sleep(2);

	printf("And this works again\n");

	sleep(2);

    return 0;
}