
#include <iostream>
#include <cstring>

void printCharArray(char str[]);

int main() {

    char testString1[] = {'h','e','l','l','o','\0'};
    char testString2[] = {' ','w','o','r','l','d','\0'};

    std::cout << "test string 1: '";
    printCharArray(testString1);
    std::cout << "'\n";

    std:: cout << "test string 2: '";
    printCharArray(testString2);
    std::cout << "'\n";

    char concatTestString[];

    return 0;
}

void printCharArray(char str[]) {
    for (uint8_t i = 0; str[i] != '\0'; i++) {
        std::cout << str[i];
    }
}