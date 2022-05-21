/* By theadventureofe(John Gormley)
   
   main file

   the_adventure_of_e λ */

#ifndef TRI_H
#define TRI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "window.h"

/* struct definition */
typedef struct Tri
{
    int x;
    int y;
    int pivot;
    int length;
} Tri;

Tri* tri_create(int x, int y, int pivot, int length);
void tri_draw(Window* win, Tri* t, char character, int colour);

#endif
