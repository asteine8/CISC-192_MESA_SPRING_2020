#include <stdio.h>
#include <iostream>

int main() {
    long long years, days, hours, minutes, seconds;
    printf("Enter how many years you have lived: ");
    scanf("%lli", &years);
    days=0.5+((double)years*365.25);
    hours=days*24LL;
    minutes=hours*60LL;
    seconds=minutes*60LL;
    printf("%-8s: %-20lli\n", "Years", years);
    printf("%-8s: %-20lli\n", "Days", days);
    printf("%-8s: %-20lli\n", "Hours", hours);
    printf("%-8s: %-20lli\n", "Minutes", minutes);
    printf("%-8s: %-20lli\n", "Seconds", seconds);
}