#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

typedef struct
{
    int height;
    int width;
    int x;
    int y;
    WINDOW* win;
} Window;

//width is roughly half the size of height so I will double the width
//this also ensures the width is an even number
Window* window_create(int height, int width, int x, int y);

void window_fill(Window* win, char character, int colour);

void window_random(Window* win, char character, int colour, int chance);

void window_cross(Window* win, int col_1, int col_2);
#endif
