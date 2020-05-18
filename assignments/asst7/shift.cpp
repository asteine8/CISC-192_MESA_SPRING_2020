/** 
 * shift.cpp
 * 
 * This program implements a ceasar shift cipher command
 * line filter. Input validation for the 'shift' value is
 * very much present. Displays a help message if no
 * arguments are provided (needs shift value to work)
 * 
 * Alexandra Steiner - oryx26
 * April 29th, 2020
 */

#include <iostream>
#include <stdlib.h>
#include <ctype.h>

static const char* help_info = 
R"(shift <shiftvalue> < infile
-----
Applies a ceasar shift cipher to all alphabetic characters
in the infine. Alphabetic characters are made all lowercase.

    <shiftvalue>  : Amount of alphabetic characters to
                    shift input by. Must be integer numeric
)";

int shift = 0;

int main(int argc, char* argv[]) {
    // Case where no arguments inputted
    if (argc == 1) {
        std::cout << help_info << std::endl;
        return 255;
    }

    // Get argument 1 value as integer with some error checking
    if (sscanf(argv[1], "%i", &shift) == 0) {
        printf("##### Shift Argument Not Valid #####\n\n");
        std::cout << help_info << std::endl;
        return 255;
    }

    // Handle numbers not in range [-25, 25]
    shift = shift % 26;

    // Waterpump
    int c = '\0';
    while (EOF != (c = std::cin.get())) {
        // Only shift alphebetical characters
        if (isalpha(c)) {
            // Shift uppercase chars to lowercase
            c = tolower(c);
            
            // Shift chars to be in range [0, 26)
            c -= 0x61;

            // Shift chars
            c += shift;

            if (c < 0) c += 26; // handle looping under 'a'
            c = c % 26; // handle looping over 'z'

            // Shift chars back up to range [0x61, 0x7A]
            c += 0x61;
        }

        std::cout.put(c);
    }

    // Add a newline and flush output stream
    std::cout << std::endl;

    return 0;
}