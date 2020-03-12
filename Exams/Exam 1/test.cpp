#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int a[5];
    long b[2];
    char  s[81] = {"Oh, woe!"} ;
    int* ip[2];

    printf("sizeof(a) = %i\n", sizeof(a));
    printf("sizeof(b) = %i\n", sizeof(b));
    printf("sizeof(s) = %i\n", sizeof(s));
    printf("sizeof(ip) = %i\n", sizeof(ip));

    return 0;
}