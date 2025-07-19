# C++ Module 02 - Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Form

This repository contains the implementation of C++ Module 02 exercises from the 42 curriculum, focusing on **ad-hoc polymorphism**, **operator overloading**, and the **Orthodox Canonical Form**.

## 📋 Table of Contents

- [Overview](#overview)
- [Learning Objectives](#learning-objectives)
- [Exercises](#exercises)
- [Compilation](#compilation)
- [Key Concepts](#key-concepts)
- [Usage Examples](#usage-examples)

## 🎯 Overview

This module introduces fundamental Object-Oriented Programming concepts in C++, with a specific focus on:
- **Fixed-point arithmetic** as an alternative to floating-point numbers
- **Orthodox Canonical Form** for class design
- **Operator overloading** for custom data types
- **Ad-hoc polymorphism** through function overloading

## 🎓 Learning Objectives

By completing this module, you will understand:

- How to implement the Orthodox Canonical Form (The Big Four)
- Fixed-point number representation and arithmetic
- Operator overloading for comparison, arithmetic, and stream operations
- Static member functions and their use cases
- Binary Space Partitioning (BSP) algorithms

## 📁 Exercises

### Exercise 00: My First Class in Orthodox Canonical Form
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

Implementation of a basic Fixed-point number class following the Orthodox Canonical Form:
- Default constructor
- Copy constructor  
- Copy assignment operator
- Destructor
- Basic getter/setter methods

**Key Features:**
- 8 fractional bits representation
- Raw value storage and retrieval
- Proper constructor/destructor messaging

### Exercise 01: Towards a More Useful Fixed-Point Number Class
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

Enhanced Fixed-point class with additional constructors and conversion methods:
- Integer constructor
- Float constructor
- Float/Integer conversion methods
- Stream insertion operator overload

**Key Features:**
- Automatic conversion from int/float to fixed-point
- Conversion back to int/float
- Proper stream output formatting

### Exercise 02: Now We're Talking
**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

Complete Fixed-point class with full operator overloading:
- Comparison operators (`>`, `<`, `>=`, `<=`, `==`, `!=`)
- Arithmetic operators (`+`, `-`, `*`, `/`)
- Increment/decrement operators (pre/post)
- Static min/max functions

**Key Features:**
- Full arithmetic operations support
- Epsilon-based increment/decrement
- Static utility functions for comparison

### Exercise 03: BSP (Binary Space Partitioning)
**Files:** `Fixed.hpp`, `Fixed.cpp`, `Point.hpp`, `Point.cpp`, `bsp.cpp`, `main.cpp`, `Makefile`

Implementation of a Point class and BSP algorithm:
- Point class representing 2D coordinates
- BSP function to determine if a point is inside a triangle
- Utilizes the Fixed-point class for precise calculations

**Key Features:**
- 2D point representation with const Fixed coordinates
- Triangle inside/outside point determination
- Edge and vertex cases handled (returns false)

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

### Orthodox Canonical Form
Every class implements the "Big Four":
1. **Default Constructor** - Initializes object with default values
2. **Copy Constructor** - Creates object from another object
3. **Copy Assignment Operator** - Assigns one object to another
4. **Destructor** - Cleans up resources when object is destroyed

### Fixed-Point Arithmetic
- **Representation:** Integer with implied decimal point
- **Precision:** 8 fractional bits (1/256 smallest increment)
- **Advantages:** Deterministic, no floating-point errors
- **Use cases:** Graphics, audio processing, embedded systems

### Operator Overloading Categories
- **Arithmetic:** `+`, `-`, `*`, `/`
- **Comparison:** `>`, `<`, `>=`, `<=`, `==`, `!=` 
- **Increment/Decrement:** `++`, `--` (pre and post)
- **Stream:** `<<` for output

## 💡 Usage Examples

### Exercise 00 - Basic Usage
```cpp
Fixed a;                    // Default constructor
Fixed b(a);                 // Copy constructor  
Fixed c;                    // Default constructor
c = b;                      // Copy assignment

std::cout << a.getRawBits() << std::endl;  // Output: 0
```

### Exercise 01 - Constructors and Conversions
```cpp
Fixed a;                    // Default: 0
Fixed b(10);                // From integer
Fixed c(42.42f);           // From float
Fixed d(b);                 // Copy constructor

std::cout << "a is " << a << std::endl;           // a is 0
std::cout << "b is " << b.toInt() << std::endl;   // b is 10
```

### Exercise 02 - Operators and Functions
```cpp
Fixed a;
Fixed b(Fixed(5.05f) * Fixed(2));

std::cout << a << std::endl;        // 0
std::cout << ++a << std::endl;      // 0.00390625
std::cout << a++ << std::endl;      // 0.00390625  
std::cout << a << std::endl;        // 0.0078125

std::cout << Fixed::max(a, b) << std::endl;  // 10.1016
```

### Exercise 03 - Point and BSP
```cpp
Point a(0.0f, 0.0f);
Point b(10.0f, 0.0f); 
Point c(5.0f, 10.0f);
Point p(5.0f, 5.0f);

bool inside = bsp(a, b, c, p);  // Check if p is inside triangle abc
```

## 📚 Technical Notes

- **Memory Management:** No dynamic allocation required in these exercises
- **Precision:** Fixed-point provides consistent precision across operations
- **Standard:** Code complies with C++98 standard
- **Error Handling:** Division by zero may cause program termination

## 🚀 Advanced Features

- **Static Functions:** `min()` and `max()` work without object instances
- **Const Correctness:** Proper use of const methods and parameters
- **Operator Precedence:** Maintains standard mathematical operator precedence
- **BSP Algorithm:** Efficient point-in-triangle testing using area calculations

---

*This module serves as a foundation for understanding advanced C++ concepts including polymorphism, inheritance, and template programming covered in subsequent modules.*