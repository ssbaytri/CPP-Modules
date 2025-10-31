#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        std::cerr << "Examples:" << std::endl;
        std::cerr << "  ./convert 0" << std::endl;
        std::cerr << "  ./convert nan" << std::endl;
        std::cerr << "  ./convert 42.0f" << std::endl;
        std::cerr << "  ./convert a" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    return 0;
}