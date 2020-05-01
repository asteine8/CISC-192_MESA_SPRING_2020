#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std ;

int main (int argc, char *argv[], char **env)
{
    char c ;
    c = cin.get() ;
    while ( ! cin.eof())
    {
        cout.put(c )  ;
        c = cin.get() ;
    }

    int i, j;
    int row;
    int col;
    string line;
    string array [row][col];

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
        {
            if (cin.get())
            {
                array [i][j] = line;
                cout << line ;
            }
        }
    }
}

char c ;
c = cin.get() ;
while ( ! cin.eof())
{
    cout.put(c )  ;
    c = cin.get() ;
}