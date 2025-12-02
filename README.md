# CPP Modules

A comprehensive collection of C++ programming exercises covering fundamental to advanced concepts in Modern C++.  This repository contains 10 modules (CPP Module 00-09) designed to progressively build C++ programming skills.

## 📋 Table of Contents

- [About](#about)
- [Modules Overview](#modules-overview)
- [Getting Started](#getting-started)
- [Compilation](#compilation)
- [Requirements](#requirements)
- [Module Structure](#module-structure)
- [Learning Objectives](#learning-objectives)
- [Author](#author)

## 📖 About

This repository is a structured learning path through C++ programming, covering everything from basic syntax and object-oriented programming to advanced topics like templates, STL containers, and design patterns. Each module builds upon the previous one, introducing new concepts and reinforcing fundamental principles.

## 🎯 Modules Overview

### Module 00 - Namespaces, Classes, Member Functions, I/O Streams
Introduction to C++ basics and object-oriented programming fundamentals. 
- Namespaces
- Classes and objects
- Member functions and attributes
- stdio streams
- Initialization lists
- Static and const members

### Module 01 - Memory Allocation, Pointers, References
Deep dive into memory management and understanding the difference between stack and heap.
- Memory allocation
- Pointers to members
- References
- Switch statements

### Module 02 - Ad-hoc Polymorphism, Operator Overloading
Understanding polymorphism and implementing custom operators.
- Ad-hoc polymorphism
- Operator overloading
- Orthodox Canonical class form
- Fixed-point numbers

### Module 03 - Inheritance
Introduction to inheritance and class hierarchies.
- Inheritance basics
- Base and derived classes
- Access specifiers (public, protected, private)
- Multiple inheritance

### Module 04 - Subtype Polymorphism, Abstract Classes, Interfaces
Advanced OOP concepts including polymorphism and abstraction.
- Subtype polymorphism
- Abstract classes
- Interfaces
- Virtual functions and destructors

### Module 05 - Repetition and Exceptions
Error handling and exception management in C++.
- Try/catch blocks
- Exception classes
- Custom exceptions
- RAII (Resource Acquisition Is Initialization)

### Module 06 - C++ Casts
Understanding different types of casting in C++.
- Static cast
- Dynamic cast
- Const cast
- Reinterpret cast
- Scalar type conversions

### Module 07 - C++ Templates
Introduction to generic programming with templates.
- Function templates
- Class templates
- Template specialization
- Template instantiation

### Module 08 - Templated Containers, Iterators, Algorithms
Working with STL and understanding iterators. 
- STL containers (vector, list, map, etc.)
- Iterators
- Algorithms
- Container adaptors

### Module 09 - STL Containers and Algorithms
Advanced usage of Standard Template Library. 
- Advanced STL usage
- Container operations
- Algorithm composition
- Performance considerations

## 🚀 Getting Started

### Prerequisites

- C++ compiler supporting C++98 standard or later (g++, clang++)
- Make utility
- Unix-based operating system (Linux, macOS) or WSL for Windows

### Installation

Clone the repository:

```bash
git clone https://github.com/ssbaytri/CPP-Modules.git
cd CPP-Modules
```

## 🔨 Compilation

Each module contains multiple exercises, each with its own Makefile.  To compile an exercise:

```bash
# Navigate to a specific module and exercise
cd "CPP Module 00"
cd ex00  # or any exercise directory

# Compile using Make
make

# Run the executable
./[executable_name]

# Clean object files
make clean

# Clean everything including the executable
make fclean

# Recompile
make re
```

## 📦 Requirements

All projects in this repository follow these requirements:

- **Language Standard**: C++98
- **Compiler Flags**: `-Wall -Wextra -Werror`
- **Coding Standard**: Orthodox Canonical Form for classes (where applicable)
- **Forbidden Functions**: Varies by module (specified in each exercise)
- **Memory Management**: No memory leaks allowed

## 📂 Module Structure

Each module typically contains:

```
CPP Module XX/
├── ex00/          # First exercise
│   ├── Makefile
│   ├── *.cpp
│   └── *.hpp
├── ex01/          # Second exercise
│   ├── Makefile
│   ├── *.cpp
│   └── *.hpp
└── ...
```

## 🎓 Learning Objectives

By completing these modules, you will:

- ✅ Master object-oriented programming in C++
- ✅ Understand memory management and RAII principles
- ✅ Learn proper use of inheritance and polymorphism
- ✅ Implement operator overloading correctly
- ✅ Handle exceptions effectively
- ✅ Use C++ casts appropriately
- ✅ Work with templates and generic programming
- ✅ Utilize the Standard Template Library (STL)
- ✅ Write clean, maintainable, and efficient C++ code

## 🔍 Key Concepts Covered

- **OOP Principles**: Encapsulation, Inheritance, Polymorphism, Abstraction
- **Memory Management**: Stack vs Heap, new/delete, smart pointers concepts
- **C++ Specific Features**: References, const correctness, operator overloading
- **Exception Handling**: Try-catch, exception safety, RAII
- **Generic Programming**: Templates, type deduction, template specialization
- **STL**: Containers, iterators, algorithms, functors

## 👤 Author

**ssbaytri**
- GitHub: [@ssbaytri](https://github.com/ssbaytri)

## 📝 Notes

- Each module must be completed in order as they build upon each other
- All code follows the C++98 standard
- Solutions emphasize clean code practices and proper C++ idioms
- Memory leaks are strictly forbidden and should be checked with tools like valgrind

---

*This repository is part of a structured C++ curriculum designed to build strong foundations in modern C++ programming.*
```
