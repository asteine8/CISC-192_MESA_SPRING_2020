#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        printf("rand() % 100 = %i\n", rand() % 100);
    }

    return 0;
}
