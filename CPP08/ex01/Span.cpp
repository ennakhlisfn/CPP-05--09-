#include "Span.hpp"
#include <limits>

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &src) : _n(src._n), _storage(src._storage) {}

Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        this->_n = rhs._n;
        this->_storage = rhs._storage;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_storage.size() >= _n)
        throw SpanFullException();
    _storage.push_back(number);
}

long Span::shortestSpan() const {
    if (_storage.size() <= 1)
        throw NoSpanException();

    std::vector<int> sorted = _storage;
    std::sort(sorted.begin(), sorted.end());

    long min_span = std::numeric_limits<long>::max();

    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        long current_span = static_cast<long>(sorted[i + 1]) - sorted[i];
        if (current_span < min_span)
            min_span = current_span;
    }
    return min_span;
}

long Span::longestSpan() const {
    if (_storage.size() <= 1)
        throw NoSpanException();

    int min_val = *std::min_element(_storage.begin(), _storage.end());
    int max_val = *std::max_element(_storage.begin(), _storage.end());

    return static_cast<long>(max_val) - min_val;
}