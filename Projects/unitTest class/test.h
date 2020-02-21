#ifndef TEST_H
#define TEST_H

class Test {
  public:
    template<class T>
    void assertEquals(const char* message, T expected, T actual, const char* errMessage);
    
    template<class T>
    void assertArrayEquals(char* message, T* expected, T* actual, char* errMessage);

    void printCharPointer(const char* str);

};

#endif

/*
void func ( void (*f)(int) ) {
  for ( int ctr = 0 ; ctr < 5 ; ctr++ ) {
    (*f)(ctr);
  }
}
*/
