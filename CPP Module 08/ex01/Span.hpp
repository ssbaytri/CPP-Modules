#pragma once
#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
    	int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				if (_numbers.size() >= _maxSize)
					throw SpanFullException();
				_numbers.push_back(*begin);
				++begin;
			}
		}

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Span is full, cannot add more numbers";
				}
			};

			class NoSpanException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough numbers to calculate span";
				}
			};
};