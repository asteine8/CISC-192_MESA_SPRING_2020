/** 
 * caesarb.cpp
 * 
 * This program implements Caesar Block Cypher filter
 * and applies it to the input stream. Error checking
 * is present and a linked list is used to dynamically
 * store the input stream to prevent buffer overflow.
 * 
 * Alexandra Steiner - oryx26
 * May 7th, 2020
 */

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <cmath>

#define DEBUG 0

static const char* help_info = 
R"(caesarb -[option] < infine
-----
Applies a Caesar Block Cypher to the input stream.

    [option] - An optional argument

        -h -H => Displays this help message
)";

// Node structure for linked list
struct node {
    int c;
    node *next;
};

// Linked list class
class LinkedString {
    private:
        node *head;
        node *tail;
    public:
        long length;

        LinkedString() {
            head = NULL;
            tail = NULL;
            length = 0;
        }

        void addNode(int c) {
            node *tmpNode = new node;
            tmpNode->c = c;
            tmpNode->next = NULL;

            if (head == NULL) {
                head = tmpNode;
                tail = tmpNode;
            }
            else {
                tail->next = tmpNode;
                tail = tmpNode;
            }

            length++;
        }

        node* getHead() {
            return head;
        }

        node* getTail() {
            return tail;
        }
};

int main(int argc, char* argv[]) {
    // Handle Options
    if (argc > 1) {
        switch (argv[1][1]) {
            case 'h':
            case 'H': // Display help
                std::cout << help_info << std::endl;
                return 255;
                break;
        }
    }

    // Initialize input string
    LinkedString inString;

    // Waterpump in istream
    int c = '\0';
    while (EOF != (c = std::cin.get())) {
        if (isalnum(c)) {
            inString.addNode(c);
        }
    }

    // Get matrix dimensions. Ceiling round to ensure we can fit everything
    int squareSize = ceil(sqrt(inString.length));

    #if DEBUG==1
    printf("numchars = %i | sqrsize = %i\n", numChars, squareSize);
    #endif

    // Initialize matrix to store input stream
    int** inputmatrix = new int*[squareSize];
    for (int i = 0; i < squareSize; i++) {
        inputmatrix[i] = new int[squareSize];
    }

    // Read input stream into matrix in Col-Row form
    node *n = inString.getHead();
    for (int row = 0; row < squareSize; row++) {
        for (int col = 0; col < squareSize; col++) {
            if(n->next != NULL) {
                // Go through inString until we get an alnum char
                if (isalnum(n->c)) {
                    inputmatrix[row][col] = n->c;
                    #if DEBUG==1
                    printf("%c ", n->c);
                    #endif
                }
                else {
                    // lets try this again...
                    col--;
                }

                // Get next node
                n = n->next;
            }
            else { // End of string reached: fill with '\0' characters
                inputmatrix[row][col] = '\0';
            }
        }
        #if DEBUG==1
        printf("\n");
        #endif
    }

    int cOutput = '\0';
    // Output matrix in Row-Col form
    for (int col = 0; col < squareSize; col++) {
        for (int row = 0; row < squareSize; row++) {

            cOutput = inputmatrix[row][col];
            // Check to make sure this isn't a blank cell
            if (cOutput != '\0') {
                std::cout.put(cOutput);
            }
        }
    }

    return 0;
}