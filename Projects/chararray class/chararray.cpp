#include "chararray.h"

CharArray::CharArray() {
    array = new char[0];
}

CharArray::CharArray(char* str) {
    array = new char[numCharacters(str)];
    char* tempPtr = array;

    while (*str != '\0') {
        *tempPtr = *str;
        tempPtr++;
        str++;
    }

    *tempPtr = '\0'; // Add a terminator to the end...
}

CharArray::~CharArray() {
    delete CharArray::array;
}

void CharArray::reverse() {
    int numel = numCharacters()-1;
    char* tempPtr = array;

    char tempLower, tempUpper;
    for (int i = 0; i < numel/2; i++) {
        tempLower = *tempPtr;
        tempPtr += numel-(2*i)-1;
        tempUpper = *tempPtr;
        *tempPtr = tempLower;
        tempPtr -= numel-(2*i)-1;
        *tempPtr = tempUpper;
        tempPtr++;
    }
}

void CharArray::toUppercase() {
    char* tempPtr = array;

    while (*tempPtr != '\0') {
        if (*tempPtr >= 'a' && *tempPtr <= 'z') {
            *tempPtr -= 0x20;
        }
        tempPtr++;
    }
}

void CharArray::toLowercase() {
    char* tempPtr = array;

    while (*tempPtr != '\0') {
        if (*tempPtr >= 'A' && *tempPtr <= 'Z') {
            *tempPtr += 0x20;
        }
        tempPtr++;
    }
}

int CharArray::findTerm(char* searchTerm) {

}

int CharArray::findTerm(CharArray searchTerm) {

}

void CharArray::append(char* str) {

}

void CharArray::append(CharArray str) {

}

// Includes the '\0' char
int CharArray::numCharacters() {
    char* tempPtr = array;

    int numchars = 0;
    while (*tempPtr != '\0') {
        numchars++;
        tempPtr++;
    }

    numchars++; // Add one for the '\0' char
    return numchars;
}

// Includes the '\0' char
int CharArray::numCharacters(char* str) {
    int numchars = 0;
    while (*str != '\0') {
        numchars++;
        str++;
    }

    numchars++; // Add one for the '\0' char
    return numchars;
}