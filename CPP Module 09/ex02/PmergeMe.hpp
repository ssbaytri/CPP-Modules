#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>
#include <string>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <iomanip>

class PmergeMe {
private:
    std::vector<int> _vectorData;
    std::deque<int> _dequeData;
    
    template <typename Container>
    std::vector<size_t> generateJacobsthalIndices(size_t n);
    
    template <typename Container>
    size_t binarySearchInsert(const Container& container, int value);
    
    template <typename Container>
    void fordJohnsonSort(Container& container);
    
    double getElapsedTime(struct timeval start, struct timeval end);
    void validateAndParse(char** av);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void process(char** av);
};


template <typename Container>
std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
    if (n == 0) return std::vector<size_t>();
    
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    
    while (jacob.back() < n) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    
    std::vector<size_t> indices;
    std::vector<bool> used(n, false);
    
    for (size_t i = 2; i < jacob.size(); i++) {
        size_t curr = jacob[i];
        size_t prev = jacob[i - 1];
        
        if (curr > n) curr = n;
        
        for (size_t j = curr; j > prev && j > 0; j--) {
            size_t idx = j - 1;
            if (idx < n && !used[idx]) {
                indices.push_back(idx);
                used[idx] = true;
            }
        }
    }
    
    for (size_t i = 0; i < n; i++) {
        if (!used[i]) {
            indices.push_back(i);
        }
    }
    
    return indices;
}

template <typename Container>
size_t PmergeMe::binarySearchInsert(const Container& container, int value) {
    size_t left = 0;
    size_t right = container.size();
    
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
    
    if (n <= 1)
        return;
    
    if (n == 2) {
        if (container[0] > container[1])
            std::swap(container[0], container[1]);
        return;
    }
    
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = (n % 2 == 1);
    int oddElement = 0;
    
    if (hasOdd) {
        oddElement = container[n - 1];
    }
    
    for (size_t i = 0; i + 1 < n; i += 2) {
        int a = container[i];
        int b = container[i + 1];
        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
        } else {
            pairs.push_back(std::make_pair(b, a));
        }
    }
    
    for (size_t i = 0; i < pairs.size(); i++) {
        for (size_t j = i + 1; j < pairs.size(); j++) {
            if (pairs[i].first > pairs[j].first) {
                std::swap(pairs[i], pairs[j]);
            }
        }
    }
    
    Container mainChain;
    if (!pairs.empty()) {
        mainChain.push_back(pairs[0].second);
    }
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
    }
    
    std::vector<int> pend;
    for (size_t i = 1; i < pairs.size(); i++) {
        pend.push_back(pairs[i].second);
    }
    
    std::vector<size_t> order = generateJacobsthalIndices<Container>(pend.size());
    
    for (size_t k = 0; k < order.size(); k++) {
        size_t idx = order[k];
        if (idx < pend.size()) {
            size_t pos = binarySearchInsert(mainChain, pend[idx]);
            mainChain.insert(mainChain.begin() + pos, pend[idx]);
        }
    }
    
    if (hasOdd) {
        size_t pos = binarySearchInsert(mainChain, oddElement);
        mainChain.insert(mainChain.begin() + pos, oddElement);
    }
    
    container = mainChain;
}

#endif