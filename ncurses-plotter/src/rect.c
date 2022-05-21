/* By theadventureofe(John Gormley)  
   main file

   the_adventure_of_e λ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#include "../headers/rect.h"
#include "../headers/window.h"

Rect* rect_create(int x, int y, int width, int height)
{
    Rect* r = (Rect*) malloc(sizeof(Rect));
    r->x = x;
    r->y = y;
    r->width = width;
    r->height = height;
  
    return r;
}

int rect_area(Rect *r)
{
    return r->width * r->height;
}

int rect_perimeter(Rect *r)
{
    return (r->width * 2) + (r->height * 2);
}

double rect_pythagoras(Rect *r)
{
    return sqrt(pow(r->width, 2.0) + pow(r->height, 2.0));
}

void rect_swap_axis(Rect *r)
{
    int temp = r->width;
    r->width = r->height;
    r->height = temp;
}

void rect_rotate(Rect* r, int pivot)
{
    switch(pivot)
    {
        case BOTTOM_LEFT:
            if(r->width >= r->height)
            {
                r->y -= r->width;
            }
            break;

        case BOTTOM_RIGHT:
            r->x += r->width;
            break;

        case TOP_LEFT:
            r->x -= r->height;
            r->y += r->height - r->width;
            break;

        case TOP_RIGHT:
            r->y += r->height;
            r->x -= r->height - r->width;
            break;

        default:
            break;
    }
    rect_swap_axis(r);
}

void rect_describe(Rect *r)
{
    printf("x:(%d) y:(%d) w:(%d) h:(%d)\n", r->x, r->y, r->width, r->height);
    printf("area:(%d) perimeter(%d)\n", rect_area(r), rect_perimeter(r));
    printf("%d \n", );int("middle coord:(%.3f, %.3f) \n", r->x + (r->width / 2.0), r->y + (r->height/ 2.0));
    printf("top right coord:(%d, %d) \n", r->x + r->width, r->y + r->height);
    printf("\n");
}

void rect_draw(Window* win, Rect *r,char character, int colour)
{
    wattron(win->win, COLOR_PAIR(colour));

    for(int i = 0; i < r->height; i++)
    {
        for(int j = 0; j < r->width*2; j+=2)
        {
            mvwprintw(win->win,
                      win->height/2 - i - r->y,
                      win->width+j-1 + r->x*2,
                      "%c ", character);
        }
    }    
    wattroff(win->win, COLOR_PAIR(colour));
}
