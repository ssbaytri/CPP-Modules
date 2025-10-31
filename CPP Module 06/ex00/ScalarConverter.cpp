#include "ScalarConverter.hpp"
#include <limits>

bool ScalarConverter::isCharLiteral(const std::string& str)
{
	if (str.length() != 1)
		return false;
	char c = str[0];
	if (!std::isprint(c) || std::isdigit(c))
		return false;
	return true;
}

bool ScalarConverter::isIntLiteral(const std::string& str)
{
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str.length() == 1)
			return false;
		i++;
	}
	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return true;

	if (str.empty() || str[str.length() - 1] != 'f')
		return false;

	std::string core = str.substr(0, str.length() - 1);

	if (core.empty())
		return false;

	size_t i = 0;
	bool hasDot = false;
	bool hasDigit = false;
	if (core[i] == '+' || core[i] == '-')
	{
		i++;
		if (i >= core.length())
			return false;
	}

	while (i < core.length())
	{
		if (core[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(core[i]))
			hasDigit = true;
		else
			return false;
		i++;
	}
	return (hasDigit && hasDot);
}

bool ScalarConverter::isDoubleLiteral(const std::string& str)
{
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return true;

	if (str.empty())
		return false;

	size_t i = 0;
	bool hasDot = false;
	bool hasDigit = false;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (i >= str.length())
			return false;
	}

	while (i < str.length())
	{
		if (str[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(str[i]))
			hasDigit = true;
		else
			return false;
		i++;
	}
	return (hasDigit && hasDot);
}

void ScalarConverter::printFromChar(char c)
{
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
	          << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
	          << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printFromInt(int i)
{
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (i < 32 || i >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << i << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) 
              << static_cast<float>(i) << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(1) 
              << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printFromFloat(float f)
{
    // Print char
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else if (f < 32 || f >= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    
    // Print int
    if (std::isnan(f) || std::isinf(f))
        std::cout << "int: impossible" << std::endl;
    else if (f < std::numeric_limits<int>::min() || 
             f > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    
    // Print float
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) 
                  << f << "f" << std::endl;
    }
    
    // Print double
    if (std::isnan(f))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(f))
        std::cout << "double: " << (f > 0 ? "+inf" : "-inf") << std::endl;
    else
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) 
                  << static_cast<double>(f) << std::endl;
    }
}

void ScalarConverter::printFromDouble(double d)
{
    // Print char
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (d < 32 || d >= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    
    // Print int
    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else if (d < std::numeric_limits<int>::min() || 
             d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    
    // Print float
    if (std::isnan(d))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(d))
        std::cout << "float: " << (d > 0 ? "+inff" : "-inff") << std::endl;
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) 
                  << static_cast<float>(d) << "f" << std::endl;
    }
    
    // Print double
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) 
                  << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isCharLiteral(literal))
	{
		char c = literal[0];
		printFromChar(c);
		return ;
	}

	if (isIntLiteral(literal))
	{
		char *end;
		long value = std::strtol(literal.c_str(), &end, 10);
		if (value > std::numeric_limits<int>::max()
			|| value < std::numeric_limits<int>::min())
		{
			std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
		}
		int i = static_cast<int>(value);
		printFromInt(i);
		return ;	
	}

	if (isFloatLiteral(literal))
	{
		float f;
        
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff" || literal == "inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else
        {
            char *end;
            f = std::strtof(literal.c_str(), &end);
        }

		printFromFloat(f);
		return ;
	}

	if (isDoubleLiteral(literal))
    {
        double d;
        
        if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf" || literal == "inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else
        {
            char *end;
            d = std::strtod(literal.c_str(), &end);
        }
        
        printFromDouble(d);
        return;
    }

	std::cout << "Error: Invalid literal format" << std::endl;
}
