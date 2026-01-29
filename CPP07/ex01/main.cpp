#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElem(T &elem) {
    std::cout << elem << " ";
}

template <typename T>
void printConstElem(const T &elem) {
    std::cout << elem << " ";
}

void increment(int &n) {
    n++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = 5;

    std::cout << "Original Ints: ";
    ::iter(arr, len, printElem<int>); 
    std::cout << std::endl;

    std::cout << "Incrementing..." << std::endl;
    ::iter(arr, len, increment);

    std::cout << "Modified Ints: ";
    ::iter(arr, len, printElem<int>);
    std::cout << std::endl;

    const std::string words[] = {"Hello", "World", "Templates"};
    
    std::cout << "Const Strings: ";
    ::iter(words, 3, printConstElem<std::string>);
    std::cout << std::endl;

    return 0;
}