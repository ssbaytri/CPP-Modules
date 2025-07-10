# C++ Module 01 - Memory Allocation, Pointers to Members, References and Switch Statements

This module introduces fundamental C++ concepts including memory allocation, pointers to members, references, and switch statements. The exercises focus on understanding memory management and object-oriented programming principles.

## 📋 Table of Contents

- [General Information](#general-information)
- [Compilation](#compilation)
- [Exercises](#exercises)
  - [Exercise 00: BraiiiiiiinnnzzzZ](./ex00/)
  - [Exercise 01: Moar brainz!](./ex01/)
  - [Exercise 02: HI THIS IS BRAIN](./ex02/)
  - [Exercise 03: Unnecessary violence](./ex03/)
  - [Exercise 04: Sed is for losers](./ex04/)
  - [Exercise 05: Harl 2.0](./ex05/)
  - [Exercise 06: Harl filter](./ex06/)
- [Key Learning Objectives](#key-learning-objectives)
- [Important Notes](#important-notes)

## 🎯 General Information

This module is part of the 42 C++ curriculum and focuses on:
- Memory allocation using `new` and `delete`
- Understanding the difference between stack and heap allocation
- Working with pointers to member functions
- Using references as an alternative to pointers
- Implementing switch statements

**Standard**: C++98  
**Version**: 10.1

## 🔧 Compilation

All exercises must be compiled with:
```bash
c++ -Wall -Wextra -Werror -std=c++98 [source_files]
```

## 📚 Exercises

### Exercise 00: BraiiiiiiinnnzzzZ
**Directory**: `ex00/`  
**Files**: `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`

**Objective**: Create a Zombie class and understand stack vs heap allocation.

**Key Components**:
- `Zombie` class with private `name` attribute
- `announce()` member function that prints: `<name>: BraiiiiiiinnnzzzZ...`
- `newZombie()` function that creates a zombie on the heap
- `randomChump()` function that creates a zombie on the stack
- Proper destructor implementation for debugging

**Learning Focus**: Understanding when to use stack vs heap allocation and proper memory management.

### Exercise 01: Moar brainz!
**Directory**: `ex01/`  
**Files**: `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `zombieHorde.cpp`

**Objective**: Allocate multiple objects in a single allocation.

**Key Components**:
- `zombieHorde()` function that allocates N zombies in one allocation
- Proper initialization of all zombies with the same name
- Memory deallocation using `delete[]`

**Learning Focus**: Array allocation with `new[]` and proper cleanup with `delete[]`.

### Exercise 02: HI THIS IS BRAIN
**Directory**: `ex02/`  
**Files**: `Makefile`, `main.cpp`

**Objective**: Understand the relationship between variables, pointers, and references.

**Key Components**:
- String variable initialized to "HI THIS IS BRAIN"
- Pointer to the string (`stringPTR`)
- Reference to the string (`stringREF`)
- Display memory addresses and values

**Learning Focus**: Demystifying references and understanding they're another syntax for address manipulation.

### Exercise 03: Unnecessary violence
**Directory**: `ex03/`  
**Files**: `Makefile`, `main.cpp`, `Weapon.{h,hpp}`, `Weapon.cpp`, `HumanA.{h,hpp}`, `HumanA.cpp`, `HumanB.{h,hpp}`, `HumanB.cpp`

**Objective**: Understand when to use pointers vs references.

**Key Components**:
- `Weapon` class with private `type` attribute
- `getType()` returns const reference to type
- `setType()` modifies the weapon type
- `HumanA` class that always has a weapon (uses reference)
- `HumanB` class that may not have a weapon (uses pointer)
- `attack()` function that displays: `<name> attacks with their <weapon type>`

**Learning Focus**: Choosing between pointers and references based on use case.

### Exercise 04: Sed is for losers
**Directory**: `ex04/`  
**Files**: `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`

**Objective**: File manipulation and string processing in C++.

**Key Components**:
- Program takes three parameters: filename, s1 (search), s2 (replace)
- Creates `<filename>.replace` with all occurrences of s1 replaced by s2
- Must use C++ file streams (no C file functions)
- Cannot use `std::string::replace()`

**Learning Focus**: File I/O in C++ and string manipulation without built-in replace function.

### Exercise 05: Harl 2.0
**Directory**: `ex05/`  
**Files**: `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp`

**Objective**: Implement pointers to member functions.

**Key Components**:
- `Harl` class with private functions: `debug()`, `info()`, `warning()`, `error()`
- `complain()` function that calls appropriate function based on level
- Must use pointers to member functions (no if/else chains)

**Log Levels**:
- **DEBUG**: Contextual information for problem diagnosis
- **INFO**: Extensive information for tracing execution
- **WARNING**: Potential issues that can be handled
- **ERROR**: Unrecoverable errors requiring intervention

**Learning Focus**: Pointers to member functions as an alternative to conditional statements.

### Exercise 06: Harl filter
**Directory**: `ex06/`  
**Files**: `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp`

**Objective**: Implement filtering system using switch statements.

**Key Components**:
- Program takes one parameter (log level)
- Displays messages from specified level and above
- Uses switch statement for level filtering
- Executable name must be `harlFilter`

**Example**:
```bash
./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years, whereas you started working here just last month.
[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

**Learning Focus**: Switch statements and cascading behavior.

## 🎓 Key Learning Objectives

By completing this module, you will understand:

1. **Memory Management**: When and how to use stack vs heap allocation
2. **References**: Alternative syntax to pointers for certain use cases
3. **Pointers to Member Functions**: Advanced function pointer concepts
4. **File I/O**: C++ streams for file manipulation
5. **Switch Statements**: Efficient alternative to if/else chains
6. **Object Design**: When to use pointers vs references in class design

## ⚠️ Important Notes

### Compilation Rules
- Use C++98 standard
- Compile with `-Wall -Wextra -Werror`
- No external libraries except standard library
- No STL containers until Module 08

### Forbidden Functions
- `*printf()` family functions
- `*alloc()` and `free()`
- `using namespace` (except when explicitly allowed)
- `friend` keyword
- `std::string::replace()` (Exercise 04 only)

### Design Requirements
- Avoid memory leaks
- Use Orthodox Canonical Form (from Module 02 onwards)
- Include guards in header files
- No function implementations in header files (except templates)
- Each header must be independently usable

### Memory Management
- Every `new` must have corresponding `delete`
- Use `new[]` with `delete[]` for arrays
- Stack allocation for temporary objects
- Heap allocation for objects that outlive their scope

---

*This module is part of the 42 C++ curriculum. Each exercise builds upon previous concepts, so complete them in order for maximum learning benefit.*
