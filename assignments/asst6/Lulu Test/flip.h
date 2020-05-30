#ifndef FLIP_H
#define FLIP_H

#include <stdlib.h>
#include <time.h>

bool flip (int x)
{
    srand(time(NULL));
    
    int weight = rand() % 100;

    if (x < weight) return true;
    else return false;
}

#endif