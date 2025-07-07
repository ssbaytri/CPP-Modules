# C++ Module 00 - Introduction to Object-Oriented Programming

This repository contains the implementation of three exercises from C++ Module 00, focusing on basic C++ concepts including namespaces, classes, member functions, stdio streams, initialization lists, static, const, and other fundamental concepts.

## 📚 Learning Objectives

- Introduction to Object-Oriented Programming (OOP) in C++
- Understanding C++ syntax and basic concepts
- Working with classes and member functions
- Using C++ standard library features
- Memory management and proper coding practices

## 🛠️ Compilation Requirements

All exercises must be compiled with:
```bash
c++ -Wall -Wextra -Werror -std=c++98 [source_files]
```

## 📋 Exercises Overview

### Exercise 00: Megaphone 📢
**Files:** `ex00/Makefile`, `ex00/megaphone.cpp`

A simple program that converts command-line arguments to uppercase and displays them.

**Features:**
- Converts all arguments to uppercase
- Handles multiple arguments with proper spacing
- Displays default message when no arguments provided

**Usage Examples:**
```bash
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Key Concepts:**
- Command-line argument processing
- String manipulation
- C++ iostream usage

---

### Exercise 01: My Awesome PhoneBook 📞
**Files:** `ex01/Makefile`, `ex01/*.cpp`, `ex01/*.{h,hpp}`

A phonebook application that manages contacts with basic CRUD operations.

**Classes Implemented:**
- `PhoneBook`: Main container class for managing contacts
- `Contact`: Individual contact representation

**Features:**
- Store up to 8 contacts (oldest replaced when full)
- Three main commands: ADD, SEARCH, EXIT
- Formatted display with proper alignment and truncation
- Input validation for empty fields

**Commands:**
- **ADD**: Add a new contact with fields:
  - First name
  - Last name
  - Nickname
  - Phone number
  - Darkest secret
- **SEARCH**: Display contacts in formatted table and view specific contact details
- **EXIT**: Quit the program

**Display Format:**
```
     Index|First Name| Last Name|  Nickname
         1|      John|     Smith|    Johnny
         2|      Jane|       Doe|        J.
```

**Key Concepts:**
- Class design and encapsulation
- Private vs public members
- Array management without dynamic allocation
- String formatting and manipulation
- Input/output streams

---

### Exercise 02: The Job Of Your Dreams 💼
**Files:** `ex02/Makefile`, `ex02/Account.cpp`, `ex02/Account.hpp`, `ex02/tests.cpp`

Recreation of a banking account system based on provided header file and test output.

**Challenge:**
- Implement `Account.cpp` based on existing `Account.hpp`
- Match exact output format from provided log file
- Handle static members and proper initialization

**Features:**
- Account creation and management
- Transaction logging with timestamps
- Static member tracking (total accounts, total amount, etc.)
- Proper constructor/destructor implementation

**Key Concepts:**
- Static member variables and functions
- Constructor/destructor implementation
- File I/O and logging
- Reverse engineering from header files
- Understanding existing code structure

---

## 🚀 Getting Started

### Prerequisites
- C++ compiler supporting C++98 standard
- Make utility

### Compilation
Each exercise has its own Makefile. Navigate to the exercise directory and run:
```bash
make
```

### Running the Programs
```bash
# Exercise 00
./megaphone [arguments...]

# Exercise 01
./phonebook

# Exercise 02
./account_test
```

## 📁 Project Structure
```
cpp_module00/
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── PhoneBook.hpp
│   ├── PhoneBook.cpp
│   ├── Contact.hpp
│   ├── Contact.cpp
│   └── main.cpp
├── ex02/
│   ├── Makefile
│   ├── Account.hpp
│   ├── Account.cpp
│   └── tests.cpp
└── README.md
```

## 🔧 Implementation Notes

### General Guidelines
- Follow C++98 standard
- No external libraries beyond standard library
- No STL containers until Module 08
- Proper memory management (avoid leaks)
- Clean, readable code structure

### Forbidden Functions/Features
- `printf()` family functions
- `*alloc()` and `free()`
- `using namespace` declarations
- `friend` keyword
- C++11 and later features

## 🎯 Key Takeaways

1. **Object-Oriented Design**: Understanding how to structure code using classes and objects
2. **Encapsulation**: Proper use of private/public access specifiers
3. **Memory Management**: Working within C++98 constraints without dynamic allocation
4. **Standard Library**: Using C++ streams and string manipulation
5. **Code Organization**: Proper header/source file separation

## 📖 Resources

- [C++ String Reference](http://www.cplusplus.com/reference/string/string/)
- [C++ IOManip Reference](http://www.cplusplus.com/reference/iomanip/)
- C++98 Standard Documentation

## 🏆 Completion Status

- [x] Exercise 00: Megaphone
- [x] Exercise 01: My Awesome PhoneBook  
- [x] Exercise 02: The Job Of Your Dreams

---

*This module serves as an introduction to C++ and Object-Oriented Programming. Each exercise builds upon previous concepts while introducing new C++ features and best practices.*
