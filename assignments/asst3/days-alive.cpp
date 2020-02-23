#include <iostream>
#include <cstdio>
#include <stdlib.h>

int pow(int val, int power) {
    int originalVal = val;
    if (power == 0) return 1;
    if (power < 0) return -1;
    for (int i = 0; i < power; i++) {
        val *= originalVal;
    }

    return val;
}

void printWithCommas(int value) {
    char buffer[100];

    itoa (value, buffer, 10);

    printf("%s",buffer);

}

int main(int argc, char *argv[]) {
    int numYearsLived = 0;
    int numMonths, numDays, numHours, numMinutes, numSeconds;

    // Query user for number of years lived
    printf("Please enter the number of years you have lived: ");
    if (scanf("%i", &numYearsLived) != 1 || numYearsLived<0) {
        printf("Did not get a valid input. Please enter a positive integer value\n\n");
        return 0;
    }
    printf("You entered %i\n", numYearsLived);

    numMonths = numYearsLived * 12;
    numDays = 0.5 + ((double)numYearsLived * 365.25);
    numHours = numDays * 24;
    numMinutes = numHours * 60;
    numSeconds = numMinutes * 60;
    
    printf("Num seconds alive: %d\n", numSeconds);
    printWithCommas(numSeconds);
    std::cout<<std::endl;

    return 0;
}