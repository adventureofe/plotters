/* By theadventureofe(John Gormley)
   
   main file

   the_adventure_of_e λ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "../headers/tri.h"
#include "../headers/window.h"

Tri* tri_create(int x, int y, int pivot, int length)
{
    Tri* t = (Tri*) malloc(sizeof(Tri));
    t->x = x;
    t->y = y;
    t->pivot = pivot;
    t->length = length;
    return t;
}

void tri_draw(Window* win, Tri* t, char character, int colour)
{
    wattron(win->win, COLOR_PAIR(colour));

    switch(t->pivot)
    {
        case 0:
          for(int i = 0; i < t->length; i++)
          {
              for(int j = 0; j < t->length*2; j+= 2)
              {
                  mvwprintw(win->win,
                            win->height/2 - t->y - i,
                            win->width + 3  + t->x * i,
                            "%c ", character);
                  
              }
          } 
          break;

        case 1:
            break;
            
        case 2:
            break;

        case 3:
            break;
    }
    wattroff(win->win, COLOR_PAIR(colour));
}
