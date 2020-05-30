#ifndef FLIP_H
#define FLIP_H

#include <stdlib.h> // Added to include the 'rand' function


bool flip (int x)
{

    // int x; <-- Was overriding your parameter variable due to scope

    int weight = rand(); // <-- Was throwing error "Not defined in scope"
    // Needs stdlib.h to work (http://www.cplusplus.com/reference/cstdlib/rand/)


    if (x < weight) return true;
    else return false;
}


#endif