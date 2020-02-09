/**------------------------------------------------------------------
*  2/8/2020 Alexandra Steiner (oryx26)
* 
*  guessnum.cpp  -  guesses a number and gives a recommendation for each
*               guess to result in a win every time
*
*       => Code modified from guessnum.cpp by T. Harrisburg
*  
*
* # How to win guessnum every time
*     1: Guess the number halfway between the highest possible number and the lowest possible number
*     2: If the guess is low, throw out all possibilities below the previous guess
*     3: If the guess is high, throw out all possibilities above the previous guess
*     4: Repeat from step 1 until you correctly guess the number
*     
* # Instructions for program use
*     The program guessnum.exe operates exactly like the original program but gives a recommendation for each
*     guess when asking for a guess. Simply guess the recommended guess each round and you are garunteed to
*     win.
*
-------------------------------------------------------------------*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

/**
 * intPow(int value, int power)
 * 
 * Simple function to calculate the value of
 * <value> to the power of <power>
 */
int intPow(int value, int power) {
    // Some error checking
    if (power == 0) return 1;
    if (power < 0) return -1;

    int initialValue = value;

    for (int i = 0; i < power-1; i++) {
        value = value * initialValue;
    }

    return value;
}

int main () {
    srand(time(NULL)) ;              // seed the randomizer
    int limit = 1000 ;               // set a range limit
    int secret = rand() % (limit+1);    // % is the "remainder" operator
    int max_tries = 10 ;
    int guess;

    double previousGuess = 0;
    double previousGuessResult = 1;
    double recommendedGuess;

    int trial;

    // Loop <max_tries> times
    for (trial = 1; trial <= max_tries; trial++) {

        // Calculate the absolute value to move the recommended guess from the previous guess
        int deltaGuess = ceil((double)limit/((double)intPow(2,trial)));

        // Constrain the delta value to a minimum of 1
        deltaGuess = deltaGuess < 1 ? 1 : deltaGuess;

        // Calculate the final recommended guess
        recommendedGuess = previousGuess + deltaGuess*previousGuessResult;

        // Get input from command line and display the recommended guess
        cout << "Guess (recommended: " << (int)round(recommendedGuess) << "): ";
        cin >> guess;

        // Compare guess vs secret and display results
        if (guess < secret) {
            cout << "Low\n";
            previousGuessResult = 1;
        }
        else if (guess > secret) {
            cout << "High\n";
            previousGuessResult = -1;
        }
        else {
            cout << "RIGHT!! YOU WIN!!!!\n";
            break;
        }

        // Kill loop and display losing message if too many tries
        if (trial == max_tries) {
            cout << "Too many guesses: you lose.\n" ;
            break;
        }

        // Store guess for next game round
        previousGuess = guess;
    }

    // Display results of game
    cout << "Number of tries: " << trial << ". Press ENTER:" << endl ;
    cout << "Number was " << secret;
    cin.get() ;

    return 0 ;  // (0 is good)
}


