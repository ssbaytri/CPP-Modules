#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    _stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token)
{
	if (token.length() != 1)
		return false;
	return (token[0] >= '0' && token[0] <= '9');
}

int RPN::performOperation(int a, int b, char op)
{
	switch(op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by zero");
			return a / b;
		default:
			throw std::runtime_error("Error: invalid operator");
	}
}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (isNumber(token)) {
            int num = token[0] - '0';
            _stack.push(num);
        }
        else if (isOperator(token)) {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");
            
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            
            int result = performOperation(a, b, token[0]);
            _stack.push(result);
        }
        else {
            throw std::runtime_error("Error: invalid token");
        }
    }
    
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    
    return _stack.top();
}
