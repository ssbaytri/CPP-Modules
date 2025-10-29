#pragma once

# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <cstdlib>   // for strtod, strtof
# include <cmath>     // for isnan, isinf
# include <cctype>    // for isprint

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

public:
    // === Main entry point ===
    static void convert(const std::string &literal);

private:
    // === Helper methods ===
    
    // 1️⃣ Detect literal type
    static bool isCharLiteral(const std::string &str);
    static bool isIntLiteral(const std::string &str);
    static bool isFloatLiteral(const std::string &str);
    static bool isDoubleLiteral(const std::string &str);

    // 2️⃣ Print conversions
    static void printFromChar(char c);
    static void printFromInt(int i);
    static void printFromFloat(float f);
    static void printFromDouble(double d);
};

