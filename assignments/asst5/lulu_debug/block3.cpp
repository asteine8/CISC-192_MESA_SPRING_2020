#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std ;
int main (int argc, char *argv[], char **env)
{

    int characterPerGroup = atoi(argv[1]);
    int groupsPerLine = atoi(argv[2]);
    
    char c;
    c = cin.get();
    int i;
    int j;    

    while ( ! cin.eof())
    {
        i = 0;
        
        while (i < groupsPerLine && ! cin.eof())
        {
            j = 0;
            
            while (j < characterPerGroup && ! cin.eof())
            {
                if (isalnum(c))
                {
                    putchar(c);
                    j++;
                }
            }
            
            i++;
        }
        
        if ((i % groupsPerLine == 0) && (i!=0))
        {
            for (j = 0; j < characterPerGroup; j++)
            {
                cout << putchar(c);
                if (j % characterPerGroup == (characterPerGroup - 1)) cout << ' ';
                if (j % groupsPerLine == (groupsPerLine - 1)) cout << '\n';
            }
        }
        
        if (c == 10)
        {
            for (j = 0; j < characterPerGroup; j++)
            {
                cout << putchar(c);
                if (j % characterPerGroup == (characterPerGroup - 1)) cout << ' ';
                if (j % groupsPerLine == (groupsPerLine - 1)) cout << '\n';
            }
        }
    }
    
    if (argc < 3)
    {
        cout << "Cannot open the file.\nRe-enter." << endl;
    }
    
}