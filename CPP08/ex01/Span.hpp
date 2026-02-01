#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span {
    private:
        unsigned int        _n;
        std::vector<int>    _storage;
        
        Span();

    public:
        Span(unsigned int n);
        Span(const Span &src);
        Span &operator=(const Span &rhs);
        ~Span();

        void addNumber(int number);
        long shortestSpan() const;
        long longestSpan() const;

        template <typename InputIterator>
        void addRange(InputIterator begin, InputIterator end) {
            if (std::distance(begin, end) + _storage.size() > _n)
                throw SpanFullException();
            _storage.insert(_storage.end(), begin, end);
        }

        class SpanFullException : public std::exception {
            virtual const char* what() const throw() { return "Span is already full"; }
        };

        class NoSpanException : public std::exception {
            virtual const char* what() const throw() { return "Not enough elements to find a span"; }
        };
};

#endif