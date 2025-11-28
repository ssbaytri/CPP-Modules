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

		// helper insertion sort used for small sizes
		template <typename Container>
		static void insertionSort(Container& container)
		{
			for (size_t i = 1; i < container.size(); ++i) {
				int key = container[i];
				size_t j = i;
				while (j > 0 && container[j - 1] > key) {
					container[j] = container[j - 1];
					--j;
				}
				container[j] = key;
			}
		}

		double getElapsedTime(struct timeval start, struct timeval end);
		void validateAndParse(char** av);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void process(char **av);
};

		// -------------------- Template implementations --------------------

		template <typename Container>
		std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
			std::vector<size_t> indices;
			if (n == 0) return indices;

			// Generate Jacobsthal numbers up to n
			std::vector<size_t> jacob;
			jacob.push_back(0);
			jacob.push_back(1);
			while (true) {
				size_t s = jacob.size();
				size_t next = jacob[s - 1] + 2 * jacob[s - 2];
				if (next > static_cast<size_t>(-1) || next > n) break;
				jacob.push_back(next);
			}

			std::vector<char> used(n, 0);
			// Use jacob indices first (if within range), then fill remaining
			for (size_t k = 1; k < jacob.size(); ++k) {
				size_t idx = jacob[k];
				if (idx < n && !used[idx]) {
					indices.push_back(idx);
					used[idx] = 1;
				}
			}

			for (size_t i = 0; i < n; ++i) {
				if (!used[i]) indices.push_back(i);
			}

			return indices;
		}

		template <typename Container>
		size_t PmergeMe::binarySearchInsert(const Container& container, int value, size_t end) {
			size_t left = 0;
			size_t right = end;
			while (left < right) {
				size_t mid = left + (right - left) / 2;
				if (container[mid] < value)
					left = mid + 1;
				else
					right = mid;
			}
			return left;
		}

		template <typename Container>
		void PmergeMe::fordJohnsonSort(Container& container) {
			size_t n = container.size();
			if (n <= 1) return;
			if (n <= 20) {
				insertionSort(container);
				return;
			}

			// Pair elements into (larger, smaller)
			std::vector<std::pair<int,int> > pairs;
			bool hasOdd = (n % 2 == 1);
			int odd = 0;
			if (hasOdd) odd = container[n - 1];

			for (size_t i = 0; i + 1 < n; i += 2) {
				int a = container[i];
				int b = container[i + 1];
				if (a >= b) pairs.push_back(std::make_pair(a, b));
				else pairs.push_back(std::make_pair(b, a));
			}

			// Sort pairs by larger element (ascending). std::pair::operator< compares
			// first element then second, so default std::sort works for our purpose.
			std::sort(pairs.begin(), pairs.end());

			// Build main chain: start with the smaller of the first pair, then all largers
			Container mainChain;
			if (!pairs.empty()) {
				mainChain.push_back(pairs[0].second);
			}
			for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].first);

			// pend: the smaller elements of pairs except the first
			std::vector<int> pend;
			for (size_t i = 1; i < pairs.size(); ++i) pend.push_back(pairs[i].second);

			// Insert pend elements using Jacobsthal order (optimized insertion order)
			std::vector<size_t> order = generateJacobsthalIndices<Container>(pend.size());
			for (size_t k = 0; k < order.size(); ++k) {
				size_t idx = order[k];
				if (idx >= pend.size()) continue;
				size_t pos = binarySearchInsert(mainChain, pend[idx], mainChain.size());
				mainChain.insert(mainChain.begin() + pos, pend[idx]);
			}

			// Insert odd element if present
			if (hasOdd) {
				size_t pos = binarySearchInsert(mainChain, odd, mainChain.size());
				mainChain.insert(mainChain.begin() + pos, odd);
			}

			container = mainChain;
		}

