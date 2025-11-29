# C++ Module 09 - STL

This repository contains the implementation of C++ Module 09 exercises from the 42 curriculum, focusing on **STL containers** and **advanced algorithms**.

## 📋 Table of Contents

- [Overview](#-overview)
- [Learning Objectives](#-learning-objectives)
- [Exercises](#-exercises)
- [Compilation](#-compilation)
- [Key Concepts](#-key-concepts)
- [Usage Examples](#-usage-examples)

## 🎯 Overview

This module explores advanced uses of the Standard Template Library (STL), with a focus on:
- **STL Containers** (map, stack, vector, deque)
- **Container Comparison** and performance analysis
- **Algorithm Implementation** (Ford-Johnson merge-insert sort)
- **Data Parsing** and validation
- **Time Measurement** and benchmarking

## 🎓 Learning Objectives

By completing this module, you will understand:

- How to choose appropriate STL containers for specific tasks
- CSV and text file parsing techniques
- Reverse Polish Notation (RPN) evaluation
- Ford-Johnson merge-insert sort algorithm
- Performance comparison between different containers
- Time measurement in microseconds
- Container-specific constraints and trade-offs

## 📁 Exercises

### Exercise 00: Bitcoin Exchange
**Files:** `BitcoinExchange.hpp`, `BitcoinExchange.cpp`, `main.cpp`, `Makefile`

Bitcoin price calculator using historical exchange rate database:
- Reads CSV database of historical Bitcoin prices
- Processes input file with date-value pairs
- Calculates Bitcoin value on specific dates
- Uses closest lower date if exact date not in database
- Validates date format (YYYY-MM-DD) and value range (0-1000)
- Uses `std::map` for efficient date-price lookups

**Key Features:**
- CSV parsing and data storage
- Date comparison and lookup
- Binary search for closest lower date
- Input validation and error handling
- File I/O operations
- Map container for key-value storage

**Example:**
```bash
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-09 => 1 = 0.32
Error: not a positive number.
2012-01-11 => 1 = 7.1
Error: too large a number.
```

**Container Used:** `std::map<std::string, float>` - Efficient sorted key-value storage for date-price pairs.

### Exercise 01: Reverse Polish Notation
**Files:** `RPN.hpp`, `RPN.cpp`, `main.cpp`, `Makefile`

RPN calculator for evaluating postfix mathematical expressions:
- Evaluates expressions in Reverse Polish Notation
- Supports operations: `+`, `-`, `*`, `/`
- Handles single-digit operands (0-9)
- Stack-based evaluation algorithm
- Error handling for invalid expressions
- Uses `std::stack` for LIFO operations

**Key Features:**
- Stack-based expression evaluation
- Token parsing and validation
- Operator application
- Division by zero detection
- Expression validation (balanced operands/operators)

**Example:**
```bash
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42

$> ./RPN "7 7 * 7 -"
42

$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0

$> ./RPN "(1 + 1)"
Error
```

**Container Used:** `std::stack<int>` - Perfect for LIFO evaluation of RPN expressions.

**Algorithm Steps:**
1. Parse input string into tokens
2. For each token:
   - If number: push to stack
   - If operator: pop 2 operands, compute, push result
3. Final stack should contain exactly one value (the result)

### Exercise 02: PmergeMe
**Files:** `PmergeMe.hpp`, `PmergeMe.cpp`, `main.cpp`, `Makefile`

Ford-Johnson merge-insert sort with container performance comparison:
- Implements Ford-Johnson algorithm (merge-insert sort)
- Sorts positive integer sequences
- Uses Jacobsthal sequence for optimal insertion order
- Compares performance between `std::vector` and `std::deque`
- Handles at least 3000 integers
- Displays timing in microseconds
- Validates input (positive integers only)

**Key Features:**
- Ford-Johnson merge-insert sort implementation
- Jacobsthal sequence generation
- Binary insertion for sorted placement
- Dual-container sorting (vector and deque)
- Microsecond-precision timing
- Performance benchmarking
- Large dataset handling (3000+ elements)

**Example:**
```bash
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 13.00000 us
Time to process a range of 5 elements with std::deque : 14.00000 us

$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After:  79 141 321 526 [...]
Time to process a range of 3000 elements with std::vector : 1309.00000 us
Time to process a range of 3000 elements with std::deque : 2154.00000 us
```

**Containers Used:**
- `std::vector<int>` - Contiguous memory, faster access
- `std::deque<int>` - Non-contiguous, different performance characteristics

**Algorithm Overview:**
1. **Pair elements** into (larger, smaller) tuples
2. **Sort pairs** by their larger elements
3. **Build main chain** starting with first smaller + all larger elements
4. **Build pend** with remaining smaller elements
5. **Insert pend** using Jacobsthal sequence order with binary search
6. **Insert straggler** if odd number of elements

## 🔧 Compilation

All exercises follow the same compilation rules:

```bash
make
```

**Compiler flags used:**
- `-Wall -Wextra -Werror`
- `-std=c++98`

**Example compilation:**
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```

## 🔑 Key Concepts

### Container Selection Strategy

**Module 09 Rule:** Once a container is used, it cannot be used again in subsequent exercises.

| Exercise | Container | Why This Container? |
|----------|-----------|---------------------|
| **Ex00** | `std::map` | Sorted key-value storage, O(log n) lookup for dates |
| **Ex01** | `std::stack` | LIFO operations perfect for RPN evaluation |
| **Ex02** | `std::vector` + `std::deque` | Performance comparison, both support random access |

### Ford-Johnson Algorithm (Exercise 02)

The **Ford-Johnson algorithm** (also called **merge-insert sort**) minimizes the number of comparisons needed to sort a sequence.

**Key Components:**

1. **Pairing:** Group elements into pairs (larger, smaller)
2. **Sorting Pairs:** Sort pairs by their larger elements
3. **Main Chain:** Sorted sequence starting with smallest element
4. **Pend:** Remaining elements to be inserted
5. **Jacobsthal Sequence:** Optimal insertion order to minimize comparisons
6. **Binary Insertion:** Find correct position in O(log n) time

**Jacobsthal Sequence:**
```
J(0) = 0
J(1) = 1
J(n) = J(n-1) + 2*J(n-2)

Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85...
```

**Insertion Order Example:**
For 9 elements in pend, Jacobsthal groups create insertion order:
```
[1], [3, 2], [5, 4], [11, 10, 9, 8, 7, 6]
```
Elements are inserted in reverse within each group for optimal comparison count.

### Reverse Polish Notation (Exercise 01)

**RPN** (Reverse Polish Notation) is a mathematical notation where operators follow operands.

**Infix vs RPN:**
| Infix | RPN | Evaluation |
|-------|-----|------------|
| `3 + 4` | `3 4 +` | Push 3, push 4, add → 7 |
| `(3 + 4) * 5` | `3 4 + 5 *` | Add first, then multiply |
| `8 * 9 - 9` | `8 9 * 9 -` | Multiply, then subtract |

**Stack-Based Evaluation:**
```
Expression: 8 9 * 9 -

Step 1: Push 8        [8]
Step 2: Push 9        [8, 9]
Step 3: Multiply      [72]        (pop 9, pop 8, push 8*9)
Step 4: Push 9        [72, 9]
Step 5: Subtract      [63]        (pop 9, pop 72, push 72-9)

Result: 63
```

### Time Measurement

Using `gettimeofday()` for microsecond precision:

```cpp
struct timeval start, end;

gettimeofday(&start, NULL);
// ... operation to measure ...
gettimeofday(&end, NULL);

double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0 
               + (end.tv_usec - start.tv_usec);
```

## 💡 Usage Examples

### Exercise 00 - Bitcoin Exchange

**Database file (data.csv):**
```csv
date,exchange_rate
2009-01-02,0
2011-01-03,0.3
2011-01-09,0.32
2012-01-11,7.1
```

**Input file (input.txt):**
```
date | value
2011-01-03 | 3
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
```

**Execution:**
```bash
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
```

### Exercise 01 - RPN

```bash
# Simple addition
$> ./RPN "2 3 +"
5

# Complex expression
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42

# Invalid: brackets not allowed
$> ./RPN "(1 + 1)"
Error

# Invalid: not enough operands
$> ./RPN "1 +"
Error
```

### Exercise 02 - PmergeMe

```bash
# Small test
$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 13.00000 us
Time to process a range of 5 elements with std::deque : 14.00000 us

# Large test with random numbers (Linux)
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After:  79 141 321 526 [...]
Time to process a range of 3000 elements with std::vector : 1309.00000 us
Time to process a range of 3000 elements with std::deque : 2154.00000 us

# Large test (macOS)
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]

# Error cases
$> ./PmergeMe "-1" "2"
Error

$> ./PmergeMe
Error
```

## 📚 Technical Notes

### CSV Parsing (Exercise 00)

```cpp
// Read CSV line: "2011-01-03,0.3"
std::getline(file, line);
size_t pos = line.find(',');
std::string date = line.substr(0, pos);
std::string value = line.substr(pos + 1);

// Store in map
float rate = atof(value.c_str());
database[date] = rate;
```

### Date Lookup with Lower Bound

```cpp
// Find exact or closest lower date
std::map<std::string, float>::iterator it = database.find(date);
if (it != database.end()) {
    return it->second;  // Exact match
}

// Find closest lower date
it = database.lower_bound(date);
if (it == database.begin()) {
    return 0;  // No lower date exists
}
--it;  // Go to previous (lower) date
return it->second;
```

### Stack-Based RPN Evaluation

```cpp
std::stack<int> stack;
std::istringstream iss(expression);
std::string token;

while (iss >> token) {
    if (isNumber(token)) {
        stack.push(atoi(token.c_str()));
    } else if (isOperator(token)) {
        int b = stack.top(); stack.pop();
        int a = stack.top(); stack.pop();
        stack.push(calculate(a, b, token[0]));
    }
}

return stack.top();  // Final result
```

### Ford-Johnson Implementation

```cpp
// 1. Create pairs (larger, smaller)
for (size_t i = 0; i + 1 < n; i += 2) {
    if (container[i] > container[i + 1])
        pairs.push_back(make_pair(container[i], container[i + 1]));
    else
        pairs.push_back(make_pair(container[i + 1], container[i]));
}

// 2. Sort pairs by larger element
sort(pairs.begin(), pairs.end());

// 3. Build main chain
mainChain.push_back(pairs[0].second);  // First smaller (guaranteed min)
for (each pair)
    mainChain.push_back(pair.first);   // All larger elements

// 4. Build pend (remaining smaller)
for (i = 1 to pairs.size())
    pend.push_back(pairs[i].second);

// 5. Insert pend using Jacobsthal order
vector<size_t> order = generateJacobsthalIndices(pend.size());
for (each index in order)
    binaryInsert(mainChain, pend[index]);
```

### Jacobsthal Index Generation

```cpp
// Generate Jacobsthal numbers
vector<size_t> jacob = {0, 1};
while (jacob.back() < n) {
    jacob.push_back(jacob[size-1] + 2 * jacob[size-2]);
}

// Create insertion order with reverse groups
// For J = [0, 1, 3, 5, 11]:
// Insert: [1], [3,2], [5,4], then remaining
vector<size_t> indices;
for (size_t i = 2; i < jacob.size(); i++) {
    size_t curr = jacob[i];
    size_t prev = jacob[i-1];
    // Insert from curr-1 down to prev (reverse)
    for (size_t j = curr-1; j > prev; j--)
        indices.push_back(j);
}
```

### Binary Insertion

```cpp
// Find insertion position in sorted container
size_t binarySearchInsert(Container& cont, int value) {
    size_t left = 0;
    size_t right = cont.size();
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (cont[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left;
}

// Insert at found position
cont.insert(cont.begin() + pos, value);
```

## 🚀 Performance Analysis

### Container Comparison (Exercise 02)

**std::vector:**
- **Memory:** Contiguous allocation
- **Access:** O(1) random access
- **Insertion:** O(n) when inserting in middle
- **Cache:** Excellent cache locality
- **Result:** Usually faster for this algorithm

**std::deque:**
- **Memory:** Chunked allocation
- **Access:** O(1) random access (with overhead)
- **Insertion:** O(n) when inserting in middle
- **Cache:** Poorer cache locality than vector
- **Result:** Usually slightly slower

**Typical Results:**
```
Small (5 elements):    vector ~13us, deque ~14us
Medium (100 elements): vector ~70us, deque ~130us
Large (3000 elements): vector ~1300us, deque ~2150us
```

**Why vector is faster:**
- Better cache performance
- Less pointer dereferencing
- Contiguous memory layout benefits binary search

## ⚠️ Common Pitfalls

### Exercise 00 - Bitcoin Exchange
- **Date Format:** Must be exactly YYYY-MM-DD
- **Closest Lower:** Use previous date, not next date
- **Value Range:** Must be 0 to 1000
- **CSV Parsing:** Handle different line endings

### Exercise 01 - RPN
- **Operator Order:** When popping: b = top, a = top, then a op b
- **Stack Size:** Check for at least 2 elements before operation
- **Final Validation:** Stack must have exactly 1 element
- **Invalid Tokens:** No brackets, only single digits

### Exercise 02 - PmergeMe
- **Odd Numbers:** Handle straggler element separately
- **Jacobsthal Index:** Must cover all elements (add remaining)
- **Container Choice:** Can't reuse containers from previous exercises
- **Time Units:** Display in microseconds, not milliseconds
- **Element Loss:** Ensure all elements are sorted (no losses!)

## 🎯 Algorithm Complexity

### Ford-Johnson (Exercise 02)

**Time Complexity:**
- Pairing: O(n)
- Sorting pairs: O(n²) with bubble sort (or O(n log n) if using better sort)
- Building chains: O(n)
- Jacobsthal insertion: O(n log n) - n insertions, each O(log n) binary search
- **Overall:** O(n log n) to O(n²) depending on pair sorting method

**Space Complexity:**
- Pairs storage: O(n)
- Main chain: O(n)
- Pend: O(n)
- **Overall:** O(n)

**Comparison Count:**
- Ford-Johnson is designed to minimize comparisons
- Theoretical minimum for sorting n elements
- Jacobsthal order achieves near-optimal comparison count

### Container Performance

| Operation | vector | deque | Reason |
|-----------|--------|-------|--------|
| Random Access | O(1) | O(1) | Both support indexing |
| Insert Middle | O(n) | O(n) | Must shift elements |
| Cache Performance | Excellent | Good | Vector has better locality |
| Memory Overhead | Low | Higher | Deque uses multiple chunks |

## 📖 Module Progression

### Container Usage Across Exercises

```
Ex00: std::map        → Key-value lookup, sorted dates
Ex01: std::stack      → LIFO for RPN evaluation  
Ex02: std::vector     → Performance baseline
      + std::deque    → Performance comparison
```

**Rule Enforcement:** Once a container type is used in one exercise, it cannot be reused in subsequent exercises. This forces understanding of different container characteristics.

## 🔍 Testing Strategies

### Exercise 00 Testing
```bash
# Valid inputs
./btc input.txt

# Edge cases
echo "2011-01-03 | 0" | ./btc      # Minimum value
echo "2011-01-03 | 1000" | ./btc   # Maximum value
echo "2011-01-03 | 1001" | ./btc   # Too large
echo "2011-01-03 | -1" | ./btc     # Negative
echo "2001-42-42 | 1" | ./btc      # Invalid date
```

### Exercise 01 Testing
```bash
# Basic operations
./RPN "2 3 +"                      # Addition
./RPN "10 5 -"                     # Subtraction
./RPN "4 5 *"                      # Multiplication
./RPN "20 4 /"                     # Division

# Complex
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" # Should be 42

# Errors
./RPN "1"                          # No operation
./RPN "1 2"                        # Too many operands
./RPN "+"                          # No operands
./RPN "(1 + 1)"                    # Invalid syntax
```

### Exercise 02 Testing
```bash
# Small tests
./PmergeMe 3 5 9 7 4
./PmergeMe 1 2 3 4 5 6 7 8 9 10

# Medium tests
./PmergeMe `shuf -i 1-1000 -n 100 | tr "\n" " "`

# Large tests (3000 elements)
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

# Edge cases
./PmergeMe 42                      # Single element
./PmergeMe 5 2                     # Two elements
./PmergeMe 1 1 1 1 1               # Duplicates

# Errors
./PmergeMe                         # No input
./PmergeMe -1 2 3                  # Negative
./PmergeMe 1 abc 3                 # Non-numeric
```

## 💻 Debugging Tips

### Tracing Ford-Johnson
```cpp
// Add debug output to trace algorithm
void printPairs(vector<pair<int,int>>& pairs) {
    cout << "Pairs: ";
    for (size_t i = 0; i < pairs.size(); i++)
        cout << "(" << pairs[i].first << "," << pairs[i].second << ") ";
    cout << endl;
}

void printContainer(vector<int>& cont, string label) {
    cout << label << ": ";
    for (size_t i = 0; i < cont.size(); i++)
        cout << cont[i] << " ";
    cout << endl;
}
```

### Verifying Sorting
```bash
# Verify output is sorted
./PmergeMe 9 2 8 1 7 3 | grep "After:" | tr ' ' '\n' | tail -n +2 | sort -n -c
# If sorted correctly, no output. Otherwise shows error.
```

### Counting Elements
```bash
# Ensure no elements are lost
./PmergeMe 1 2 3 4 5 | tee /dev/tty | awk '/Before:/{b=NF-1}/After:/{a=NF-1}END{print "Before:",b,"After:",a}'
```

---

**Congratulations!** 🎉 You've completed C++ Module 09, mastering STL container selection, algorithm implementation, and performance analysis. This module builds upon previous knowledge and prepares you for advanced C++ development with deep understanding of container characteristics and algorithmic complexity.

*This module emphasizes practical container usage, algorithm implementation, and performance benchmarking - essential skills for writing efficient, production-quality C++ code.*