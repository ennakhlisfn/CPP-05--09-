#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Load the data.csv into our map
bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // Skip the header (date,exchange_rate)
    while (std::getline(file, line)) {
        size_t del = line.find(',');
        if (del != std::string::npos) {
            std::string date = line.substr(0, del);
            float rate = std::atof(line.substr(del + 1).c_str());
            _data[date] = rate;
        }
    }
    file.close();
    return true;
}

// Check if the date is logically valid
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31) return false;
    if (year < 2008) return false; // BTC didn't exist before

    // Handle months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

    // Handle February and leap years
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28)) return false;
    }

    return true;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header (date | value)
    while (std::getline(file, line)) {
        size_t del = line.find('|');
        if (del == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, del);
        trim(date);
        std::string valueStr = line.substr(del + 1);
        trim(valueStr);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        char* endptr;
        float value = std::strtof(valueStr.c_str(), &endptr);
        if (*endptr != '\0' || valueStr.empty()) {
             std::cerr << "Error: not a valid number." << std::endl;
        } else if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
        } else if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
        } else {
            // Find the rate (lower_bound logic)
            std::map<std::string, float>::iterator it = _data.lower_bound(date);
            if (it != _data.begin() && (it == _data.end() || it->first != date)) {
                --it;
            }
            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        }
    }
}

void BitcoinExchange::trim(std::string& str) const {
    str.erase(0, str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
}