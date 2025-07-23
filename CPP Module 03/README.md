# C++ Module 03 - Inheritance

This repository contains the implementation of C++ Module 03 exercises from the 42 curriculum, focusing on **inheritance**, **polymorphism**, and **object-oriented design patterns**.

## 📋 Table of Contents

- [Overview](#-overview)
- [Learning Objectives](#-learning-objectives)
- [Exercises](#-exercises)
- [Compilation](#-compilation)
- [Key Concepts](#-key-concepts)
- [Usage Examples](#-usage-examples)

## 🎯 Overview

This module introduces fundamental Object-Oriented Programming concepts in C++, with a specific focus on:
- **Inheritance hierarchies** and class relationships
- **Constructor/destructor chaining** in derived classes
- **Method overriding** and specialization
- **Multiple inheritance** and the diamond problem
- **Virtual inheritance** for complex class hierarchies

## 🎓 Learning Objectives

By completing this module, you will understand:

- How to implement inheritance relationships between classes
- Constructor and destructor calling order in inheritance
- Method overriding and polymorphic behavior
- Access control in inheritance (public, protected, private)
- Multiple inheritance challenges and virtual inheritance solutions
- Orthodox Canonical Form in inheritance hierarchies

## 📁 Exercises

### Exercise 00: Aaaaand... OPEN!
**Files:** `ClapTrap.hpp`, `ClapTrap.cpp`, `main.cpp`, `Makefile`

Implementation of the base ClapTrap class with combat mechanics:
- Private attributes: name, hit points (10), energy points (10), attack damage (0)
- Public methods: attack(), takeDamage(), beRepaired()
- Orthodox Canonical Form compliance
- Constructor/destructor messaging

**Key Features:**
- Basic combat system with energy management
- Health and damage tracking
- Informative action messages

### Exercise 01: Serena, my love!
**Files:** Previous files + `ScavTrap.hpp`, `ScavTrap.cpp`

ScavTrap class inheriting from ClapTrap with enhanced capabilities:
- Enhanced stats: 100 HP, 50 Energy, 20 Attack damage
- Overridden attack() method with unique messaging
- Special ability: guardGate() - Gate keeper mode
- Proper construction/destruction chaining demonstration

**Key Features:**
- Single inheritance implementation
- Constructor delegation and chaining
- Method overriding with specialized behavior
- Unique special abilities

### Exercise 02: Repetitive work
**Files:** Previous files + `FragTrap.hpp`, `FragTrap.cpp`

FragTrap class as another ClapTrap derivative with different specialization:
- High-energy build: 100 HP, 100 Energy, 30 Attack damage
- Unique construction/destruction messages
- Special ability: highFivesGuys() - Positive interaction request
- Parallel inheritance demonstration

**Key Features:**
- Multiple derived classes from same base
- Different attribute initialization per class
- Specialized behaviors and messaging
- Independent inheritance paths

### Exercise 03: Now it's weird!
**Files:** Previous files + `DiamondTrap.hpp`, `DiamondTrap.cpp`

DiamondTrap implementing multiple inheritance from both ScavTrap and FragTrap:
- Inherits from both FragTrap AND ScavTrap
- Mixed attribute inheritance: HP (FragTrap), Energy (ScavTrap), Attack (FragTrap)
- Method inheritance: attack() from ScavTrap
- Special ability: whoAmI() - Identity display
- Virtual inheritance to solve diamond problem

**Key Features:**
- Multiple inheritance implementation
- Diamond problem resolution with virtual inheritance
- Attribute selection from different parents
- Complex constructor chaining
- Name shadowing management

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

### Inheritance Hierarchy
- **Base Class:** ClapTrap provides core functionality
- **Derived Classes:** ScavTrap and FragTrap extend base capabilities
- **Multiple Inheritance:** DiamondTrap combines multiple parents
- **Virtual Inheritance:** Resolves diamond problem ambiguity

### Constructor/Destructor Chaining
1. **Construction Order:** Base class constructor called first
2. **Destruction Order:** Derived class destructor called first
3. **Initialization:** Derived classes must initialize base class
4. **Cleanup:** Proper resource management through the chain

### Method Overriding
- **Virtual Functions:** Enable polymorphic behavior
- **Override Mechanism:** Derived classes provide specialized implementations
- **Access Control:** Public, protected, and private inheritance
- **Name Resolution:** Scope resolution for specific method calls

### Orthodox Canonical Form in Inheritance
Every class implements:
1. **Default Constructor** - May delegate to base class
2. **Copy Constructor** - Must handle base class copying
3. **Copy Assignment Operator** - Assign base and derived parts
4. **Destructor** - Virtual when inheritance is involved

## 💡 Usage Examples

### Exercise 00 - Basic ClapTrap
```cpp
ClapTrap clap("CT-001");

clap.attack("target");      // CT-001 attacks target, causing 0 points of damage!
clap.takeDamage(5);         // CT-001 takes 5 points of damage!
clap.beRepaired(3);         // CT-001 is repaired for 3 hit points!
```

### Exercise 01 - ScavTrap Inheritance
```cpp
ScavTrap scav("ST-002");

scav.attack("enemy");       // ST-002 attacks enemy, causing 20 points of damage!
scav.guardGate();          // ScavTrap ST-002 is now in Gate keeper mode!
// Construction: ClapTrap constructor -> ScavTrap constructor
// Destruction: ScavTrap destructor -> ClapTrap destructor
```

### Exercise 02 - FragTrap Specialization
```cpp
FragTrap frag("FT-003");

frag.attack("target");      // FT-003 attacks target, causing 30 points of damage!
frag.highFivesGuys();      // FragTrap FT-003 requests a high five!
```

### Exercise 03 - Multiple Inheritance
```cpp
DiamondTrap diamond("DT-004");

diamond.attack("enemy");    // Uses ScavTrap's attack method
diamond.whoAmI();          // Displays both DiamondTrap and ClapTrap names
// HP: 100 (FragTrap), Energy: 50 (ScavTrap), Attack: 30 (FragTrap)
```

## 📚 Technical Notes

### Virtual Inheritance
```cpp
class ScavTrap : virtual public ClapTrap { /* ... */ };
class FragTrap : virtual public ClapTrap { /* ... */ };
class DiamondTrap : public ScavTrap, public FragTrap { /* ... */ };
```

### Diamond Problem Resolution
- **Issue:** Multiple inheritance paths to same base class
- **Solution:** Virtual inheritance ensures single base instance
- **Result:** Unambiguous member access and single construction

### Access Specifiers in Inheritance
- **Public Inheritance:** "is-a" relationship, maintains access levels
- **Protected Inheritance:** More restrictive access to inherited members
- **Private Inheritance:** "implemented-in-terms-of" relationship

## 🚀 Advanced Features

- **Polymorphism:** Virtual functions enable runtime method selection
- **Constructor Delegation:** Efficient initialization through inheritance chain
- **Virtual Destructors:** Proper cleanup in polymorphic hierarchies
- **Name Resolution:** Scope resolution operator for specific method calls
- **Memory Layout:** Understanding object memory organization in inheritance

## ⚠️ Common Pitfalls

- **Slicing Problem:** Copying derived objects to base class variables
- **Virtual Destructor:** Required when deleting through base class pointers
- **Constructor Order:** Base class must be initialized before derived class
- **Diamond Problem:** Resolved with virtual inheritance, not regular inheritance

---

*This module serves as a foundation for understanding advanced C++ concepts including virtual functions, abstract classes, and template specialization covered in subsequent modules.*
