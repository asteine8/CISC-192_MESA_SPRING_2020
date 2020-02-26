#include <iostream>
#include <stdio.h>

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

    printf("start: %i, end:%i, numel:%i, middle:%i\n", start, end, numel, middle);
    prtArray(array, start, end);
    std::cout << std::endl;
    
    int* temparr = new int[numel];
    int* temparrPtr = temparr;
    int indexL = start;
    int indexU = middle+1;
    
    
    // Merge into temp array
    while (true) {
        if (indexL == middle && indexU == end) break;
        if (indexL == middle) {
            *temparrPtr = *array[indexU];
            indexU++;
            temparrPtr++;
        }
        else if (indexU == end) {
            printf("ow\n");
            *temparrPtr = *array[indexL];
            indexL++;
            temparrPtr++;
        }
        else if (*array[indexL] > *array[indexU]) {
            printf("ow2\n");
            *temparrPtr = *array[indexU];
            indexU++;
            temparrPtr++;
        }
        else {
            printf("ow3\n");
            *temparrPtr = *array[indexL];
            indexL++;
            temparrPtr++;
        }
    }
    

    // Merge temp array into main array
    for (int i = start; i < end; i++) {
        *array[i] = *temparr;
        std::cout << *temparr << ',';
        temparr++;
    }
    std::cout << std::endl;
    
    // delete[] temparr;
}



int main() {

    int array[] = {4,2,8,9,3,7};
    int* ptrArray[6];

    for (int i = 0; i < 6; i++) {
        ptrArray[i] = &(array[i]);
    }

    mergeSort(ptrArray, 0, 6);

    for (int i = 0; i < 6; i++) {
        std::cout << *ptrArray[i] << ',';
    }

    std::cout << std::endl;

    return 0;
}