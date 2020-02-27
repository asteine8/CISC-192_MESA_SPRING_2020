/** 
 * block.cpp
 * 
 * This propgram formats data seperated by newlines and condenses it
 * into blocks with specified width, specified number of blocks per
 * line, and allows for a delay between each output. block.cpp is meant
 * to act as a CLI output pump and has the command line options to boot.
 * 
 * Alexandra Steiner - oryx26
 * Feb 27th, 2020
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// Check for Unix vs Windows function libraries (need delay)
#ifdef __has_include
    #if __has_include(<unistd.h>)
        #include <unistd.h>
    #else
        #include <windows.h>
    #endif
#else
    #include <unistd.h>
#endif

using namespace std;

const char* helpInfo = 
R"(
    
        block [OPTION] <blocksize> <blocksperline> <msLineDelay>

*   The block command formats data seperated by newlines and condenses
*   it into blocks with specified width, specified number of blocks per
*   line, and allows for a delay between each output.
*
*   <blocksize>     : The number of characters in each block
*                     (Not including terminator) [default: 10]
*   <blocksperline> : The number of blocks printed per line
*                     [default: 1]
*   <msLineDelay>   : Waits this number of milliseconds before writing 
*                     the next line [default: 100]  
*
*       ++OPTIONS++
*
*          -h -help : Displays this help message
*          -d -v    : Displays debug messages
*

)";

bool debug = false;

int blockSize = 10;
int blocksPerLine = 1;
int msLineDelay = 100;

int main(int argc, char* argv[]) {
    // Set settings based on command line arguments
    if (argc == 1) {printf("Didn't recieve enough arguments, printing help: %s", helpInfo); return 0;}
    // Test for [OPTION] value
    int numOptions = 0;
    while (argv[numOptions+1][0] == '-') {
        switch (argv[numOptions+1][1]) {
            case 'h': // Help
                printf("Displaying help: %s", helpInfo);
                return 0;
            case 'd': // Debug
            case 'v':
                debug = true;
                break;
        }
        numOptions++;
        if (numOptions+1 >= argc) break;
    }
    
    // Get general arguments
    switch(argc-numOptions-1) {
        case 3: // block <blocksize> <blocksperline> <msLineDelay>
            msLineDelay = atoi(argv[3+numOptions]);
        case 2: // block <blocksize> <blocksperline>
            blocksPerLine = atoi(argv[2+numOptions]);
        case 1: // block <blocksize>
            blockSize = atoi(argv[1+numOptions]);
            break;
        case 0: // Display Help
            printf("Didn't recieve enough arguments, printing help: %s", helpInfo);
            return 0;
    }

    // Validate input
    if (blockSize <= 0) {printf("Recieved zero or negative block size, quitting"); return 1;}
    if (blocksPerLine <= 0) {printf("Recieved zero or negative blocks per line, quitting"); return 1;}
    if (msLineDelay < 0) {printf("Recieved negative ms delay, quitting"); return 1;}

    unsigned int lineNumber = 1;
    int numSpaces;
    char line[blockSize+1];

    // Do this until the end of file
    while (!cin.eof() && !cin.fail()) {
        
        // Get characters from stream and slap it into the line array
        int numCharsGotten = 0;
        char c;
        for (int i = 0; numCharsGotten < blockSize; i++) {
            c = cin.get();
            if (c == '\n' || cin.eof()) break;
            line[i] = c;
            numCharsGotten++;
        }

        // Set last char to null terminator
        line[numCharsGotten] = '\0';

        // Seek to next '\n' char if we didn't seek there during the read
        while (c != '\n' && ! cin.eof()) {
            c = cin.get();
        }

        // Write line to the screen for a maximim number of chars of blockSize
        for (int i = 0; i < blockSize && line[i] != '\0'; i++) {
            cout.put(line[i]);
        }
        
        // Add spaces to end to maintain min block size
        numSpaces = blockSize - numCharsGotten;
        while (numSpaces > 0) {
            std::cout << ' ';
            numSpaces--;
        }

        // Add a newline if blocksPerLine has been reached
        // Otherwise, add spaces to the end of the block
        if (lineNumber % blocksPerLine == 0) {
            std::cout << std::endl;

            // Implement delay between lines

            // Unix Version
            #ifdef _POSIX_VERSION
            usleep(msLineDelay * 1000);
            #endif

            // Windows Version
            #ifdef _WINDOWS_H
            Sleep(msLineDelay);
            #endif
        }
        else {
            std::cout << "  ";
        }

        lineNumber++;
    }

    // Flush and add a newline at the end
    std::cout << std::endl;

    if (debug) {
        printf("+++ Debug Stuff +++\n");
        printf("blkSize: %i\nblksperline: %i\nmsLineDelay: %ims\n", blockSize, blocksPerLine, msLineDelay);
        printf("Lines Printed: %i\n", lineNumber);

    }

    // yay!, we did it!
    return 0;
}