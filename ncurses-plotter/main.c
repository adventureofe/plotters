/* By theadventureofe(John Gormley)
   main file
   the_adventure_of_e λ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include "headers/window.h"
#include "headers/rect.h"
#include "headers/tri.h"

// print all included cmd args (removes warning)
void arg_print(int argc, char** argv)
{
    for(int i = 1; i < argc; i++)
    {
        printf("arg[%d]: %s", i, argv[i]);
    }

    if(argc > 1)
    {
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    arg_print(argc, argv);

    /* initialise random seed */
    srand(time(NULL));
    time_t my_time;
    srand((unsigned) time(&my_time));

    initscr();
    start_color();

    #define SCR_WIDTH 51
    #define SCR_HEIGHT 51
    #define SCR_X 0
    #define SCR_Y 0
    Window* win = window_create(SCR_X, SCR_Y, SCR_WIDTH, SCR_HEIGHT);

    refresh();
    init_pair(1, 2, 16);
    init_pair(2, 0, 10);
    init_pair(3, 0, 15);
    init_pair(4, 0, 3);
    init_pair(5, 0, 4);

    window_fill(win, '.', 1);
    window_cross(win, 2, 3);

    Rect* r = rect_create(-13, 4, 2, 7);
    rect_draw(win, r, '1' , 4);

    rect_rotate(r, TOP_RIGHT);
    rect_draw(win, r, '2', 5);

    rect_rotate(r, TOP_RIGHT);
    rect_draw(win, r, '3', 4);

    wrefresh(win->win);

    getch();
    endwin();

    return EXIT_SUCCESS;
}
