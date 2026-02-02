#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <sys/time.h>

long long currentTimeMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (static_cast<long long>(tv.tv_sec) * 1000000) + tv.tv_usec;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    try {
        for (int i = 1; i < argc; ++i) {
            char *endptr;
            long val = std::strtol(argv[i], &endptr, 10);
            if (*endptr != '\0' || val < 0) throw std::exception();
            vec.push_back(static_cast<int>(val));
            deq.push_back(static_cast<int>(val));
        }
    } catch (...) {
        std::cerr << "Error: Invalid input (positive integers only)." << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size() && i < 10; ++i) std::cout << vec[i] << " ";
    if (vec.size() > 10) std::cout << "[...]";
    std::cout << std::endl;

    PmergeMe sorter;

    long long startVec = currentTimeMicros();
    sorter.sortVector(vec);
    long long endVec = currentTimeMicros();

    long long startDeq = currentTimeMicros();
    sorter.sortDeque(deq);
    long long endDeq = currentTimeMicros();

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size() && i < 10; ++i) std::cout << vec[i] << " ";
    if (vec.size() > 10) std::cout << "[...]";
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec);
    double timeDeq = static_cast<double>(endDeq - startDeq);

    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;

    return 0;
}