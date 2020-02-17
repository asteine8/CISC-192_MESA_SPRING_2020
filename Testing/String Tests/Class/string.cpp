
#include <iostream>

#define BUFFER_SIZE 256

using namespace std;

void printStr(char* str);
char* trimStr(char* str);
void reverseString(char* str);
char* copyString(char* str);
int arraySize(char* str);
char* concatStrings(char* str1, char* str2);
int searchString(char* str, char* searchTerm);
bool compareStrings(char* str1, char* str2);
void toLower(char* str);
void toUpper(char* str);

int main() {
    char inputString1[BUFFER_SIZE];
    char inputString2[BUFFER_SIZE];
    
    // Get strings from input
    cout << "Enter String 1: ";
    cin.getline(inputString1, BUFFER_SIZE);
    cout << "Enter String 2: ";
    cin.getline(inputString2, BUFFER_SIZE);

    cout << "String 1 Size: " << arraySize(inputString1) << endl;

    cout << "Your String 1: ";
    printStr(inputString1);
    cout << endl;
    cout << "Your String 2: ";
    printStr(inputString2);
    cout << endl;

    char* trimmedStr = trimStr(inputString1);
    cout << "Trimmed String: ";
    printStr(trimmedStr);
    cout << endl;

    char* copiedTrimmedStr = copyString(trimmedStr);
    cout << "Copied Trimmed String: ";
    printStr(copiedTrimmedStr);
    cout << endl;

    cout << "Reversed String: ";
    reverseString(trimmedStr);
    printStr(trimmedStr);
    cout << endl;

    cout << "Concat reversed and trimmed strings: ";
    char* concatedString = concatStrings(trimmedStr, copiedTrimmedStr);
    printStr(concatedString);
    cout << endl;

    cout << "Search string 1 for string 2 (index): ";
    cout << searchString(inputString1, inputString2) << endl;

    cout << "Compare string 1 to string 2: ";
    cout << compareStrings(inputString1, inputString2) << endl;

    cout << "Convert string 1 to uppercase: ";
    toUpper(inputString1);
    printStr(inputString1);
    cout << endl;

    cout << "Convert string 1 to lowercase: ";
    toLower(inputString1);
    printStr(inputString1);
    cout << endl;

    return 0;
}

void printStr(char* str) {
    int i = 0;
    cout << "'";
    while (*str != '\0') {
        cout << (*str);
        str++;
    }
    cout << "'";
}

char* copyString(char* str) {
    int size = arraySize(str);

    char* newString = new char[size];

    while (*str != '\0') {
        *newString = *str;
        newString++;
        str++;
    }

    *newString = '\0';

    newString -= size-1;
    return newString;
}

void reverseString(char* str) {
    int numel = arraySize(str)-1;

    char tempLower, tempUpper;
    for (int i = 0; i < numel/2; i++) {
        tempLower = *str;
        str += numel-(2*i)-1;
        tempUpper = *str;
        *str = tempLower;
        str -= numel-(2*i)-1;
        *str = tempUpper;
        str++;
    }
}

// Trims whitespace characters from end of char array
char* trimStr(char* str) {
    int newStringSize;
    int strSize = 1; // Start at one to account for '\0' char at end

    // Find the end of string
    while (*str != '\0') {
        str++;
        strSize++;
    }

    newStringSize = strSize;

    // Subtract the size of the trimmed array
    while (*str <= 32) {
        str--;
        newStringSize--;
    }

    // cout << "New String Size: " << newStringSize << " | String Size: " << strSize << endl;

    // Generate new string from the heap with 1 additional char for the '\0' character
    char* trimmedStr = new char[newStringSize+1];

    if (trimmedStr == nullptr) {
        cout << "Error: memory could not be allocated" << endl;
    }

    // Set trimmedStr pointer to end of new string
    trimmedStr += newStringSize;

    // Set '\0' character at end
    *trimmedStr = '\0';
    trimmedStr--;

    // Fill new string
    for (int i = 0; i < newStringSize; i++) {
        *trimmedStr = *str;
        str--;
        trimmedStr--;
    }

    // Go back up one memory location to initial location
    trimmedStr++;

    return trimmedStr;
}

// Returns the number of elements plus the '\0' character
int arraySize(char* str) {
    int numel = 1;
    while (*str != '\0') {
        numel++;
        str++;
    }

    return numel;
}

char* concatStrings(char* str1, char* str2) {
    int newArraySize = arraySize(str1) + arraySize(str2) - 1; // Get rid of extra '\0'

    char* newString = new char[newArraySize];

    while (*str1 != '\0') {
        *newString = *str1;
        newString++;
        str1++;
    }
    while (*str2 != '\0') {
        *newString = *str2;
        newString++;
        str2++;
    }

    // Add terminator
    *newString = '\0';

    newString -= newArraySize-1;

    return newString;
}

int searchString(char* str, char* searchTerm) {
    int index = 0;
    int numChecks = 0;

    // Iterate through all characters in the string
    while (*str != '\0') {

        // Iterate while we have a match
        while (*searchTerm == *str) {
            searchTerm++;
            str++;
            numChecks++;

            // If we have reached the end of the search term, return the index
            if (*searchTerm == '\0') return index;
            if (*str == '\0' || *searchTerm != *str) { // get back to the search
                str -= numChecks;
                searchTerm -= numChecks;
                numChecks = 0;
                break;
            }
        }

        str++;
        index++;
    }

    return -1; // Return -1 if no terms found
}

bool compareStrings(char* str1, char* str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') return true;
        str1++;
        str2++;
    }
    return false;
}

void toUpper(char* str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str -= 0x20;
        }
        str++;
    }
}

void toLower(char* str) {
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 0x20;
        }
        str++;
    }
}