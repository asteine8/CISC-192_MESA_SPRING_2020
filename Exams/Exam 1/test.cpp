#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int i=4, *ip, **ip2, ***ip3;
    ip = &i;
    ip2 = &ip;
    ip3 = &ip2;

    printf("i = %i, &i = %x\n", i, &i);
    printf("*ip = %i, ip = %x, &ip = %x\n", *ip, ip, &ip);
    printf("**ip2 = %i, ip2 = %x, &ip2 = %x\n", **ip2, ip2, &ip2);
    printf("***ip3 = %i, ip3 = %x, &ip3 = %x\n", ***ip3, ip3, &ip3);

    return 0;
}