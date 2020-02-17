
#include <iostream>

using namespace std;

char* allocateArray(int size, char c) {
    char* newArray = new char[size+1];
    for (unsigned int i = 0; i < size; i++) {
        *newArray = c;
        newArray++;
    }

    *newArray = '\0';
    newArray -= size;

    return newArray;
}

int main() {
    cout << "Enter a number: ";
    int numel;
    cin >> numel;
    char c = '*';

    char* myArray = allocateArray(numel, c);
    cout << "Generated string: ";
    while (*myArray != '\0') {
        cout << *myArray;
        myArray++;
    }

    cout << endl;

    return 0;
}