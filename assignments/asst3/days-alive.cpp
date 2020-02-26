#include <iostream>
#include <cstdio>
#include <stdlib.h>

#define BUFFER_SIZE 20

/**
 * long long pow(long long val, int power)
 * Calculates the value of 'val' to the power of 'power'
 */
long long pow(long long val, int power) {
    long long originalVal = val;
    if (power == 0) return 1;
    if (power == 1) return val;
    if (power < 0) return -1;
    for (int i = 1; i < power; i++) {
        val *= originalVal;
    }

    return val;
}

/**
 * int numDigits(long long val)
 * 
 * Calculates the number of base 10 digits in 'val'
 */
int numDigits(long long val) {
    int numDigits = 1;
    while (val >= 10LL) {
        val = val / 10LL;
        numDigits++;
    }
    return numDigits;
}

/**
 * int numChars(char* str)
 * 
 * returns the number of characters in the string including the '\0' char
 */
int numChars(char* str) {
    int numChars = 0;
    while (*str != '\0') {
        numChars++;
        str++;
    }
    numChars++;
    return numChars;
}

/**
 * void to_str_with_commas(long long value, char* str)
 * 
 * Converts value to a char array with commas and stores it in str
 */
void to_str_with_commas(long long value, char* str) {
    int digits = numDigits(value)-1;

    int digitValue;
    for (int i = digits; i >= 0;) {
        if (i%3 == 0 && i != digits && i != 0) {
            *str = ',';
            str++;
        }

        digitValue = value / pow(10LL, i);
        value = value % pow(10LL, i);

        *str = (char)(digitValue+0x30);
        str++;
        
        i--;
    }
    *str = '\0';
}

int main(int argc, char *argv[]) {
    // initialize all as long long
    long long years = 0;
    long long days, hours, minutes, seconds;

    // Query user for number of years lived and do some input validation
    printf("Please enter the number of years you have lived: ");
    if (scanf("%lli", &years) != 1 || years<=0) {
        printf("Did not get a valid input. Please enter a positive, non-zero integer value\n\n");
        return 0;
    }
    if (years > 100000000000) {
        printf("You are too old.\n\n");
        return 0;
    }

    // Calculate values
    days = 0.5 + ((double)years * 365.25);
    hours = days * 24LL;
    minutes = hours * 60LL;
    seconds = minutes * 60LL;

    // Convert values to strings
    char yearsStr[BUFFER_SIZE], daysStr[BUFFER_SIZE], hoursStr[BUFFER_SIZE], minutesStr[BUFFER_SIZE], secondsStr[BUFFER_SIZE];
    to_str_with_commas(years, yearsStr);
    to_str_with_commas(days, daysStr);
    to_str_with_commas(hours, hoursStr);
    to_str_with_commas(minutes, minutesStr);
    to_str_with_commas(seconds, secondsStr);

    // Print values
    printf("%8s: %-20s\n", "Years", yearsStr);
    printf("%8s: %-20s\n", "Days", daysStr);
    printf("%8s: %-20s\n", "Hours", hoursStr);
    printf("%8s: %-20s\n", "Minutes", minutesStr);
    printf("%8s: %-20s\n", "Seconds", secondsStr);

    return 0;
}
