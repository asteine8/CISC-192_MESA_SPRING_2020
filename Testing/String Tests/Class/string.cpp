
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

    char* trimmedStr = trimStr(inputString1);
    cout << "New String: ";
    printStr(trimmedStr);
    cout << endl;

    return 0;
}

void printStr(char* str) {
    int i = 0;
    while (*str != '\0') {
        cout << *str;
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

    cout << "New String Size: " << newStringSize << " | String Size: " << strSize << endl;

    // Generate new string from the heap with 1 additional char for the '\0' character
    char* trimmedStr = new char[newStringSize+1];

    if (trimmedStr == nullptr) {
        cout << "Error: memory could not be allocated" << endl;
    }

    cout << "Initial Position: " << trimmedStr << endl;
    // Set trimmedStr pointer to end of new string
    trimmedStr += newStringSize;

    cout << "New Position: " << trimmedStr << endl;

    // Set '\0' character at end
    *trimmedStr = '\0';
    trimmedStr--;

    // Fill new string
    for (int i = 0; i < newStringSize; i++) {
        *trimmedStr = *str;
        str--;
        trimmedStr--;
    }

    char* ptr = trimmedStr;
    while (*ptr != '\0') {
        cout << *ptr;
        ptr++;
    }
    cout << endl;

    cout << "End Position: " << trimmedStr << endl;

    return trimmedStr;
}


