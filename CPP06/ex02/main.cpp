#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception> 

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int r = std::rand() % 3;

    if (r == 0) return new A();
    if (r == 1) return new B();
    return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown" << std::endl;
}

int main() {
    std::srand(std::time(NULL));

    Base* ptr = generate();

    std::cout << "Identify via Pointer:   ";
    identify(ptr);

    std::cout << "Identify via Reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}