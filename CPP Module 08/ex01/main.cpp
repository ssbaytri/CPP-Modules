#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    // Test from subject
    std::cout << "=== Test from subject ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    // Test exception when full
    std::cout << "\n=== Test: Span full exception ===" << std::endl;
    {
        try {
            Span sp(3);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4); // Should throw
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }

    // Test exception with not enough numbers
    std::cout << "\n=== Test: Not enough numbers ===" << std::endl;
    {
        try {
            Span sp(5);
            sp.addNumber(1);
            std::cout << sp.shortestSpan() << std::endl; // Should throw
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }

    // Test with 10,000 numbers using addRange
    std::cout << "\n=== Test: 10,000 numbers ===" << std::endl;
    {
        Span sp(10000);
        std::vector<int> numbers;
        
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(std::rand());
        }
        
        sp.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Added 10,000 numbers" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Test with negative numbers
    std::cout << "\n=== Test: Negative numbers ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(10);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    return 0;
}