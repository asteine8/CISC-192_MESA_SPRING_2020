#include <iostream>
#include "chararray.h"

using namespace std;

int main() {
    char newArray[] = {'h','e','l','l','o','\0'};

    CharArray cArr(newArray);

    cArr.reverse();

    cout << "Your string: " << cArr.array << endl;

    return 0;
}