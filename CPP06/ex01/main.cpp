#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data myData;
    myData.name = "Test Data";
    myData.value = 42;
    myData.next = NULL;

    std::cout << "Original Address: " << &myData << std::endl;
    std::cout << "Original Name:    " << myData.name << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized (Raw): " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Address: " << ptr << std::endl;

    if (ptr == &myData) {
        std::cout << "SUCCESS! Pointers match." << std::endl;
        std::cout << "Recovered Name: " << ptr->name << std::endl;
    } else {
        std::cout << "ERROR! Pointers do not match." << std::endl;
    }

    return 0;
}