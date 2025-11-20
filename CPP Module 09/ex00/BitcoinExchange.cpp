#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    _database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::parseDatabaseLine(const std::string& line)
{
	size_t pos = line.find(',');
	if (pos == std::string::npos) return ;

	std::string date = line.substr(0, pos);
	std::string valueStr = line.substr(pos + 1);

	float rate = std::atof(valueStr.c_str());
	_database[date] = rate;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
		parseDatabaseLine(line);
	file.close();
}


void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);
	while (getline(file, line))
		parseInputLine(line);
	file.close();		
}

void BitcoinExchange::parseInputLine(const std::string& line)
{
	size_t pos = line.find(" | ");
	if (pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string date = line.substr(0, pos);
	std::string valueStr = line.substr(pos + 3);

	if (!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
        return;
	}

	float value;
	if (!isValidValue(valueStr, value))
		return ;

	float rate = findExchangeRate(date);
	float res = value * rate;

	std::cout << date << " => " << value << " = " << res << std::endl;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	for (size_t i = 0; i < yearStr.length(); i++)
		if (!std::isdigit(yearStr[i])) return false;
	for (size_t i = 0; i < monthStr.length(); i++)
		if (!std::isdigit(monthStr[i])) return false;
	for (size_t i = 0; i < dayStr.length(); i++)
		if (!std::isdigit(dayStr[i])) return false;

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	(void)year;
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value)
{
	char *end;
	value = std::strtof(valueStr.c_str(), &end);
	
	if (*end != '\0' && *end != '\n') {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

	if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

	if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
	return true;
}

float BitcoinExchange::findExchangeRate(const std::string& date)
{
	std::map<std::string, float>::iterator it = _database.find(date);
	if (it != _database.end())
		return it->second;

	it = _database.lower_bound(date);

	if (it == _database.begin())
		return 0;

	--it;
	return it->second;
}
