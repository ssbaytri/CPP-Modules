# C++ Module 03 - Inheritance

## Overview

This module introduces **Object-Oriented Programming (OOP)** concepts in C++, specifically focusing on **inheritance**. The exercises demonstrate how to create base classes and derive new classes from them, exploring the relationships and behaviors between parent and child classes.

## Learning Objectives

- Understanding inheritance in C++
- Implementing base and derived classes
- Constructor and destructor chaining
- Virtual functions and polymorphism
- Multiple inheritance (Diamond Problem)
- Orthodox Canonical Form compliance

## Compilation Requirements

```bash
c++ -Wall -Wextra -Werror -std=c++98 [source_files]
```

## Project Structure

```
cpp03/
├── ex00/           # ClapTrap base class
├── ex01/           # ScavTrap inheritance
├── ex02/           # FragTrap inheritance
├── ex03/           # DiamondTrap multiple inheritance
└── README.md
```

## Exercises

### Exercise 00: Aaaaand... OPEN!

**Objective**: Implement a base class called `ClapTrap`.

**Files**: `Makefile`, `main.cpp`, `ClapTrap.{h,hpp}`, `ClapTrap.cpp`

**Features**:
- Private attributes: `name`, `hit_points (10)`, `energy_points (10)`, `attack_damage (0)`
- Public methods: `attack()`, `takeDamage()`, `beRepaired()`
- Constructor/destructor with debug messages
- Energy and hit points management

**Key Concepts**:
- Basic class implementation
- Encapsulation with private attributes
- Public interface methods

### Exercise 01: Serena, my love!

**Objective**: Create `ScavTrap` class that inherits from `ClapTrap`.

**Files**: Previous files + `ScavTrap.{h,hpp}`, `ScavTrap.cpp`

**Features**:
- Inherits from `ClapTrap`
- Different attribute values: `hit_points (100)`, `energy_points (50)`, `attack_damage (20)`
- Overridden `attack()` method with different message
- Special ability: `guardGate()`
- Proper construction/destruction chaining

**Key Concepts**:
- Basic inheritance
- Constructor/destructor chaining
- Method overriding
- Access to protected members

### Exercise 02: Repetitive work

**Objective**: Implement `FragTrap` class, another `ClapTrap` derivative.

**Files**: Previous files + `FragTrap.{h,hpp}`, `FragTrap.cpp`

**Features**:
- Inherits from `ClapTrap`
- Different attribute values: `hit_points (100)`, `energy_points (100)`, `attack_damage (30)`
- Unique construction/destruction messages
- Special ability: `highFivesGuys()`
- Proper construction/destruction chaining

**Key Concepts**:
- Multiple derived classes from same base
- Different initialization values per derived class
- Specialized behaviors in derived classes

### Exercise 03: Now it's weird! (Bonus)

**Objective**: Create `DiamondTrap` with multiple inheritance from both `FragTrap` and `ScavTrap`.

**Files**: Previous files + `DiamondTrap.{h,hpp}`, `DiamondTrap.cpp`

**Features**:
- Inherits from both `FragTrap` AND `ScavTrap`
- Private `name` attribute (same variable name as `ClapTrap`)
- Attribute inheritance: HP from `FragTrap`, Energy from `ScavTrap`, Attack from `FragTrap`
- Method inheritance: `attack()` from `ScavTrap`
- Special ability: `whoAmI()`
- Virtual inheritance to solve Diamond Problem

**Key Concepts**:
- Multiple inheritance
- Diamond Problem resolution
- Virtual inheritance
- Name shadowing (`-Wshadow` flag awareness)

## Implementation Guidelines

### Orthodox Canonical Form
All classes must implement:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

### Memory Management
- Proper memory allocation/deallocation
- No memory leaks
- Use of `new`/`delete` when necessary

### Design Patterns
- Clear inheritance hierarchy
- Proper encapsulation
- Meaningful method names and messages

## Testing Strategy

Each exercise should include comprehensive tests demonstrating:
- Object creation and destruction
- Method functionality
- Inheritance behavior
- Constructor/destructor chaining
- Error handling (no energy/hit points)

## Common Pitfalls

1. **Constructor Chaining**: Ensure derived class constructors properly call base class constructors
2. **Virtual Destructors**: Consider when virtual destructors are needed
3. **Diamond Problem**: Exercise 03 requires careful handling of multiple inheritance
4. **Name Shadowing**: Be aware of variable name conflicts in multiple inheritance

## Compilation Examples

```bash
# Exercise 00
make -C ex00 && ./ex00/claptrap

# Exercise 01
make -C ex01 && ./ex01/scavtrap

# Exercise 02
make -C ex02 && ./ex02/fragtrap

# Exercise 03 (if implemented)
make -C ex03 && ./ex03/diamondtrap
```

## Key C++ Concepts Covered

- **Inheritance**: `class Derived : public Base`
- **Constructor Delegation**: Base class initialization
- **Method Overriding**: Redefining base class methods
- **Access Specifiers**: `public`, `protected`, `private`
- **Multiple Inheritance**: `class D : public A, public B`
- **Virtual Inheritance**: Solving diamond problem
- **Polymorphism**: Different behaviors for same interface

## Notes

- This module uses **C++98 standard**
- No STL containers or algorithms allowed (until Module 08/09)
- No external libraries beyond standard library
- Focus on understanding inheritance mechanics rather than complex implementations

## Resources

- [C++ Inheritance Documentation](https://en.cppreference.com/w/cpp/language/inheritance)
- [Diamond Problem Explanation](https://en.wikipedia.org/wiki/Multiple_inheritance#The_diamond_problem)
- [Orthodox Canonical Form](https://en.cppreference.com/w/cpp/language/rule_of_three)

---

*This module serves as an introduction to OOP concepts in C++. Mastering inheritance is crucial for understanding more advanced C++ features in subsequent modules.*
