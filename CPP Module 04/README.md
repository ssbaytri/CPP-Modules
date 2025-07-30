# C++ Module 04 - Subtype Polymorphism, Abstract Classes, and Interfaces

This repository contains the implementation of C++ Module 04 exercises from the 42 curriculum, focusing on **polymorphism**, **abstract classes**, **interfaces**, and **advanced object-oriented design patterns**.

## 📋 Table of Contents

- [Overview](#-overview)
- [Learning Objectives](#-learning-objectives)
- [Exercises](#-exercises)
- [Compilation](#-compilation)
- [Key Concepts](#-key-concepts)
- [Usage Examples](#-usage-examples)

## 🎯 Overview

This module introduces advanced Object-Oriented Programming concepts in C++, with a specific focus on:
- **Virtual functions** and runtime polymorphism
- **Abstract base classes** and pure virtual functions
- **Interface implementation** through pure abstract classes
- **Deep vs shallow copying** in inheritance hierarchies
- **Memory management** with polymorphic objects

## 🎓 Learning Objectives

By completing this module, you will understand:

- How to implement virtual functions for runtime polymorphism
- The difference between early and late binding
- How to create abstract classes that cannot be instantiated
- Interface design patterns using pure abstract classes
- Proper memory management with virtual destructors
- Deep copying techniques for complex objects

## 📁 Exercises

### Exercise 00: Polymorphism
**Files:** `Animal.hpp`, `Animal.cpp`, `Dog.hpp`, `Dog.cpp`, `Cat.hpp`, `Cat.cpp`, `WrongAnimal.hpp`, `WrongAnimal.cpp`, `WrongCat.hpp`, `WrongCat.cpp`, `main.cpp`, `Makefile`

Implementation of basic polymorphism with Animal hierarchy:
- Base Animal class with protected type attribute
- Derived Dog and Cat classes with proper type initialization
- Virtual makeSound() method for polymorphic behavior
- WrongAnimal/WrongCat demonstration of non-virtual behavior
- Proper constructor/destructor messaging

**Key Features:**
- Virtual function implementation
- Runtime polymorphism demonstration
- Comparison between virtual and non-virtual behavior
- Type identification system

### Exercise 01: I don't want to set the world on fire
**Files:** Previous files + `Brain.hpp`, `Brain.cpp`

Enhanced Animal hierarchy with Brain composition and deep copying:
- Brain class containing array of 100 std::string ideas
- Dog and Cat classes with private Brain* attribute
- Dynamic memory allocation for Brain objects
- Deep copy implementation for proper object copying
- Virtual destructor ensuring proper cleanup
- Array-based polymorphic object management

**Key Features:**
- Composition with dynamic allocation
- Deep vs shallow copy demonstration
- Virtual destructor implementation
- Memory leak prevention
- Polymorphic array management

### Exercise 02: Abstract class
**Files:** Previous exercise files modified

Abstract Animal class implementation:
- Pure virtual functions making Animal non-instantiable
- Maintained polymorphic behavior in derived classes
- Abstract base class design pattern
- Optional AAnimal naming convention
- All functionality preserved while preventing base class instantiation

**Key Features:**
- Pure virtual function implementation
- Abstract class design
- Prevention of base class instantiation
- Maintained inheritance hierarchy functionality

### Exercise 03: Interface & recap
**Files:** `AMateria.hpp`, `AMateria.cpp`, `Ice.hpp`, `Ice.cpp`, `Cure.hpp`, `Cure.cpp`, `ICharacter.hpp`, `Character.hpp`, `Character.cpp`, `IMateriaSource.hpp`, `MateriaSource.hpp`, `MateriaSource.cpp`, `main.cpp`, `Makefile`

Complex interface implementation with Materia system:
- AMateria abstract base class with pure virtual clone()
- Concrete Ice and Cure Materia implementations
- ICharacter interface for character management
- Character class with 4-slot Materia inventory
- IMateriaSource interface for Materia creation
- MateriaSource class for Materia template management
- Complex interaction system between all components

**Key Features:**
- Multiple interface implementations
- Factory pattern with MateriaSource
- Inventory management system
- Clone pattern implementation
- Complex object interaction design
- Memory management in interface hierarchies

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

### Polymorphism Types
- **Runtime Polymorphism:** Virtual functions enable method selection at runtime
- **Compile-time Polymorphism:** Function overloading and templates
- **Subtype Polymorphism:** Derived classes can be treated as base class instances
- **Virtual Function Table:** Mechanism enabling dynamic dispatch

### Abstract Classes and Interfaces
- **Abstract Class:** Contains at least one pure virtual function
- **Pure Virtual Function:** `virtual function() = 0;` makes class abstract
- **Interface:** Pure abstract class with only pure virtual functions
- **Implementation:** Concrete classes must implement all pure virtual functions

### Virtual Functions and Destructors
- **Virtual Functions:** Enable polymorphic behavior through dynamic binding
- **Virtual Destructors:** Essential for proper cleanup in inheritance hierarchies
- **Override:** Derived classes provide specific implementations
- **Late Binding:** Runtime method resolution based on object type

### Memory Management
- **Deep Copy:** Complete duplication including dynamically allocated members
- **Shallow Copy:** Copying pointers without duplicating pointed-to objects
- **Virtual Destructors:** Ensure proper destruction order in polymorphic hierarchies
- **RAII:** Resource Acquisition Is Initialization principle

## 💡 Usage Examples

### Exercise 00 - Basic Polymorphism
```cpp
const Animal* animals[2];
animals[0] = new Dog();
animals[1] = new Cat();

for (int i = 0; i < 2; i++) {
    animals[i]->makeSound();  // Calls correct derived method
    delete animals[i];        // Proper cleanup with virtual destructor
}
```

### Exercise 01 - Deep Copying with Brain
```cpp
Dog* original = new Dog();
Dog* copy = new Dog(*original);  // Deep copy with separate Brain

// Both dogs have independent Brain objects
delete original;  // copy's Brain remains valid
delete copy;      // No memory leaks
```

### Exercise 02 - Abstract Classes
```cpp
// Animal* animal = new Animal();  // Error: cannot instantiate abstract class
Animal* dog = new Dog();           // OK: Dog implements all pure virtuals
dog->makeSound();                  // Polymorphic call to Dog::makeSound()
delete dog;                        // Virtual destructor ensures proper cleanup
```

### Exercise 03 - Interface Implementation
```cpp
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());

ICharacter* character = new Character("hero");
AMateria* ice = src->createMateria("ice");
character->equip(ice);

ICharacter* target = new Character("enemy");
character->use(0, *target);  // * shoots an ice bolt at enemy *

delete target;
delete character;
delete src;
```

## 📚 Technical Notes

### Virtual Function Implementation
```cpp
class Base {
public:
    virtual ~Base() {}                    // Virtual destructor
    virtual void method() = 0;            // Pure virtual function
    virtual void overridable() {}         // Virtual function with default
};

class Derived : public Base {
public:
    void method() override {}             // Must implement pure virtual
    void overridable() override {}        // Optional override
};
```

### Interface Design Pattern
```cpp
class IInterface {
public:
    virtual ~IInterface() {}
    virtual void method1() = 0;
    virtual void method2() = 0;
};

class Implementation : public IInterface {
public:
    void method1() override { /* implementation */ }
    void method2() override { /* implementation */ }
};
```

### Deep Copy Implementation
```cpp
class DeepCopyClass {
private:
    Resource* resource;
public:
    DeepCopyClass(const DeepCopyClass& other) {
        resource = new Resource(*other.resource);  // Deep copy
    }
    
    DeepCopyClass& operator=(const DeepCopyClass& other) {
        if (this != &other) {
            delete resource;                       // Clean up old resource
            resource = new Resource(*other.resource);  // Deep copy
        }
        return *this;
    }
};
```

## 🚀 Advanced Features

- **Virtual Function Tables (vtables):** Runtime method dispatch mechanism
- **Pure Virtual Destructors:** Advanced abstract class techniques
- **Multiple Inheritance with Interfaces:** Complex hierarchy management
- **Factory Patterns:** Object creation through interfaces
- **Clone Patterns:** Object duplication through virtual methods
- **RAII with Polymorphism:** Resource management in inheritance hierarchies

## ⚠️ Common Pitfalls

- **Missing Virtual Destructors:** Memory leaks when deleting through base pointers
- **Shallow Copy Issues:** Shared resources leading to double deletion
- **Abstract Class Instantiation:** Compile-time errors with pure virtual functions
- **Slicing:** Loss of derived class information when copying to base class
- **Memory Leaks:** Improper cleanup in complex object hierarchies

## 🎯 Design Patterns Demonstrated

- **Template Method:** Abstract base with concrete and abstract methods
- **Factory Method:** MateriaSource creates Materia objects
- **Clone Pattern:** AMateria::clone() for object duplication
- **Strategy Pattern:** Different Materia types with common interface
- **Composite Pattern:** Character managing collection of Materia objects

---

*This module serves as a bridge to advanced C++ concepts including templates, STL containers, and advanced design patterns covered in subsequent modules. The understanding of polymorphism and interfaces developed here is crucial for modern C++ development.*
