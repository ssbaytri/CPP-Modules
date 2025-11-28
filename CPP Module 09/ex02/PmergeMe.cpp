#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    _vectorData = other._vectorData;
    _dequeData = other._dequeData;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vectorData = other._vectorData;
        _dequeData = other._dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

template <typename Container>
std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
    std::vector<size_t> indices;
    if (n == 0) return indices;
    
    // Generate Jacobsthal numbers
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    
    while (jacob.back() < n) {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    
    // Build insertion order
    size_t pos = 1;
    for (size_t i = 2; i < jacob.size(); i++) {
        size_t curr = jacob[i];
        if (curr >= n) curr = n - 1;
        
        for (size_t j = curr; j > pos && j < n; j--) {
            indices.push_back(j);
        }
        pos = jacob[i];
    }
    
    for (size_t i = pos + 1; i < n; i++) {
        indices.push_back(i);
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

// Simple insertion sort for small arrays (fallback)
template <typename Container>
void insertionSort(Container& container) {
    for (size_t i = 1; i < container.size(); i++) {
        int key = container[i];
        size_t j = i;
        while (j > 0 && container[j - 1] > key) {
            container[j] = container[j - 1];
            j--;
        }
        container[j] = key;
    }
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container& container) {
    size_t n = container.size();
    
    if (n <= 1)
        return;
    
    // For very small sizes, use simple insertion sort to avoid complexity
    if (n <= 20) {
        insertionSort(container);
        return;
    }
    
    // Pair elements
    std::vector<std::pair<int, int> > pairs; // (larger, smaller)
    bool hasOdd = (n % 2 == 1);
    int oddElement = hasOdd ? container[n - 1] : 0;
    
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (container[i] > container[i + 1]) {
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        } else {
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
        }
    }
    
    // Extract larger elements
    Container larger;
    for (size_t i = 0; i < pairs.size(); i++) {
        larger.push_back(pairs[i].first);
    }
    
    // Recursively sort larger elements
    fordJohnsonSort(larger);
    
    // Rebuild pairs in sorted order
    // This is the tricky part: we need to maintain pair relationships
    // Solution: sort pairs based on how their larger elements appear in sorted 'larger'
    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    
    for (size_t i = 0; i < larger.size(); i++) {
        // Find first unused pair with this larger value
        bool found = false;
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && pairs[j].first == larger[i]) {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            // This should never happen if algorithm is correct
            std::cerr << "Error: pair matching failed" << std::endl;
        }
    }
    
    // Build main chain: b1 + all sorted larger
    Container mainChain;
    if (!sortedPairs.empty()) {
        mainChain.push_back(sortedPairs[0].second);
    }
    for (size_t i = 0; i < sortedPairs.size(); i++) {
        mainChain.push_back(sortedPairs[i].first);
    }
    
    // Build pend
    std::vector<int> pend;
    for (size_t i = 1; i < sortedPairs.size(); i++) {
        pend.push_back(sortedPairs[i].second);
    }
    
    // Insert pend using Jacobsthal order
    std::vector<size_t> insertOrder = generateJacobsthalIndices<Container>(pend.size());
    for (size_t i = 0; i < insertOrder.size(); i++) {
        size_t idx = insertOrder[i];
        if (idx < pend.size()) {
            size_t pos = binarySearchInsert(mainChain, pend[idx], mainChain.size());
            mainChain.insert(mainChain.begin() + pos, pend[idx]);
        }
    }
    
    // Insert odd element
    if (hasOdd) {
        size_t pos = binarySearchInsert(mainChain, oddElement, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, oddElement);
    }
    
    container = mainChain;
}

double PmergeMe::getElapsedTime(struct timeval start, struct timeval end) {
    double startTime = start.tv_sec * 1000000.0 + start.tv_usec;
    double endTime = end.tv_sec * 1000000.0 + end.tv_usec;
    return endTime - startTime;
}

void PmergeMe::validateAndParse(char** av) {
    for (int i = 0; av[i]; i++) {
        std::string str(av[i]);
        for (size_t j = 0; j < str.length(); j++) {
            if (!isdigit(str[j])) {
                throw std::invalid_argument("Error");
            }
        }
        
        char* end;
        long num = strtol(av[i], &end, 10);
        
        if (*end != '\0' || num < 0 || num > 2147483647) {
            throw std::invalid_argument("Error");
        }
        
        _vectorData.push_back(static_cast<int>(num));
        _dequeData.push_back(static_cast<int>(num));
    }
    
    if (_vectorData.empty()) {
        throw std::invalid_argument("Error");
    }
}

void PmergeMe::process(char **av)
{
	validateAndParse(av);
	
	std::cout << "Before: ";
	for (size_t i = 0; i < _vectorData.size(); i++)
		std::cout << _vectorData[i] << " ";
	std::cout << std::endl;

	struct timeval start, end;
	gettimeofday(&start, NULL);
	fordJohnsonSort(_vectorData);
	gettimeofday(&end, NULL);
	double vectorTime = getElapsedTime(start, end);

	std::cout << "After: ";
	for (size_t i = 0; i < _vectorData.size(); i++)
		std::cout << _vectorData[i] << " ";
	std::cout << std::endl;

	gettimeofday(&start, NULL);
    fordJohnsonSort(_dequeData);
    gettimeofday(&end, NULL);
    double dequeTime = getElapsedTime(start, end);

	std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vectorData.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
}
