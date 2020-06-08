#include <string>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cctype>




using namespace std ;




int main (int argc, char *argv[], char **env)
{
    char c ;
    
    char str;
    
    int shift = atoi(argv[1]);
    
    do
    {
        cin.get() ;
        
        if (isalpha(c))
            {
                tolower(c);
                
                str = c - 97 + shift;
                
                c = str % 26;
                
                c += 97;
                
                cout << c;
            }
        else
        {
            cout << c;
        }
                
    }
    
    while ( ! cin.eof());
}