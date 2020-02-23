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

void printWithCommas(long long value) {

}

int main(int argc, char *argv[]) {
    // initialize all as long long
    long long numYears = 0;
    long long numMonths, numDays, numHours, numMinutes, numSeconds;

    // Query user for number of years lived
    printf("Please enter the number of years you have lived: ");
    if (scanf("%i", &numYears) != 1 || numYears<=0) {
        printf("Did not get a valid input. Please enter a positive, non-zero integer value\n\n");
        return 0;
    }
    printf("You entered: %i\n", numYears);

    // Calculate values
    numMonths = numYears * 12LL;
    numDays = 0.5 + ((double)numYears * 365.25);
    numHours = numDays * 24LL;
    numMinutes = numHours * 60LL;
    numSeconds = numMinutes * 60LL;

    printf("sizeof(<>): %d\n", sizeof(long long));
    
    printf("Num seconds alive: %lld\n", numSeconds);
    printWithCommas(numSeconds);
    std::cout<<std::endl;

    return 0;
}