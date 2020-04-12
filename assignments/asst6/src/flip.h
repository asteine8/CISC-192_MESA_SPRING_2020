#ifndef FLIP_H
#define FLIP_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * bool flip (int weight)
 *      weight: determines how many times in 100 
 *	    invocations flip() will return true. Weight 
 *      cannot exceed 100 and must be non-negative
 */
bool flip(int weight);

#endif