# C++ Module 08 - Templated Containers, Iterators, Algorithms

This repository contains the implementation of C++ Module 08 exercises from the 42 curriculum, focusing on **STL containers**, **iterators**, and **algorithms**.

## 📋 Table of Contents

- [Overview](#-overview)
- [Learning Objectives](#-learning-objectives)
- [Exercises](#-exercises)
- [Compilation](#-compilation)
- [Key Concepts](#-key-concepts)
- [Usage Examples](#-usage-examples)

## 🎯 Overview

This module introduces the Standard Template Library (STL) in C++, with a specific focus on:
- **STL Containers** (vector, list, stack, deque, etc.)
- **Iterators** for container traversal
- **STL Algorithms** (find, sort, min_element, max_element, etc.)
- **Container adapters** and customization
- **Generic programming** with STL

## 🎓 Learning Objectives

By completing this module, you will understand:

- How to use STL containers effectively
- Iterator concepts and usage patterns
- Standard algorithms for common operations
- Creating custom iterable containers
- Container adapters and their limitations
- Generic algorithm implementation
- Exception handling in container contexts
- Range-based operations with iterators

## 📁 Exercises

### Exercise 00: Easy find
**Files:** `easyfind.hpp`, `main.cpp`, `Makefile`

Implementation of a generic search function template:
- `easyfind`: Finds the first occurrence of an integer in a container
- Works with any STL container of integers
- Uses `std::find` algorithm internally
- Returns an iterator to the found element
- Throws exception if value not found
- No support needed for associative containers

**Key Features:**
- Function template with container type parameter
- STL algorithm usage (`std::find`)
- Iterator manipulation
- Exception-based error handling
- Works with vector, list, deque, etc.

**Example:**
```cpp
std::vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3);

try {
    std::vector<int>::iterator it = easyfind(vec, 2);
    std::cout << "Found: " << *it << std::endl;
} catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

### Exercise 01: Span
**Files:** `Span.hpp`, `Span.cpp`, `main.cpp`, `Makefile`

Generic span calculator class for integer sequences:
- Stores a maximum of N integers
- `addNumber()`: Adds a single number with overflow check
- `shortestSpan()`: Finds minimum distance between any two numbers
- `longestSpan()`: Finds maximum distance (max - min)
- `addRange()`: Adds multiple numbers using iterator range
- Exception handling for edge cases
- Efficient implementation using STL algorithms

**Key Features:**
- Container size management
- Iterator range insertion
- STL algorithm usage (sort, min_element, max_element)
- Exception-based validation
- Optimized span calculation
- Support for large datasets (10,000+ elements)

**Example:**
```cpp
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl;  // Output: 2
std::cout << sp.longestSpan() << std::endl;   // Output: 14

// Add range of numbers
std::vector<int> numbers;
// ... fill numbers ...
sp.addRange(numbers.begin(), numbers.end());
```

### Exercise 02: Mutated abomination
**Files:** `MutantStack.hpp`, `main.cpp`, `Makefile`

Iterable stack implementation (container adapter enhancement):
- Inherits from `std::stack`
- Adds iterator support (begin, end, rbegin, rend)
- Maintains all standard stack operations
- Exposes underlying container's iterators
- Compatible with standard stack interface
- Demonstrates container adapter customization

**Key Features:**
- Container adapter inheritance
- Iterator type definitions
- Access to protected container member `c`
- Full iterator support (forward and reverse)
- Const-correct iterator implementations
- Seamless integration with STL algorithms
- Orthodox Canonical Form implementation

**Example:**
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
mstack.push(3);
mstack.push(737);

MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();

while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
}

// Can be copied to regular stack
std::stack<int> s(mstack);
```

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

### STL Containers
- **Sequence Containers:** vector, list, deque
- **Container Adapters:** stack, queue, priority_queue
- **Associative Containers:** set, map, multiset, multimap
- **Container Properties:** size, capacity, element access

### Iterators
- **Iterator Categories:** input, output, forward, bidirectional, random access
- **Iterator Operations:** increment, decrement, dereference, comparison
- **Iterator Ranges:** [begin, end) half-open range convention
- **Const Iterators:** Read-only access to container elements

### STL Algorithms
```cpp
std::find()          // Search for value
std::sort()          // Sort elements
std::min_element()   // Find minimum
std::max_element()   // Find maximum
std::copy()          // Copy elements
std::distance()      // Calculate distance between iterators
```

### Container Adapter Pattern
- **Adapter:** Provides different interface to existing container
- **Underlying Container:** Hidden container doing actual storage
- **std::stack:** Uses deque by default, provides LIFO interface
- **Protected Member `c`:** Access point for underlying container

## 💡 Usage Examples

### Exercise 00 - Easy find
```cpp
#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    // Test with vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    
    try {
        easyfind(vec, 2);
        std::cout << "Found 2 in vector" << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    // Test with list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    
    try {
        easyfind(lst, 20);
        std::cout << "Found 20 in list" << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
```

### Exercise 01 - Span
```cpp
#include "Span.hpp"
#include <vector>

int main() {
    // Basic usage
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    // Using iterator range (10,000 numbers)
    Span bigSpan(10000);
    std::vector<int> numbers;
    
    for (int i = 0; i < 10000; i++) {
        numbers.push_back(rand());
    }
    
    bigSpan.addRange(numbers.begin(), numbers.end());
    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
    
    return 0;
}
```

### Exercise 02 - MutantStack
```cpp
#include "MutantStack.hpp"
#include <list>

int main() {
    // MutantStack test
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    // Iterate through stack (impossible with std::stack!)
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Compare with std::list (should produce same output)
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    // ... same operations ...
    
    return 0;
}
```

## 📚 Technical Notes

### Iterator Usage Pattern
```cpp
// Forward iteration
Container::iterator it = container.begin();
Container::iterator ite = container.end();

while (it != ite) {
    std::cout << *it << std::endl;  // Dereference
    ++it;                            // Increment
}

// Reverse iteration
Container::reverse_iterator rit = container.rbegin();
Container::reverse_iterator rite = container.rend();

while (rit != rite) {
    std::cout << *rit << std::endl;
    ++rit;
}
```

### Algorithm Usage
```cpp
// Find element
std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), value);
if (it != vec.end()) {
    std::cout << "Found at position: " << std::distance(vec.begin(), it);
}

// Sort container
std::sort(vec.begin(), vec.end());

// Find min/max
int min = *std::min_element(vec.begin(), vec.end());
int max = *std::max_element(vec.begin(), vec.end());
```

### Container Adapter Access
```cpp
// std::stack structure (simplified)
template<typename T, typename Container = std::deque<T> >
class stack {
protected:
    Container c;  // Underlying container
    
public:
    void push(const T& x) { c.push_back(x); }
    void pop() { c.pop_back(); }
    T& top() { return c.back(); }
};

// MutantStack exposes 'c' through iterators
template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};
```

### Exception Safety
```cpp
class Span {
public:
    void addNumber(int n) {
        if (_numbers.size() >= _maxSize)
            throw SpanFullException();  // Prevent overflow
        _numbers.push_back(n);
    }
    
    int shortestSpan() const {
        if (_numbers.size() < 2)
            throw NoSpanException();   // Need at least 2 numbers
        // ... calculate span ...
    }
};
```

## 🚀 Advanced Features

- **Iterator Ranges:** Half-open range [begin, end) convention
- **Iterator Traits:** Type information about iterators
- **Algorithm Complexity:** Understanding time/space requirements
- **Container Adapters:** Customizing existing containers
- **Template Member Functions:** Generic operations within classes
- **STL Integration:** Seamless use with standard library

## ⚠️ Common Pitfalls

- **Iterator Invalidation:** Modifying container can invalidate iterators
- **End Iterator:** Never dereference end() - it's past-the-end
- **Container Capacity:** Check size before adding elements
- **Exception Handling:** Always catch exceptions from container operations
- **Deep vs Shallow Copy:** Understand container copy semantics
- **Algorithm Requirements:** Ensure container meets algorithm requirements
- **Protected Members:** Access restrictions in inheritance

## 🎯 STL Design Patterns

- **Iterator Pattern:** Uniform traversal interface for containers
- **Algorithm Pattern:** Generic operations separated from data structures
- **Adapter Pattern:** Providing new interface to existing container
- **RAII:** Resource management through container lifecycle
- **Generic Programming:** Type-independent implementations

## 📖 Comparison: Containers

| Container | Access | Insert | Search | Iterators |
|-----------|--------|--------|--------|-----------|
| **vector** | O(1) random | O(n) | O(n) | Random access |
| **list** | O(n) sequential | O(1) | O(n) | Bidirectional |
| **deque** | O(1) random | O(n)/O(1) | O(n) | Random access |
| **stack** | O(1) top only | O(1) push/pop | N/A | None (adapter) |

## 🔍 Memory Management Notes

### Vector Memory Model
```cpp
std::vector<int> vec;
vec.push_back(1);           // Allocates memory
vec.push_back(2);           // May reallocate + copy

// Reserve capacity to avoid reallocation
vec.reserve(1000);
for (int i = 0; i < 1000; i++)
    vec.push_back(i);       // No reallocation
```

### Span Memory Safety
```cpp
class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;  // Automatic memory management
    
public:
    void addNumber(int n) {
        if (_numbers.size() >= _maxSize)
            throw SpanFullException();
        _numbers.push_back(n);  // Vector handles allocation
    }
    
    // No manual delete needed - vector destructor handles it
};
```

## 💻 Testing Strategies

### Comprehensive Testing
```cpp
// Test different container types
std::vector<int> vec;
std::list<int> lst;
std::deque<int> deq;

// Test with easyfind
easyfind(vec, 42);
easyfind(lst, 42);
easyfind(deq, 42);

// Test edge cases
Span empty(0);              // Empty span
Span single(1);             // Single element
single.addNumber(42);
// single.shortestSpan();   // Should throw

// Test large datasets
Span large(100000);
std::vector<int> data(100000);
// ... fill data ...
large.addRange(data.begin(), data.end());

// Test MutantStack like regular stack
MutantStack<int> mstack;
mstack.push(1);
mstack.pop();
int top = mstack.top();

// But also iterate!
for (MutantStack<int>::iterator it = mstack.begin(); 
     it != mstack.end(); ++it) {
    std::cout << *it << std::endl;
}
```

## 🔄 Iterator Categories

```cpp
// Random Access (vector, deque)
vec[5];                     // Direct access
it + 5;                     // Arithmetic operations

// Bidirectional (list, set, map)
++it;                       // Forward
--it;                       // Backward

// Forward (forward_list)
++it;                       // Forward only

// Input/Output
// Read or write only, single pass
```

## 🎓 Learning Progression

1. **Module 07:** Templates basics
2. **Module 08:** STL containers, iterators, algorithms ← You are here
3. **Module 09:** Advanced containers and algorithms

---

*This module builds upon the template knowledge from Module 07 and introduces the Standard Template Library (STL), which is fundamental to modern C++ development. Understanding containers, iterators, and algorithms is essential for writing efficient, maintainable C++ code.*