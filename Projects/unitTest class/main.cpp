#include <iostream>
#include "test.h"

int main() {
    Test T();

    int expected = 19;
    int actual = 109;

    T.assertEquals<int>("Testing some random numbers", expected, actual, "oh no!!!!");

    return 0;
}