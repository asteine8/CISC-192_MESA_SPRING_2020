#include <iostream>
#include <cstdio>

int pow(int val, int power) {
    int originalVal = val;
    if (power == 0) return 1;
    if (power < 0) return -1;
    for (int i = 0; i < power; i++) {
        val *= originalVal;
    }

    return val;
}

int printWithCommas(int value) {
    int numDigits = 1;
    while ((value/10) > 0) {
        numDigits++;
        value /= 10;
    }

    int numChars = 0;
    for (int i = numDigits; i > 0; i--) {
        std::cout << (value%pow(10,i)) / pow(10,i-1);
        numChars++;

        if (i % 3 == 1 && i != 1) {
            std::cout << ',';
            numChars++;
        }
    }

    return numChars;
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