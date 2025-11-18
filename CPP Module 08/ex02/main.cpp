#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
    // Test from subject
    std::cout << "=== Test with MutantStack ===" << std::endl;
    {
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << mstack.top() << std::endl;
        
        mstack.pop();
        
        std::cout << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        
        std::stack<int> s(mstack);
    }

    // Same test with std::list to compare outputs
    std::cout << "\n=== Test with std::list (should match) ===" << std::endl;
    {
        std::list<int> mstack;
        
        mstack.push_back(5);
        mstack.push_back(17);
        
        std::cout << mstack.back() << std::endl;
        
        mstack.pop_back();
        
        std::cout << mstack.size() << std::endl;
        
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    // Additional tests
    std::cout << "\n=== Test: Reverse iteration ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        
        std::cout << "Forward: ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Reverse: ";
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << std::endl;
    }

    // Test with strings
    std::cout << "\n=== Test: MutantStack with strings ===" << std::endl;
    {
        MutantStack<std::string> mstack;
        mstack.push("Hello");
        mstack.push("World");
        mstack.push("42");
        
        for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }

    // Test copy constructor
    std::cout << "\n=== Test: Copy constructor ===" << std::endl;
    {
        MutantStack<int> mstack1;
        mstack1.push(10);
        mstack1.push(20);
        mstack1.push(30);
        
        MutantStack<int> mstack2(mstack1);
        
        std::cout << "Original: ";
        for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Copy: ";
        for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}