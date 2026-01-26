#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    double value = 0.0;
    bool impossible = false;

    if (literal.length() == 1 && !isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    }
    else {
        char* end;
        value = std::strtod(literal.c_str(), &end);
        
        if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {
             impossible = true; 
        }
    }

    std::cout << "char: ";
    if (impossible || std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
        std::cout << "impossible";
    } else if (!isprint(static_cast<char>(value))) {
        std::cout << "Non displayable";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'";
    }
    std::cout << std::endl;

    std::cout << "int: ";
    if (impossible || std::isnan(value) || std::isinf(value) || 
        value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        std::cout << "impossible";
    } else {
        std::cout << static_cast<int>(value);
    }
    std::cout << std::endl;

    std::cout << "float: ";

    if (impossible) {
         std::cout << "nanf";
    } else {
         std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
    }
    std::cout << std::endl;

    std::cout << "double: ";
    if (impossible) {
        std::cout << "nan";
    } else {
        std::cout << std::fixed << std::setprecision(1) << value;
    }
    std::cout << std::endl;
}