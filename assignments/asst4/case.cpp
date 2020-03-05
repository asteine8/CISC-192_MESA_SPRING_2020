/** 
 * case.cpp
 * 
 * This program converts text from the standard input stream to
 * either uppercase or lowercase depending on command line
 * arguments.
 * 
 * Alexandra Steiner - oryx26
 * March 3rd, 2020
 */

#include <stdio.h>
#include <iostream>

enum CASE {LOWER, UPPER};
CASE caseSetting = CASE::LOWER;

// A nice help string to display
const char* helpinfo = 
R"(
    case [ OPTIONS ] < infile

        Reads standard input and changes its case as specified
        in [ OPTIONS ]


    ### Options ###

        -l -L : Converts all alphabetical characters to lowercase

        -u -U : Converts all alphabetical characters to uppercase

        -h    : Displays this help text
)";

char toLower(char c);
char toUpper(char c);

int main(int argc, char** argv) {
    // Display help if no options are selected
    if (argc == 1) {
        std::puts(helpinfo);
        return 255;
    }

    // Handle Properties
    for (int i = 1; i < argc; i++) {
        // Check if this is a property
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'l': // To lowercase
                    caseSetting = CASE::LOWER;
                    break;
                case 'U':
                case 'u': // To uppercase
                    caseSetting = CASE::UPPER;
                    break;
                case 'H':
                case 'h': // Display help
                    std::puts(helpinfo);
                    return 0;
            }
        }
    }

    // Basic waterpump
    register int c = '\0';
    while (EOF != (c = std::cin.get())) {
        // Change case
        switch (caseSetting) {
            case LOWER:
                c = toLower(c);
                break;
            case UPPER:
                c = toUpper(c);
                break;
        }

        // Write to standard output
        std::cout.put(c);
    }

    return 0;
}

// Convert character if alphabetic to lowercase
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c | 0x20;
    }
}

// Convert character if alphabetic to uppercase
char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c & (~0x20);
    }
}
