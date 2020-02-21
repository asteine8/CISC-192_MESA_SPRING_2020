#include <iostream>

#include "test.h"

/**
 * assertEquals(char* message, T expected, T actuals)
 * 
 * Returns message when expected != actuals
 */
template<class T>
void Test::assertEquals(const char* message, T expected, T actual, const char* errMessage) {
    printCharPointer(message);
    std::cout << ": " << std::endl;

    std::cout << "Expected '" << expected << "', got '" << actual << "'" << std::endl;
    
    if (expected == actual) std::cout << "Test Pass";
    else std::cout << "Test Fail: " << errMessage;

    std::cout << "\n" << std::endl;
}

/**
 * assertArrayEquals(char* message, T* expected, T* actuals)
 * 
 * Returns message when expected != actuals
 */
template<class T>
void Test::assertArrayEquals(char* message, T* expected, T* actual, char* errMessage) {
    if (expected == actual) {
        
    }
}

/**
 * Test::printCharPointer(char* str, bool useEndl = false)
 * 
 * prints a char* to std::cout with an option to add an std::endl
 */
void Test::printCharPointer(const char* str) {
    while (*str != '\0') {
        std::cout << *str;
        str++;
    }
}