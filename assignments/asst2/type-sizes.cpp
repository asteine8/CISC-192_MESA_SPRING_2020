/** 
 * type-sizes.cpp
 * 
 * This program displays the size in bytes of most common datatypes
 * defined in the C++ standard distribution
 * 
 * Alexandra Steiner - oryx26
 * Feb 14th, 2019
 */

#include <iostream>

#define DISPLAY_SIZE(TYPE) cout<<"The size of the "<<#TYPE<<" datatype is: "<<sizeof(TYPE)<<" bytes"<<endl
#define NEW_LINE cout<<endl

using namespace std;

int main() {
    DISPLAY_SIZE(bool);
    DISPLAY_SIZE(bool*);

    NEW_LINE;

    DISPLAY_SIZE(char);
    DISPLAY_SIZE(char*);
    DISPLAY_SIZE(char**);
    
    NEW_LINE;

    DISPLAY_SIZE(wchar_t);
    DISPLAY_SIZE(wchar_t*);

    NEW_LINE;

    DISPLAY_SIZE(short);
    DISPLAY_SIZE(short*);
    DISPLAY_SIZE(unsigned short);
    DISPLAY_SIZE(signed short);

    NEW_LINE;

    DISPLAY_SIZE(int);
    DISPLAY_SIZE(int*);
    DISPLAY_SIZE(unsigned int);
    DISPLAY_SIZE(signed int);

    NEW_LINE;

    DISPLAY_SIZE(long);
    DISPLAY_SIZE(long*);
    DISPLAY_SIZE(unsigned long);
    DISPLAY_SIZE(signed long);

    NEW_LINE;

    DISPLAY_SIZE(long long);
    DISPLAY_SIZE(long long*);
    DISPLAY_SIZE(unsigned long long);
    DISPLAY_SIZE(signed long long);

    NEW_LINE;

    DISPLAY_SIZE(float);
    DISPLAY_SIZE(float*);

    NEW_LINE;

    DISPLAY_SIZE(double);
    DISPLAY_SIZE(double*);

    NEW_LINE;

    DISPLAY_SIZE(long double);
    DISPLAY_SIZE(long double*);

    NEW_LINE;

    DISPLAY_SIZE(uint8_t);
    DISPLAY_SIZE(int8_t);
    DISPLAY_SIZE(uint16_t);
    DISPLAY_SIZE(int16_t);
    DISPLAY_SIZE(uint32_t);
    DISPLAY_SIZE(int32_t);
    DISPLAY_SIZE(uint64_t);
    DISPLAY_SIZE(int64_t);
    DISPLAY_SIZE(__uint128_t);
    DISPLAY_SIZE(__int128_t);

    return 0;
}
