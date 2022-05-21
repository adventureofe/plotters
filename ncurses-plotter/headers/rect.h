/* By theadventureofe(John Gormley)
   
   main file

   the_adventure_of_e λ */

#ifndef RECT_H
#define RECT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <uchar.h>
#include <stdint.h>
#include "window.h"

/* enumerations for rotation */
enum enum_pivot
{
    BOTTOM_LEFT, BOTTOM_RIGHT, TOP_LEFT, TOP_RIGHT
};

/* struct definition */
typedef struct Rect
{
    int x;
    int y;
    int width;
    int height;
} Rect;

Rect* rect_create(int x, int y, int width, int height);
int rect_area(Rect* r);
int rect_perimeter(Rect* r);
double rect_pythagoras(Rect* r);
void rect_describe(Rect* r);
void rect_draw(Window* w, Rect* r, char character, int colour);
void rect_rotate(Rect* r, int pivot);

#endif
