
int** mergeSort(int** addresses, unsigned int len) {
    if (len == 2) {
        if (**addresses > **(++addresses)) {
            int** temp = addresses;
            addresses = --addresses;
            addresses = temp;
        }
        return addresses;
    }

    int len1 = len/2;
    int len2 = len-len1;

    int** sortedLowerSide = mergeSort(addresses, len1);
    int** sortedUpperSide = mergeSort(addresses+len1, len2);

    int i,j;
    i=j=0;
    while (i < len1 || j < len2) {
        
    }
    
}

