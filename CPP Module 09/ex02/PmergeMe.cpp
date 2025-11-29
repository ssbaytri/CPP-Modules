#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    _vectorData = other._vectorData;
    _dequeData = other._dequeData;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

double PmergeMe::getElapsedTime(struct timeval start, struct timeval end) {
    double startTime = start.tv_sec * 1000000.0 + start.tv_usec;
    double endTime = end.tv_sec * 1000000.0 + end.tv_usec;
    return endTime - startTime;
}

void PmergeMe::validateAndParse(char** av) {
    for (int i = 0; av[i]; i++) {
        std::string str(av[i]);
        if (str.empty()) {
            throw std::invalid_argument("Error");
        }
        
        for (size_t j = 0; j < str.length(); j++) {
            if (!isdigit(str[j])) {
                throw std::invalid_argument("Error");
            }
        }
        
        char* end;
        long num = strtol(av[i], &end, 10);
        
        if (*end != '\0' || num < 0 || num > 2147483647) {
            throw std::invalid_argument("Error");
        }
        
        _vectorData.push_back(static_cast<int>(num));
        _dequeData.push_back(static_cast<int>(num));
    }
    
    if (_vectorData.empty()) {
        throw std::invalid_argument("Error");
    }
}

void PmergeMe::process(char** av) {
    validateAndParse(av);
    
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorData.size(); i++) {
        std::cout << _vectorData[i] << " ";
    }
    std::cout << std::endl;
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    fordJohnsonSort(_vectorData);
    gettimeofday(&end, NULL);
    double vectorTime = getElapsedTime(start, end);
    
    std::cout << "After:  ";
    for (size_t i = 0; i < _vectorData.size(); i++) {
        std::cout << _vectorData[i] << " ";
    }
    std::cout << std::endl;
    
    gettimeofday(&start, NULL);
    fordJohnsonSort(_dequeData);
    gettimeofday(&end, NULL);
    double dequeTime = getElapsedTime(start, end);
    
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}