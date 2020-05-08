#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
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
                
                c = cin.get();
            }
            cout.put(' ');
            
            i++;
        }
        
        cout.put('\n');
        
    }
    
    if (argc < 3)
    {
        cout << "Cannot open the file.\nRe-enter." << endl;
    }
    
}