#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

#define DEBUG 0
#define ARRAY_SIZE 100000
#define MAX_VAL 10

using namespace std;

void prtArray(int** array, int start, int end) {
    for (int i = start; i < end; i++) {
        std::cout << *array[i] << ',';
    }
    std::cout << std::endl;
}

void mergeSort(int** array, int start, int end) {

    // Calculate midpoint for sort and number of elements
    int numel = end - start;
    int middle = start + numel/2;

    if (numel > 2) {
        // Sort lower half
        mergeSort(array, start, middle);

        // Sort upper half
        mergeSort(array, middle, end);
    }
    
    #if DEBUG
    printf("start: %i, end:%i, numel:%i, middle:%i\n", start, end, numel, middle);
    prtArray(array, start, end);
    std::cout << std::endl;
    #endif
    
    // int* temparr1 = new int[numel];
    int temp[numel];
    int* temparr1 = temp;
    int* temparr2 = temparr1;
    int indexL = start;
    int indexU = middle;
    
    // Merge into temp array
    while (true) {
        if (indexL == middle && indexU == end) break;
        if (indexL == middle) {
            *temparr2 = *array[indexU];
            indexU++;
            temparr2++;
        }
        else if (indexU == end) {
            *temparr2 = *array[indexL];
            indexL++;
            temparr2++;
        }
        else if (*array[indexL] > *array[indexU]) {
            *temparr2 = *array[indexU];
            indexU++;
            temparr2++;
        }
        else {
            *temparr2 = *array[indexL];
            indexL++;
            temparr2++;
        }
    }

    // Merge temp array into main array
    for (int i = start; i < end; i++) {
        *array[i] = *temparr1;

        #if DEBUG
        std::cout << *temparr1 << ',';
        #endif

        temparr1++;
    }

    #if DEBUG
    std::cout << std::endl;
    #endif
}

int main() {
    srand(time(NULL));

    int array[ARRAY_SIZE];
    int* ptrArray[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % MAX_VAL;
        ptrArray[i] = &(array[i]);
    }

    printf("Array Before: {");
    prtArray(ptrArray, 0, ARRAY_SIZE);
    cout << "}" << endl;

    mergeSort(ptrArray, 0, ARRAY_SIZE);

    printf("Array After: {");
    prtArray(ptrArray, 0, ARRAY_SIZE);
    cout << "}" << endl;

    printf("sizeof(int):%li, std::size_t: %li\n", sizeof(int), sizeof(size_t));

    return 0;
}