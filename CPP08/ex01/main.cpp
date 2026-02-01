#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    std::cout << "--- Subject Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Large Data Test (20,000 numbers) ---" << std::endl;
    try {
        unsigned int size = 20000;
        Span bigSpan(size);
        std::vector<int> randomNumbers;
        
        std::srand(std::time(NULL));
        for (unsigned int i = 0; i < size; ++i) {
            randomNumbers.push_back(std::rand());
        }

        bigSpan.addRange(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Exception Test (Full Span) ---" << std::endl;
    try {
        Span small(2);
        small.addNumber(1);
        small.addNumber(2);
        small.addNumber(3);
    } catch (const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Exception Test (Empty/One element) ---" << std::endl;
    try {
        Span empty(5);
        empty.addNumber(42);
        empty.shortestSpan();
    } catch (const std::exception& e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    return 0;
}

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }