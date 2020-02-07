/*-------------------------------------------------------------------
*  guessnum.cpp   -  guess the number
*  (Your Name)   (date)
This is a real program.  Nothing's explained yet, just like a baby
learning to repeat adult speech.  Relax into it.
I tried to get all the SEVEN THINGS into this, so if you want, print it
out and mark it up with your guesses as to which Thing each part of the
program does.  Most right guesses gets bragging rights.
-------------------------------------------------------------------*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int intPow(int value, int power) {
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
    int limit = 1001 ;               // set a range limit
    int secret = rand() % limit ;    // % is the "remainder" operator
    int max_tries = 10 ;
    int guess;

    int previousGuess = 0;
    int previousGuessResult = 1;
    int recommendedGuess;

    int trial;
    for (trial = 1; trial <= max_tries; trial++ ) {

        int deltaGuess = limit/(intPow(2,trial);
        deltaGuess = deltaGuess < 1 ? 1 : deltaGuess;

        recommendedGuess = previousGuess + deltaGuess*previousGuessResult;

        cout << "Guess (recommended: " << recommendedGuess << "): ";
        cin >> guess;


        if (guess < secret) {
            cout << "Low\n";
            previousGuessResult = 1;
        }
        else if (guess > secret) {
            cout << "High\n";
            previousGuessResult = -1;
        }
        else {
            cout << "RIGHT!!\n";
            break;
        }

        if (trial == max_tries) {
            cout << "Too many guesses: you lose.\n" ;
            break;
        }

        previousGuess = guess;
    }


    cout << "Number of tries: " << trial << ". Press ENTER:" << endl ;
    cout << "Number was " << secret;
    cin.get() ;
    return 0 ;  // (0 is good)
}


