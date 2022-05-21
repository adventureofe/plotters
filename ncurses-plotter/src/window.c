/* By theadventureofe(John Gormley)
   the_adventure_of_e λ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>

#include "../headers/window.h"

//width is roughly half the size of height so I will double the width
//this also ensures the width is an even number
Window* window_create(int x, int y, int width, int height)
{
    Window* w = (Window*) malloc(sizeof(Window));
    w->x = x;
    w->y = y; 
    w->width = width;
    w->height = height;
    w->win = newwin(w->height, w->width*2, w->x, w->y);
    return w;
}


void window_fill(Window* win, char character, int colour)
{
    wattron(win->win, COLOR_PAIR(colour));
    for(int i = 0; i < win->height; i++)
    {
        for(int j = 0; j < win->width * 2; j+= 2)
        {
            mvwprintw(win->win, i, j, "%c ", character);
        }
    }
    wattroff(win->win, COLOR_PAIR(colour));
}

void window_random(Window* win, char character, int colour, int chance)
{
    wattron(win->win, COLOR_PAIR(colour));

    for(int i = 0; i < win->height; i++)
    {
        for(int j = 0; j < win->width*2; j+=2)
        {
            if(rand() % chance == 0)
            {
                mvwprintw(win->win, i, j, "%c", character);
            }
        }
    }
    wattroff(win->win, COLOR_PAIR(colour));
}


void window_cross(Window* win, int col_1, int col_2)
{

    for(int i = 0; i < win->height; i++)
    {
        if(i % 2 == 0)
        {
            wattron(win->win, COLOR_PAIR(col_1));
            wattroff(win->win, COLOR_PAIR(col_2));
        }
        else
        {
            wattron(win->win, COLOR_PAIR(col_2));
        }

        //fix formatting if number is 1 character long
        if(abs(win->height/2 - i) < 10)
        { 
            mvwprintw(win->win, i, win->width-1, "%d ", abs(win->height/2 -i));
        }
        
        else
        {
          mvwprintw(win->win, i, win->width-1, "%d", abs(win->height/2 -i));
        }
    }
    
    wattroff(win->win, COLOR_PAIR(col_1));
    wattroff(win->win, COLOR_PAIR(col_2));
    
    
    for(int j = 0; j < win->width*2; j+=2)
    {
        if(j % 4 == 0)
        {
            wattron(win->win, COLOR_PAIR(col_1));
            wattroff(win->win, COLOR_PAIR(col_2));
        }
        else
        {
            wattron(win->win, COLOR_PAIR(col_2));
        }
        
        
        if(abs(win->width/2 -j/2) < 10)
        {
            mvwprintw(win->win, win->height/2, j, "%d ", abs(win->width/2 - j/2));
        }
        else
        {
            mvwprintw(win->win, win->height/2, j, "%d", abs(win->width/2 - j/2));
        }
    }
    
    wattroff(win->win, COLOR_PAIR(col_1));
    wattroff(win->win, COLOR_PAIR(col_2));
}
