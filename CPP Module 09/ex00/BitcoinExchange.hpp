#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;

		bool isValidDate(const std::string& date);
		bool isValidValue(const std::string& valueStr, float& value);
		float findExchangeRate(const std::string& date);
		void parseDatabaseLine(const std::string& line);
		void parseInputLine(const std::string& line);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadDatabase(const std::string& filename);
		void processInput(const std::string& filename);
};
