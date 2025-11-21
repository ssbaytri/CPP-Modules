#pragma once

#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;

		bool isOperator(const std::string& token);
    	bool isNumber(const std::string& token);
    	int performOperation(int a, int b, char op);

	public:
		RPN();
		RPN(const RPN& other);
    	RPN& operator=(const RPN& other);
    	~RPN();

		int evaluate(const std::string& expression);
};
