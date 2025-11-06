
# C++ Module 07 - Templates

This repository contains the implementation of C++ Module 07 exercises from the 42 curriculum, focusing on **C++ templates**, **generic programming**, and **template metaprogramming fundamentals**.

## 📋 Table of Contents

- [Overview](#-overview)
- [Learning Objectives](#-learning-objectives)
- [Exercises](#-exercises)
- [Compilation](#-compilation)
- [Key Concepts](#-key-concepts)
- [Usage Examples](#-usage-examples)

## 🎯 Overview

This module introduces template programming in C++, with a specific focus on:
- **Function templates** for generic algorithms
- **Class templates** for generic data structures
- **Template instantiation** and type deduction
- **Generic programming principles**
- **Type-safe generic containers**

## 🎓 Learning Objectives

By completing this module, you will understand:

- How to write function templates that work with any type
- Template syntax and instantiation mechanisms
- Creating generic, reusable code components
- Class template design and implementation
- Template parameter deduction
- Exception handling in template contexts
- Memory management with templates

## 📁 Exercises

### Exercise 00: Start with a few functions
**Files:** `whatever.hpp`, `main.cpp`, `Makefile`

Implementation of basic function templates:
- `swap`: Exchanges values of two parameters of the same type
- `min`: Returns the smaller of two values (second if equal)
- `max`: Returns the larger of two values (second if equal)
- Works with any type supporting comparison operators
- Template definitions in header file

**Key Features:**
- Function template syntax
- Template type deduction
- Generic comparison operations
- Works with built-in and user-defined types

**Example:**
```cpp
int a = 2, b = 3;
::swap(a, b);           // a = 3, b = 2
::min(a, b);            // returns 2
::max(a, b);            // returns 3

std::string c = "chaine1", d = "chaine2";
::swap(c, d);           // c = "chaine2", d = "chaine1"
```

### Exercise 01: Iter
**Files:** `iter.hpp`, `main.cpp`, `Makefile`

Generic iteration function template:
- `iter`: Applies a function to every element of an array
- Three parameters: array address, length, function to apply
- Works with any array type and compatible function
- Supports both const and non-const element access
- Function parameter can be function pointer or function template

**Key Features:**
- Template function pointers
- Generic array iteration
- Const-correctness with templates
- Function template as parameter
- Type-safe generic algorithms

**Example:**
```cpp
int arr[5] = {1, 2, 3, 4, 5};
iter(arr, 5, print<int>);        // Prints each element

iter(arr, 5, increment<int>);    // Modifies each element
```

### Exercise 02: Array
**Files:** `Array.hpp`, `Array.tpp` (optional), `main.cpp`, `Makefile`

Generic array class template with dynamic memory management:
- Default constructor creating empty array
- Parameterized constructor with size (elements default-initialized)
- Copy constructor implementing deep copy
- Assignment operator with deep copy
- Subscript operator `[]` with bounds checking
- `size()` member function returning element count
- Exception throwing for out-of-bounds access
- Proper memory management with `new[]` and `delete[]`

**Key Features:**
- Class template implementation
- Dynamic memory allocation with templates
- Deep copy semantics in templates
- Exception handling with `std::exception`
- Bounds-checked array access
- Orthodox Canonical Form with templates
- Generic container design

**Example:**
```cpp
Array<int> numbers(750);
numbers[0] = 42;
numbers[1] = 100;

Array<int> copy = numbers;      // Deep copy
copy[0] = 999;                  // Doesn't affect numbers

try {
    numbers[1000] = 0;          // Throws exception
} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
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

### Template Basics
- **Function Templates:** Generic functions working with any type
- **Class Templates:** Generic classes parameterized by type
- **Template Parameters:** Type parameters specified with `template<typename T>`
- **Template Instantiation:** Compiler generates specific versions for each type used
- **Type Deduction:** Automatic determination of template parameters

### Template Syntax
```cpp
// Function template
template<typename T>
void function(T param) { }

// Class template
template<typename T>
class ClassName {
    T member;
};
```

### Template Instantiation
- **Implicit Instantiation:** Compiler generates code when template is used
- **Explicit Instantiation:** Manual specification of template parameters
- **Template Definition:** Must be visible at point of use (typically in headers)

### Generic Programming Principles
- **Code Reusability:** Write once, use with multiple types
- **Type Safety:** Compile-time type checking
- **Performance:** No runtime overhead (compile-time polymorphism)
- **Algorithm Abstraction:** Separate algorithms from data types

## 💡 Usage Examples

### Exercise 00 - Function Templates
```cpp
#include "whatever.hpp"

int main() {
    int a = 5, b = 10;
    std::cout << "Before: a=" << a << ", b=" << b << std::endl;
    
    ::swap(a, b);
    std::cout << "After: a=" << a << ", b=" << b << std::endl;
    
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    
    // Works with any type
    double x = 3.14, y = 2.71;
    ::swap(x, y);
    std::cout << "x=" << x << ", y=" << y << std::endl;
    
    return 0;
}
```

### Exercise 01 - Iter Template
```cpp
#include "iter.hpp"

template<typename T>
void print(const T& elem) {
    std::cout << elem << " ";
}

template<typename T>
void increment(T& elem) {
    elem += 1;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    std::string words[] = {"Hello", "World", "Templates"};
    
    std::cout << "Numbers: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;
    
    iter(numbers, 5, increment<int>);  // Modify array
    
    std::cout << "Modified: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;
    
    std::cout << "Strings: ";
    iter(words, 3, print<std::string>);
    std::cout << std::endl;
    
    return 0;
}
```

### Exercise 02 - Array Template
```cpp
#include "Array.hpp"

int main() {
    // Create empty array
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;
    
    // Create array with size
    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    
    // Deep copy
    Array<int> copy(numbers);
    copy[0] = 999;
    
    std::cout << "Original[0]: " << numbers[0] << std::endl;  // Still 0
    std::cout << "Copy[0]: " << copy[0] << std::endl;         // 999
    
    // Exception handling
    try {
        numbers[100] = 42;  // Out of bounds
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Works with any type
    Array<std::string> strings(3);
    strings[0] = "Templates";
    strings[1] = "are";
    strings[2] = "awesome";
    
    return 0;
}
```

## 📚 Technical Notes

### Function Template Declaration
```cpp
template<typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Can also use 'class' instead of 'typename' (same meaning)
template<class T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}
```

### Class Template Declaration
```cpp
template<typename T>
class Array {
private:
    T* _data;
    unsigned int _size;
    
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();
    
    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    unsigned int size() const;
};

// Member function implementation
template<typename T>
Array<T>::Array() : _data(NULL), _size(0) {
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}
```

### Template Best Practices
```cpp
// 1. Always define templates in headers
// Templates need to be visible at instantiation point

// 2. Use const references for read-only parameters
template<typename T>
const T& min(const T& a, const T& b);

// 3. Provide clear requirements for template parameters
// (e.g., type T must support operator<)

// 4. Handle exceptions appropriately
template<typename T>
class Container {
    void at(size_t index) {
        if (index >= size)
            throw std::out_of_range("Invalid index");
    }
};
```

## 🚀 Advanced Features

- **Template Type Deduction:** Automatic parameter type inference
- **Multiple Template Parameters:** `template<typename T, typename U>`
- **Non-type Template Parameters:** `template<typename T, int SIZE>`
- **Template Specialization:** Specific implementations for particular types
- **SFINAE:** Substitution Failure Is Not An Error principle
- **Generic Algorithms:** Type-independent algorithm implementations

## ⚠️ Common Pitfalls

- **Template Definition Location:** Templates must be defined in headers (not just declared)
- **Linking Errors:** Missing template definitions at instantiation point
- **Type Requirements:** Template parameters must support required operations
- **Deep vs Shallow Copy:** Ensure proper deep copying with dynamic memory
- **Exception Safety:** Handle exceptions in template code properly
- **Const Correctness:** Provide const and non-const versions where needed

## 🎯 Template Design Patterns

- **Generic Algorithms:** Functions that work with any compatible type
- **Generic Containers:** Data structures parameterized by element type
- **Policy-Based Design:** Templates with behavior customization
- **Type Traits:** Compile-time type information and manipulation
- **CRTP (Curiously Recurring Template Pattern):** Advanced template technique

## 📖 Comparison: Templates vs Polymorphism

| Feature | Templates | Virtual Functions |
|---------|-----------|-------------------|
| **Binding** | Compile-time | Runtime |
| **Performance** | No overhead | Virtual table lookup |
| **Type Safety** | Compile-time checking | Runtime type checking |
| **Code Size** | Separate code for each type | Single implementation |
| **Flexibility** | Works with any type | Requires inheritance |
| **Use Case** | Generic algorithms/containers | Polymorphic behavior |

## 🔍 Memory Management Notes

### Array Template Memory Safety
```cpp
// Constructor with size
Array(unsigned int n) : _data(new T[n]()), _size(n) {
    // T[n]() performs default initialization
    // Primitive types: zero-initialized
    // Objects: default constructor called
}

// Deep copy constructor
Array(const Array& other) : _data(new T[other._size]), _size(other._size) {
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];  // Copy each element
}

// Destructor
~Array() {
    delete[] _data;  // Must use delete[] for arrays
}

// Assignment operator
Array& operator=(const Array& other) {
    if (this != &other) {
        delete[] _data;              // Free old memory
        _size = other._size;
        _data = new T[_size];        // Allocate new memory
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return *this;
}
```

## 💻 Testing Strategies

### Comprehensive Testing
```cpp
// Test with different types
Array<int> intArray(10);
Array<std::string> stringArray(5);
Array<double> doubleArray(20);

// Test boundary conditions
Array<int> empty;                    // Empty array
Array<int> single(1);                // Single element

// Test copy semantics
Array<int> original(5);
Array<int> copied(original);         // Copy constructor
Array<int> assigned = original;      // Assignment operator

// Test exception handling
try {
    original[-1] = 0;                // Negative index
} catch (std::exception& e) { }

try {
    original[100] = 0;               // Out of bounds
} catch (std::exception& e) { }

// Test with custom classes
class MyClass { /* ... */ };
Array<MyClass> customArray(10);
```

---

*This module introduces fundamental template programming concepts that form the foundation for understanding the Standard Template Library (STL) in Module 08 and advanced container usage in Module 09. Mastery of templates is essential for modern C++ development and generic programming.*
