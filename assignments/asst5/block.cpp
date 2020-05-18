/** 
 * block.cpp
 * 
 * This program displays alphanumeric standard input 
 * as blocks with a user defined block size and number
 * of blocks per line. Error checking and help
 * messages are included
 * 
 * Alexandra Steiner - oryx26
 * March 21st, 2020
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SEPERATOR ' '
#define NEWLINE_SEPERATOR '\n'

static const char* help_info = 
R"(block <numchars> <numblocks> < infile

    <numchars>  : Number characters per block
                    * Must be greater than 0

    <numblocks> : Number blocks per line
                    * Must be greater than 0
)";

int blockSize = 10; // Number chars in a block
int lineSize = 10; // Number blocks in a line

int main(int argc, char* argv[]) {

    // Check that we have enough arguments
    if (argc < 3) {
        std::cout << help_info << std::endl;
        return 255;
    }
    
    // Convert arguments to numerics and do error checking
    if (sscanf(argv[1],"%d", &blockSize) > 0
        && sscanf(argv[2],"%d", &lineSize) > 0);
    else {
        std::cout << help_info << std::endl;
        return 255;
    }

    // Check if arguments are non-zero
    if (blockSize > 0 && lineSize > 0);
    else {
        std::cout << help_info << std::endl;
        return 255;
    }

    int charIndex = 0;
    int blockIndex = 0;

    int c;
    while(-1 != (c = std::cin.get())) {


        // Only process char if char is alphanumeric
        if (isalnum(c)) {

            // Check for new line
            if (blockIndex == lineSize) {
                // Add newline seperator
                std::cout.put(NEWLINE_SEPERATOR);

                blockIndex = 0;
            }
            
            // Put char in output stream
            std::cout.put(c);
            charIndex++;

            // Check for end of block
            if (charIndex == blockSize) {
                charIndex = 0;
                blockIndex++;

                // Add seperator at end of block if not last block
                if (blockIndex != lineSize) {
                    std::cout.put(BLOCK_SEPERATOR);
                }
            }
        }
    }

    // Newline at end for style >_<
    std::cout << std::endl;

    return 0;
}