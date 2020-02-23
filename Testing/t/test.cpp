#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    char myString[6] = {'h','e','l','l','o','\0'};
    char* strPtr = myString;

    printf("My string: %s , char* version: %s\n", myString, strPtr);

    const char* constString = "Hai there";
    printf("constString = %s\n\n", constString);

    return 0;
}