#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>

template <typename T>
class Array {
    private:
        T* _data;
        unsigned int    _size;
    
    public:
        Array() : _data(NULL), _size(0) {}
    
        Array(unsigned int n) : _data(new T[n]()), _size(n) {}
    
        Array(const Array& other) : _data(NULL), _size(0) {
            *this = other;
        }
    
        Array& operator=(const Array& other) {
            if (this != &other) {
                if (_data)
                    delete[] _data;
                _size = other._size;
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _data[i] = other._data[i];
                }
            }
            return *this;
        }
    
        ~Array() {
            if (_data)
                delete[] _data;
        }
    
        T& operator[](unsigned int index) {
            if (index >= _size)
                throw std::exception();
            return _data[index];
        }
    
        const T& operator[](unsigned int index) const {
            if (index >= _size)
                throw std::exception();
            return _data[index];
        }
    
        unsigned int size() const {
            return _size;
        }
};

#endif
