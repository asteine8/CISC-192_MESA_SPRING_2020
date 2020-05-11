// #include "commas.h"

#include <stdio.h>
#include <iostream>
#include <string>

int main() {
    long long years, days, hours, minutes, seconds;
    printf("Enter how many years you have lived: ");
    scanf("%lli", &years);
    days=0.5+((double)years*365.25);
    hours=days*24LL;
    minutes=hours*60LL;
    seconds=minutes*60LL;


    std::string yearStr = std::to_string(years);
    // std::string yearStrWithCommas = commas(yearStr, 3);

    // printf("%-8s: %-25s \n", "Years", yearStrWithCommas);

    // printf("%-8s: %-20lli\n", "Years", years);
    // printf("%-8s: %-20lli\n", "Days", days);
    // printf("%-8s: %-20lli\n", "Hours", hours);
    // printf("%-8s: %-20lli\n", "Minutes", minutes);
    // printf("%-8s: %-20lli\n", "Seconds", seconds);

    return 0;
}