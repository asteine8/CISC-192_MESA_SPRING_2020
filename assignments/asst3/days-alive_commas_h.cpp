#include "commas.h"

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
    std::string yearStrWithCommas = commas(yearStr, 3);

    std::string dayStr = std::to_string(days);
    std::string dayStrWithCommas = commas(dayStr, 3);

    std::string hourStr = std::to_string(hours);
    std::string hourStrWithCommas = commas(hourStr, 3);

    std::string minuteStr = std::to_string(minutes);
    std::string minuteStrWithCommas = commas(minuteStr, 3);

    std::string secondStr = std::to_string(seconds);
    std::string secondStrWithCommas = commas(secondStr, 3);

    printf("%-8s: %-25s \n", "Years", yearStrWithCommas.c_str());
    printf("%-8s: %-25s \n", "Days", dayStrWithCommas.c_str());
    printf("%-8s: %-25s \n", "Hours", hourStrWithCommas.c_str());
    printf("%-8s: %-25s \n", "Minutes", minuteStrWithCommas.c_str());
    printf("%-8s: %-25s \n", "Seconds", secondStrWithCommas.c_str());

    return 0;
}