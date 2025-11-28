#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <iomanip>


struct PairInfo {
    int larger;
    int smaller;
    size_t index;
};

class PmergeMe
{
	private:
		std::vector<int> _vectorData;
		std::deque<int> _dequeData;

		template <typename Container>
		std::vector<size_t> generateJacobsthalIndices(size_t n);

		template <typename Container>
		size_t binarySearchInsert(const Container& container, int value, size_t end);

		template <typename Container>
		void fordJohnsonSort(Container& container);

		double getElapsedTime(struct timeval start, struct timeval end);
		void validateAndParse(char** av);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void process(char **av);
};
