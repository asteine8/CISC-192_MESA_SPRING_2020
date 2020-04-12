
#include "flip.h"

/**
 * bool flip (int weight)
 *      weight: determines how many times in 100 
 *	    invocations flip() will return true. Weight 
 *      cannot exceed 100 and must be non-negative
 */
bool flip(int weight) {
    srand(time(NULL));
    int randInt = rand() % 100;

    return (randInt < weight);
}