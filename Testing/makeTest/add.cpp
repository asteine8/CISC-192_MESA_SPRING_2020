#include "add.h"

int add(int x, int y) {
    return x + y;
}

void add(int* x, int* y) {
    *x += *y;
}