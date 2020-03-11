#ifndef BIG_NUMBER_H
#define BIG_NUMBER_H

class BigNumber {
    public:
        char* digits;
        int sign;

        long long numdigits;

        BigNumber() {
            digits = new char[1];
            *digits = 0;

            numdigits = 1;
        }
};


#endif