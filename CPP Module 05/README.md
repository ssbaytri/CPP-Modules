# C++ Module 05 - Repetition and Exceptions

This repository contains the implementation of C++ Module 05 exercises from the 42 curriculum, focusing on **exception handling**, **try-catch blocks**, **custom exceptions**, **abstract classes**, and **form-based bureaucratic simulation**.

## 📋 Table of Contents

- [Overview](#-overview)
- [Learning Objectives](#-learning-objectives)
- [Exercises](#-exercises)
- [Compilation](#-compilation)
- [Key Concepts](#-key-concepts)
- [Usage Examples](#-usage-examples)

## 🎯 Overview

This module introduces exception handling mechanisms in C++, with a specific focus on:
- **Custom exception classes** inheriting from std::exception
- **Try-catch blocks** for error handling
- **Exception safety** and proper resource management
- **Abstract base classes** with pure virtual functions
- **Factory patterns** for object creation
- **Grade-based permission systems** implementation

## 🎓 Learning Objectives

By completing this module, you will understand:

- How to create and throw custom exceptions
- Proper exception handling with try-catch blocks
- Exception class hierarchies and std::exception inheritance
- Abstract classes with pure virtual functions
- Form validation and execution systems
- Factory pattern implementation
- Grade-based permission checking
- Const correctness in exception handling

## 📁 Exercises

### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
**Files:** `Bureaucrat.hpp`, `Bureaucrat.cpp`, `main.cpp`, `Makefile`

Implementation of a Bureaucrat class with grade management and exceptions:
- Constant name attribute
- Grade system (1 = highest, 150 = lowest)
- Grade increment/decrement with bounds checking
- Custom exception classes (GradeTooHighException, GradeTooLowException)
- Exception throwing in constructors
- Proper getter methods and insertion operator overload

**Key Features:**
- Custom exception implementation
- Constructor validation with exceptions
- Grade manipulation with boundary checking
- Exception inheritance from std::exception
- Proper const correctness

### Exercise 01: Form up, maggots!
**Files:** Previous files + `Form.hpp`, `Form.cpp`

Form class implementation with signing requirements:
- Constant form name and grade requirements
- Boolean signed status tracking
- Two-tier grade system (sign grade and execute grade)
- Form signing with bureaucrat permission checking
- beSigned() method for form signing
- signForm() method in Bureaucrat class with try-catch
- Comprehensive form information display

**Key Features:**
- Multi-attribute const management
- Permission-based form signing
- Exception handling in member functions
- Bureaucrat-Form interaction
- Detailed error messaging

### Exercise 02: No, you need form 28B, not 28C...
**Files:** `Makefile`, `main.cpp`, `Bureaucrat.[hpp,cpp]`, `AForm.[hpp,cpp]`, `ShrubberyCreationForm.[hpp,cpp]`, `RobotomyRequestForm.[hpp,cpp]`, `PresidentialPardonForm.[hpp,cpp]`

Abstract form implementation with concrete form types:
- AForm abstract base class with pure virtual execute()
- Three concrete form implementations:
  - **ShrubberyCreationForm** (sign: 145, exec: 137): Creates ASCII tree files
  - **RobotomyRequestForm** (sign: 72, exec: 45): 50% success robotomy simulation
  - **PresidentialPardonForm** (sign: 25, exec: 5): Presidential pardon message
- Form execution with double validation (signed + grade check)
- Target-based form initialization
- File creation and random number generation
- executeForm() method in Bureaucrat class

**Key Features:**
- Abstract class design with pure virtual functions
- Concrete class implementation with specific behaviors
- File I/O operations (ShrubberyCreationForm)
- Random outcome generation (RobotomyRequestForm)
- Target-based form execution
- Two-stage permission system (sign vs execute)

### Exercise 03: At least this beats coffee-making
**Files:** Previous exercise files + `Intern.hpp`, `Intern.cpp`

Intern factory class for form creation:
- Intern class with makeForm() factory method
- String-based form type identification
- Dynamic form creation and pointer return
- Clean implementation avoiding excessive if-else chains
- Form name mapping to concrete types
- Error handling for unknown form types
- Memory-efficient form instantiation

**Key Features:**
- Factory pattern implementation
- String-to-object mapping
- Elegant solution avoiding code duplication
- Dynamic memory allocation
- Form creation abstraction
- Clean, maintainable design

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
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o bureaucrat
```

## 🔑 Key Concepts

### Exception Handling
- **Custom Exceptions:** Classes inheriting from std::exception
- **what() Method:** Returns descriptive error message
- **throw Keyword:** Raises exceptions
- **try-catch Blocks:** Exception handling mechanism
- **Exception Specification:** `throw()` notation in C++98
- **Stack Unwinding:** Automatic cleanup when exceptions occur

### Exception Class Design
```cpp
class CustomException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Custom error message";
    }
};
```

### Grade System Logic
- **Grade 1:** Highest possible grade (most powerful)
- **Grade 150:** Lowest possible grade (least powerful)
- **Increment:** Improves grade (decreases number: 3 → 2)
- **Decrement:** Worsens grade (increases number: 2 → 3)
- **Comparison:** Lower number = higher authority

### Abstract Classes and Pure Virtual Functions
- **Pure Virtual Function:** `virtual void execute() const = 0;`
- **Abstract Class:** Cannot be instantiated
- **Concrete Classes:** Must implement all pure virtual functions
- **Polymorphism:** Base class pointers to derived objects

### Factory Pattern
- **Abstraction:** Hide object creation complexity
- **Flexibility:** Easy addition of new types
- **Encapsulation:** Centralized creation logic
- **Polymorphism:** Return base class pointers

## 💡 Usage Examples

### Exercise 00 - Basic Bureaucrat with Exceptions
```cpp
try {
    Bureaucrat bob("Bob", 2);
    std::cout << bob << std::endl;
    
    bob.incrementGrade();  // Grade becomes 1
    std::cout << bob << std::endl;
    
    bob.incrementGrade();  // Throws GradeTooHighException
}
catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
}
```

### Exercise 01 - Form Signing
```cpp
try {
    Form contract("Contract", 50, 25);
    Bureaucrat boss("Boss", 30);
    Bureaucrat intern("Intern", 100);
    
    boss.signForm(contract);    // Success: Boss signed Contract
    intern.signForm(contract);  // Failure: grade too low
}
catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
}
```

### Exercise 02 - Form Execution
```cpp
try {
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");
    
    Bureaucrat ceo("CEO", 1);
    
    // Sign all forms
    ceo.signForm(shrub);
    ceo.signForm(robot);
    ceo.signForm(pardon);
    
    // Execute all forms
    ceo.executeForm(shrub);    // Creates garden_shrubbery file
    ceo.executeForm(robot);    // 50% chance of success
    ceo.executeForm(pardon);   // Arthur has been pardoned
}
catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
}
```

### Exercise 03 - Intern Factory
```cpp
Intern someRandomIntern;
AForm* rrf;

rrf = someRandomIntern.makeForm("robotomy request", "Bender");
// Output: Intern creates robotomy request

if (rrf) {
    Bureaucrat boss("Boss", 1);
    boss.signForm(*rrf);
    boss.executeForm(*rrf);
    delete rrf;  // Cleanup
}

// Invalid form name
AForm* invalid = someRandomIntern.makeForm("unknown form", "target");
// Output: Error: Unknown form type
```

## 📚 Technical Notes

### Custom Exception Implementation
```cpp
class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low!";
        }
    };
};
```

### Abstract Form Base Class
```cpp
class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExec;
    const std::string _target;

public:
    // Pure virtual function makes class abstract
    virtual void execute(Bureaucrat const & executor) const = 0;
    
    // Regular virtual function
    virtual ~AForm() {}
    
    void beSigned(const Bureaucrat& bureaucrat);
};
```

### Concrete Form Implementation
```cpp
class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string& target)
        : AForm("Shrubbery Creation", 145, 137, target) {}
    
    void execute(Bureaucrat const & executor) const {
        // Validation checks
        if (!isSigned())
            throw FormNotSignedException();
        if (executor.getGrade() > getGradeToExec())
            throw GradeTooLowException();
        
        // Action: create file with ASCII trees
        std::ofstream file((getTarget() + "_shrubbery").c_str());
        file << "ASCII trees here" << std::endl;
        file.close();
    }
};
```

### Factory Pattern Implementation
```cpp
class Intern {
public:
    AForm* makeForm(std::string formName, std::string target) {
        std::string forms[3] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon"
        };
        
        // Function pointer array for form creation
        AForm* (*creators[3])(std::string) = {
            &createShrubbery,
            &createRobotomy,
            &createPardon
        };
        
        for (int i = 0; i < 3; i++) {
            if (formName == forms[i]) {
                std::cout << "Intern creates " << formName << std::endl;
                return creators[i](target);
            }
        }
        
        std::cout << "Error: Form type '" << formName << "' does not exist" << std::endl;
        return NULL;
    }

private:
    static AForm* createShrubbery(std::string target) {
        return new ShrubberyCreationForm(target);
    }
    
    static AForm* createRobotomy(std::string target) {
        return new RobotomyRequestForm(target);
    }
    
    static AForm* createPardon(std::string target) {
        return new PresidentialPardonForm(target);
    }
};
```

## 🚀 Advanced Features

- **Nested Exception Classes:** Exception classes defined within their parent class
- **Virtual Destructors:** Proper cleanup in polymorphic hierarchies
- **Const Correctness:** Proper use of const in getters and methods
- **Exception Safety:** Strong exception guarantee in operations
- **Factory Method Pattern:** Encapsulated object creation logic
- **Two-Tier Permission System:** Separate sign and execute permissions
- **File I/O with Exceptions:** Safe file handling with error checking
- **Random Generation:** Pseudo-random outcomes for robotomy

## ⚠️ Common Pitfalls

- **Missing Virtual Destructor:** Memory leaks with polymorphic deletion
- **Exception Specification:** Using `throw()` correctly in C++98
- **Grade Logic Confusion:** Remembering 1 is highest, 150 is lowest
- **Increment/Decrement Logic:** Increment decreases number, decrement increases
- **Form Not Signed:** Attempting to execute unsigned forms
- **Insufficient Permissions:** Trying to sign/execute without proper grade
- **Memory Leaks:** Forgetting to delete dynamically created forms
- **Copy Assignment with Const:** Cannot reassign const members

## 🎯 Design Patterns Demonstrated

- **Factory Method:** Intern creates forms without exposing creation logic
- **Template Method:** AForm defines execution framework, concrete classes implement specifics
- **Strategy Pattern:** Different form types with common interface
- **Exception Handling Pattern:** Consistent error handling throughout hierarchy
- **Two-Phase Construction:** Sign then execute workflow
- **Validation Pattern:** Pre-condition checking before operations

## 📊 Grade Requirements Summary

| Form Type | Sign Grade | Execute Grade | Action |
|-----------|-----------|--------------|---------|
| ShrubberyCreationForm | 145 | 137 | Creates ASCII tree file |
| RobotomyRequestForm | 72 | 45 | Robotomizes target (50% success) |
| PresidentialPardonForm | 25 | 5 | Grants presidential pardon |

## 🔍 Testing Checklist

### Exercise 00
- ✅ Valid bureaucrat creation
- ✅ Grade too high exception (< 1)
- ✅ Grade too low exception (> 150)
- ✅ Increment at boundary (grade 1)
- ✅ Decrement at boundary (grade 150)
- ✅ Copy constructor behavior
- ✅ Assignment operator with const name

### Exercise 01
- ✅ Valid form creation
- ✅ Form grade validation
- ✅ Successful signing
- ✅ Failed signing (grade too low)
- ✅ Exact grade match signing
- ✅ Multiple bureaucrats signing same form

### Exercise 02
- ✅ Abstract class (cannot instantiate AForm)
- ✅ Execute without signing (should fail)
- ✅ Execute with insufficient grade (should fail)
- ✅ Successful execution of all form types
- ✅ File creation for ShrubberyCreationForm
- ✅ Random outcomes for RobotomyRequestForm
- ✅ Message output for PresidentialPardonForm

### Exercise 03
- ✅ Valid form name creation
- ✅ Invalid form name handling
- ✅ All three form types creatable
- ✅ Proper memory management
- ✅ Clean code without excessive if-else
- ✅ Case-sensitive form name matching

## 💻 Memory Management Notes
```cpp
// Always remember to delete dynamically created forms
Intern intern;
AForm* form = intern.makeForm("robotomy request", "Bender");

if (form) {
    // Use the form
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    
    // Clean up
    delete form;
}
```

## 🎓 Learning Progression

This module builds upon:
- **Module 04:** Polymorphism and abstract classes
- **Module 03:** Operator overloading
- **Module 02:** Orthodox Canonical Form
- **Module 01:** Memory allocation and references

And prepares for:
- **Module 06:** C++ casts and type conversion
- **Module 07:** Templates
- **Module 08:** STL containers
- **Module 09:** STL algorithms

---

*This module demonstrates the power of exception handling in creating robust, error-resistant code. The bureaucratic simulation showcases real-world applications of abstract classes, polymorphism, and the factory pattern—concepts essential for modern C++ development and system design.*
