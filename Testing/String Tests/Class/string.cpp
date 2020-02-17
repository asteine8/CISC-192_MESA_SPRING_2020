
#include <iostream>

#define BUFFER_SIZE 256

using namespace std;

void printStr(char* str);
char* reverse(char* str);
char* trimStr(char* str);

int main() {
    char inputString1[BUFFER_SIZE];
    char inputString2[BUFFER_SIZE];
    
    // Get strings from input
    cout << "Enter a String: ";
    cin.getline(inputString1, BUFFER_SIZE);
    // cout << "Enter another String: ";
    // cin.getline(inputString2, BUFFER_SIZE);

    cout << "Your String: ";
    printStr(inputString1);
    cout << endl;

    char* trimmedStr = trimStr(inputString1);
    cout << "New String: ";
    printStr(trimmedStr);
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


