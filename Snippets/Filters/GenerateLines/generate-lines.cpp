#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Settings
bool debug = false;

enum OUTPUT_TYPE {INT, STR};
OUTPUT_TYPE outputType = OUTPUT_TYPE::INT;

int numlines = 10;
int linesize = 10;

const char* helpInfo =
R"(
    
        generatelines [OPTION] <numlines> <linesize>

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
*          -i -int  : Generate random integers
*          -s -str  : Generate random strings
*          
*

)";

int main (int argc, char** argv) {
    // Get options
    int numOptions = 0;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] = '-') {
            numOptions++;
            switch(argv[i][1]) {
                case 'h':
                    printf(helpInfo);
                    return 0;
                case 'd':
                case 'v':
                    debug = true;
                    break;
                case 'i':
                    outputType = OUTPUT_TYPE::INT;
                    break;
                case 's':
                    outputType = OUTPUT_TYPE::STR;
                    break;
            }
        }
    }

    // Get cli arguments
    switch (argc-1-numOptions) {
        case 2: // generatelines <numlines> <linesize>
            linesize = 
        case 1: // generatelines <numlines>

    }

    

    for (int i = 0; i < )

    return 0;
}