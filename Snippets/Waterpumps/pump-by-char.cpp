#include <iostream>

void do_something(char c) {
    std::cout << c;
}

int main() {
    char c = std::cin.get();

    while (!std::cin.eof()) {
        do_something(c);
        c = std::cin.get();
    }

    std::cout << std::endl;

    return 0;
}