#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Test 1: Valid Forms ===" << std::endl;
    try {
        Form document("Secret Document", 20, 10);
        Bureaucrat ceo("CEO", 1);
        Bureaucrat secretary("Secretary", 50);
        
        std::cout << document << std::endl;
        
        secretary.signForm(document);
        std::cout << document << std::endl;
        
        ceo.signForm(document);
        std::cout << document << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Test 2: Invalid Form ===" << std::endl;
    try {
        Form anotherDoc("fail form", 200, 10);  // Will throw here
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
