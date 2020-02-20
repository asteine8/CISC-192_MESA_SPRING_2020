
#include<iostream>

class Iterator {

    private:
    uint8_t value;

    public:

    Iterator(uint8_t v) {
        Iterator::value = v;
    }

    void iteratevalue();

    uint8_t getvalue() {
        return Iterator::value;
    }
};

void Iterator::iteratevalue() {
    Iterator::value ++;
}

int main() {
    Iterator iterator(100);

    for (int i = 0; i < 100; i++) {
        iterator.iteratevalue();
    }

    std::cout << "The value the iterator is now " << (int)iterator.getvalue();

    return 0;
}