#ifndef TEST_H
#define TEST_H

class Test {
    public:
        
        template<class T>
        void assertEquals(char* message, T expected, T actual, char* errMessage);

        template<class T>
        void assertArrayEquals(char* message, T* expected, T* actual, char* errMessage);

        

};

#endif

/*
void func ( void (*f)(int) ) {
  for ( int ctr = 0 ; ctr < 5 ; ctr++ ) {
    (*f)(ctr);
  }
}
*/
