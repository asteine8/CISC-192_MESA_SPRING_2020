#ifndef CHARARRAY_H
#define CHARARRAY_H

class CharArray {
    public:
        char* array;

        // Constructors
        CharArray();
        CharArray(char* str);

        // Destructor
        ~CharArray();

        void reverse();
        void toUppercase();
        void toLowercase();

        int findTerm(char* searchTerm);
        int findTerm(CharArray searchTerm);

        void append(char* str);
        void append(CharArray str);

        int numCharacters();
        int numCharacters(char* str);
};

#endif