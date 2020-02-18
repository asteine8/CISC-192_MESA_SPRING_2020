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
    int index = 0;
    char* tempPtr = array;
    
    int numChecks = 0;

    while (*tempPtr != '\0') {
        while (*searchTerm == *tempPtr) {
            tempPtr++;
            searchTerm++;
            numChecks++;

            if (*searchTerm == '\0') return index;
            if (*searchTerm != *tempPtr || *tempPtr == '\0') {
                searchTerm -= numChecks;
                tempPtr -= numChecks;
                numChecks = 0;
                break;
            }
        }
        
        index++;
        tempPtr++;
    }

    return -1;
}

int CharArray::findTerm(CharArray searchTerm) {
    int index = 0;
    char* tempPtr = array;
    char* searchPtr = searchTerm.array;
    
    int numChecks = 0;

    while (*tempPtr != '\0') {
        while (*searchPtr == *tempPtr) {
            tempPtr++;
            searchPtr++;
            numChecks++;

            if (*searchPtr == '\0') return index;
            if (*searchPtr != *tempPtr || *tempPtr == '\0') {
                searchPtr -= numChecks;
                tempPtr -= numChecks;
                numChecks = 0;
                break;
            }
        }
        
        index++;
        tempPtr++;
    }

    return -1;
}

void CharArray::append(char* str) {
    int numel = numCharacters(array)+numCharacters(str)-1;
    char* newArray = new char[numel];

    char* tempPtr = array;

    while (*tempPtr != '\0') {
        *newArray = *tempPtr;
        tempPtr++;
        newArray++;
    }
    while (*str != '\0') {
        *newArray = *str;
        str++;
        newArray++;
    }

    *newArray = '\0';
    newArray -= numel-1;

    array = newArray;
}

void CharArray::append(CharArray str) {
    int numel = numCharacters(array)+numCharacters(str.array)-1;
    char* newArray = new char[numel];

    char* tempPtr1 = array;
    char* tempPtr2 = str.array;

    while (*tempPtr1 != '\0') {
        *newArray = *tempPtr1;
        tempPtr1++;
        newArray++;
    }
    while (*tempPtr2 != '\0') {
        *newArray = *tempPtr2;
        tempPtr2++;
        newArray++;
    }

    *newArray = '\0';
    newArray -= numel-1;

    array = newArray;
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