#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <limits>

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
}