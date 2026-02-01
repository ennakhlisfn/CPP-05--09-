#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::cout << "--- Testing with std::vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found value: " << *it << " at vector position: " 
                  << std::distance(vec.begin(), it) << std::endl;
        
        std::cout << "Attempting to find non-existent value (50)..." << std::endl;
        easyfind(vec, 50);
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Testing with std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::list<int>::iterator it_list = easyfind(lst, 2);
        std::cout << "Found value: " << *it_list << " at list position: "
                  << std::distance(lst.begin(), it_list)  << std::endl;
        
        std::cout << "Attempting to find non-existent value (99)..." << std::endl;
        easyfind(lst, 99);
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}