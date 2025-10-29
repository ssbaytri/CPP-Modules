#include "ScalarConverter.hpp"

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

	if (str.empty() || str.back() != 'f')
		return false;

	std::string core = str.substr(0, str.length() - 1);

	if (core.empty())
		return false;

	size_t i = 0;
	bool hadDot = false;
	bool hadDigit = false;
}
