# C++ Module 06 - C++ Casts

This repository contains the implementation of C++ Module 06 exercises from the 42 curriculum, focusing on **type casting**, **type conversion**, **serialization**, and **runtime type identification** in C++98.

## 📋 Table of Contents

- [Overview](#-overview)
- [Learning Objectives](#-learning-objectives)
- [Exercises](#-exercises)
- [Compilation](#-compilation)
- [Key Concepts](#-key-concepts)
- [Usage Examples](#-usage-examples)

## 🎯 Overview

This module introduces the different types of C++ casts and their proper usage:
- **Static cast** for compile-time type conversions
- **Reinterpret cast** for low-level pointer/reference reinterpretation
- **Dynamic cast** for safe runtime type identification
- **Const cast** for adding/removing const qualifiers (not used in these exercises)
- **Type detection** and conversion from string literals
- **Serialization** concepts and pointer manipulation
- **Runtime type identification** without RTTI

## 🎓 Learning Objectives

By completing this module, you will understand:

- The four types of C++ casts and when to use each
- How to detect and convert between scalar types
- String parsing and literal type identification
- Serialization and deserialization concepts
- Pointer-to-integer conversions using `reinterpret_cast`
- Runtime type identification using `dynamic_cast`
- Polymorphism and virtual functions
- Exception handling with references vs pointers
- Proper use of special floating-point values (nan, inf)

## 📁 Exercises

### Exercise 00: Conversion of scalar types
**Files:** `ScalarConverter.hpp`, `ScalarConverter.cpp`, `main.cpp`, `Makefile`

Implementation of a ScalarConverter class for converting string literals to scalar types:
- Static-only class (non-instantiable)
- Single static method: `convert(const std::string& literal)`
- Detects input type: char, int, float, or double
- Converts to all four scalar types and displays results
- Handles special values: `nan`, `inf`, `-inf`, `+inf` (with 'f' suffix for floats)
- Proper error handling for impossible conversions and overflows
- Character displayability checking
- Precision formatting for float and double output

**Key Features:**
- Type detection from string format
- Static casting for type conversions
- Special floating-point value handling
- ASCII range validation for char type
- Overflow detection and reporting
- Proper formatting with decimal precision

**Example Usage:**
```bash
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

### Exercise 01: Serialization
**Files:** `Serializer.hpp`, `Serializer.cpp`, `Data.hpp`, `main.cpp`, `Makefile`

Serializer class for pointer-to-integer conversion:
- Static-only class (non-instantiable)
- `serialize(Data* ptr)`: Converts pointer to `uintptr_t`
- `deserialize(uintptr_t raw)`: Converts `uintptr_t` back to pointer
- Non-empty Data structure with member variables
- Demonstrates `reinterpret_cast` usage
- Validates pointer equality after round-trip conversion
- Understanding of memory addresses as integers

**Key Features:**
- Reinterpret casting between pointer and integer types
- `uintptr_t` type for platform-independent pointer storage
- Pointer serialization concept demonstration
- Memory address manipulation
- Type-safe pointer reconstruction

**Example Usage:**
```cpp
Data* original = new Data;
original->id = 42;
original->name = "Alice";
original->value = 3.14f;

uintptr_t serialized = Serializer::serialize(original);
Data* deserialized = Serializer::deserialize(serialized);

// deserialized == original (same memory address)
```

### Exercise 02: Identify real type
**Files:** `Base.hpp`, `Base.cpp`, `A.hpp`, `A.cpp`, `B.hpp`, `B.cpp`, `C.hpp`, `C.cpp`, `functions.hpp`, `functions.cpp`, `main.cpp`, `Makefile`

Runtime type identification without `<typeinfo>` header:
- Base class with only public virtual destructor
- Three empty derived classes: A, B, and C
- `generate()`: Randomly instantiates A, B, or C, returns as Base*
- `identify(Base* p)`: Identifies type using pointer and `dynamic_cast`
- `identify(Base& p)`: Identifies type using reference (no pointers allowed inside)
- Exception-based type checking with references
- Random object generation for testing

**Key Features:**
- Dynamic cast with pointers (returns NULL on failure)
- Dynamic cast with references (throws exception on failure)
- Exception handling with `catch(...)`
- Polymorphism and virtual functions
- Runtime type checking without RTTI
- Random number generation for object creation

**Example Usage:**
```cpp
Base* obj = generate();  // Randomly creates A, B, or C

identify(obj);   // Prints: A, B, or C (using pointer)
identify(*obj);  // Prints: A, B, or C (using reference)

delete obj;
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
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o convert
```

## 🔑 Key Concepts

### The Four C++ Casts

#### 1. Static Cast
**Usage:** Safe, compile-time conversions between related types
```cpp
int i = 42;
float f = static_cast<float>(i);  // int to float
char c = static_cast<char>(i);    // int to char
```
**When to use:**
- Converting between numeric types
- Upcasting in inheritance hierarchies
- Explicit conversions that are semantically safe

#### 2. Reinterpret Cast
**Usage:** Low-level reinterpretation of bit patterns
```cpp
Data* ptr = new Data;
uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);  // pointer to int
Data* ptr2 = reinterpret_cast<Data*>(addr);         // int to pointer
```
**When to use:**
- Converting between pointer and integer types
- Low-level memory manipulation
- Platform-specific conversions
**Warning:** Dangerous! No type safety checks.

#### 3. Dynamic Cast
**Usage:** Safe runtime downcasting with type checking
```cpp
Base* base = new Derived;
Derived* derived = dynamic_cast<Derived*>(base);  // Returns NULL if fails
if (derived != NULL) {
    // Successful cast
}

// With references (throws exception on failure)
try {
    Derived& ref = dynamic_cast<Derived&>(baseRef);
} catch (...) {
    // Cast failed
}
```
**When to use:**
- Downcasting in inheritance hierarchies
- Runtime type checking
- When you need to verify type before using

#### 4. Const Cast
**Usage:** Add or remove const/volatile qualifiers
```cpp
const int* cptr = &value;
int* ptr = const_cast<int*>(cptr);  // Remove const
```
**When to use:** Rarely! Usually indicates design problems.

### Type Detection Strategy

For Exercise 00, type detection order matters:
1. **Char literal:** Single printable non-digit character
2. **Int literal:** Optional sign + digits only
3. **Float literal:** Digits with decimal point + 'f' suffix
4. **Double literal:** Digits with decimal point, no 'f' suffix
5. **Pseudo-literals:** Special values like `nan`, `inf`, etc.

### Serialization vs This Exercise

**Real Serialization:**
```cpp
// Convert object data to storable format
Data obj = {42, "Alice", 3.14};
std::string json = "{\"id\":42,\"name\":\"Alice\",\"value\":3.14}";
// Can save, transmit, restore on different machine
```

**Exercise 01 "Serialization":**
```cpp
// Just converts pointer to integer representation
Data* ptr = new Data;
uintptr_t num = reinterpret_cast<uintptr_t>(ptr);
// Only valid within same program/process/memory space
```

This exercise teaches `reinterpret_cast`, not true serialization.

### Dynamic Cast Behavior

**With Pointers:**
```cpp
Base* ptr = new A;
A* aPtr = dynamic_cast<A*>(ptr);  // Returns valid pointer
B* bPtr = dynamic_cast<B*>(ptr);  // Returns NULL (failed cast)

if (bPtr == NULL) {
    // Cast failed
}
```

**With References:**
```cpp
Base& ref = *new A;
try {
    A& aRef = dynamic_cast<A&>(ref);  // Success
} catch (...) {
    // Won't reach here
}

try {
    B& bRef = dynamic_cast<B&>(ref);  // Throws std::bad_cast
} catch (...) {
    // Caught here - cast failed
}
```

## 💡 Usage Examples

### Exercise 00 - Scalar Conversion

**Input Types:**
```bash
# Character
./convert a
char: 'a'
int: 97
float: 97.0f
double: 97.0

# Integer
./convert 42
char: '*'
int: 42
float: 42.0f
double: 42.0

# Float
./convert 4.2f
char: Non displayable
int: 4
float: 4.2f
double: 4.2

# Double
./convert 4.2
char: Non displayable
int: 4
float: 4.2f
double: 4.2

# Special values
./convert nanf
char: impossible
int: impossible
float: nanf
double: nan

./convert +inff
char: impossible
int: impossible
float: +inff
double: +inf
```

**Edge Cases:**
```bash
# Non-displayable character (ASCII < 32 or > 126)
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

# Overflow
./convert 999999999999
char: impossible
int: impossible
float: 9.99999e+11f
double: 9.99999e+11
```

### Exercise 01 - Serialization

```cpp
#include "Serializer.hpp"

int main() {
    // Create and populate data
    Data* original = new Data;
    original->id = 42;
    original->name = "Alice";
    original->value = 3.14f;
    
    std::cout << "Original pointer: " << original << std::endl;
    
    // Serialize (pointer → integer)
    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    // Deserialize (integer → pointer)
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    
    // Verify equality
    if (deserialized == original) {
        std::cout << "✅ Pointers are equal!" << std::endl;
        std::cout << "Data matches: " << deserialized->name << std::endl;
    }
    
    delete original;
    return 0;
}
```

**Output:**
```
Original pointer: 0x7fff5fbff8a0
Serialized value: 140734799803552
Deserialized pointer: 0x7fff5fbff8a0
✅ Pointers are equal!
Data matches: Alice
```

### Exercise 02 - Type Identification

```cpp
#include "functions.hpp"

int main() {
    // Random generation and identification
    Base* random = generate();  // Creates A, B, or C randomly
    
    std::cout << "Identify with pointer: ";
    identify(random);  // Output: A, B, or C
    
    std::cout << "Identify with reference: ";
    identify(*random);  // Output: A, B, or C
    
    delete random;
    
    // Manual testing
    Base* a = new A;
    Base* b = new B;
    Base* c = new C;
    
    identify(a);  // Output: A
    identify(b);  // Output: B
    identify(c);  // Output: C
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}
```

## 📚 Technical Notes

### Exercise 00 - Type Detection Implementation

```cpp
bool ScalarConverter::isCharLiteral(const std::string& str) {
    // Single printable character (not a digit)
    if (str.length() != 1)
        return false;
    if (!std::isprint(str[0]))
        return false;
    if (std::isdigit(str[0]))
        return false;
    return true;
}

bool ScalarConverter::isIntLiteral(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t i = 0;
    // Optional sign
    if (str[i] == '+' || str[i] == '-') {
        i++;
        if (i >= str.length())
            return false;
    }
    
    // All remaining must be digits
    while (i < str.length()) {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloatLiteral(const std::string& str) {
    // Check pseudo-literals
    if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return true;
    
    // Must end with 'f'
    if (str.empty() || str[str.length() - 1] != 'f')
        return false;
    
    // Validate numeric part with decimal point
    std::string core = str.substr(0, str.length() - 1);
    // ... validation logic for digits and single decimal point
}
```

### Exercise 00 - Conversion and Display

```cpp
void ScalarConverter::printFromInt(int i) {
    // Char conversion
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (i < 32 || i == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    
    // Int display
    std::cout << "int: " << i << std::endl;
    
    // Float conversion with formatting
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(i) << "f" << std::endl;
    
    // Double conversion with formatting
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(i) << std::endl;
}
```

### Exercise 01 - Serialization Implementation

```cpp
class Serializer {
private:
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }
    
    static Data* deserialize(uintptr_t raw) {
        return reinterpret_cast<Data*>(raw);
    }
};
```

**Data Structure:**
```cpp
struct Data {
    int id;
    std::string name;
    float value;
};
```

### Exercise 02 - Dynamic Cast with Pointers

```cpp
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
```

**How it works:**
- `dynamic_cast<A*>(p)` returns valid pointer if `p` points to an `A` object
- Returns `NULL` if cast fails
- Check result in if-condition (NULL = false, valid pointer = true)

### Exercise 02 - Dynamic Cast with References

```cpp
void identify(Base& p) {
    // Try casting to A
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}
    
    // Try casting to B
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}
    
    // Must be C
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
}
```

**How it works:**
- `dynamic_cast<A&>(p)` throws `std::bad_cast` if cast fails
- Use `catch(...)` to catch any exception (avoids `<typeinfo>` header)
- `(void)` cast silences "unused variable" warnings
- Try each type until one succeeds

### Random Generation

```cpp
Base* generate(void) {
    std::srand(std::time(0));
    int random = std::rand() % 3;
    
    switch(random) {
        case 0: return new A;
        case 1: return new B;
        default: return new C;
    }
}
```

## 🚀 Advanced Features

### Special Floating-Point Values

```cpp
// Creating special values
float nanf = std::numeric_limits<float>::quiet_NaN();
float inf = std::numeric_limits<float>::infinity();
float ninf = -std::numeric_limits<float>::infinity();

// Checking special values
if (std::isnan(f))
    std::cout << "nanf" << std::endl;
else if (std::isinf(f))
    std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
```

### Precision Formatting

```cpp
// Always show at least one decimal place
std::cout << std::fixed << std::setprecision(1);
std::cout << 42.0f << "f" << std::endl;  // Output: 42.0f
std::cout << 42.123f << "f" << std::endl;  // Output: 42.1f
```

### C++98 Compatibility Notes

**Avoid C++11 features:**
```cpp
// ❌ C++11
str.back()  // Use str[str.length() - 1]

// ❌ C++11
nullptr  // Use NULL

// ❌ C++11
auto var = value;  // Declare explicit types

// ✅ C++98
str[str.length() - 1]
NULL
explicit type declarations
```

## ⚠️ Common Pitfalls

### Exercise 00
- **Forgetting 'f' suffix:** Float output must have 'f': `42.0f` not `42.0`
- **Wrong decimal precision:** Always show at least one decimal place
- **Character range errors:** Valid displayable chars are ASCII 32-126
- **Pseudo-literal detection:** Check these before parsing as regular numbers
- **C++11 methods:** Don't use `.back()`, use `[str.length() - 1]`
- **Overflow checking:** Validate int range before casting from long

### Exercise 01
- **Wrong cast type:** Must use `reinterpret_cast`, not `static_cast`
- **Empty Data struct:** Subject requires non-empty structure
- **Memory leaks:** Remember to delete dynamically allocated Data objects
- **Platform assumptions:** Use `uintptr_t`, not `unsigned long` or `size_t`

### Exercise 02
- **Including `<typeinfo>`:** Forbidden by subject - use `catch(...)` instead
- **Using pointers in reference identify:** The challenge is to avoid pointers entirely
- **Missing virtual destructor:** Base class needs virtual destructor for polymorphism
- **Not checking NULL:** With pointer version, check if cast result is NULL
- **Catching specific exceptions:** Use `catch(...)` not `catch(std::bad_cast&)`
- **Seeding every call:** `srand(time(0))` in `generate()` may cause same values

## 🎯 Design Patterns Demonstrated

### Static Utility Classes
```cpp
class ScalarConverter {
private:
    ScalarConverter();  // Prevent instantiation
    // ...
public:
    static void convert(const std::string& literal);
};

// Usage: ScalarConverter::convert("42");
```

### Type Detection Pattern
```cpp
// Check types in order from most specific to most general
if (isChar(str)) { /* ... */ }
else if (isInt(str)) { /* ... */ }
else if (isFloat(str)) { /* ... */ }
else if (isDouble(str)) { /* ... */ }
else { /* error */ }
```

### Exception-Based Type Identification
```cpp
// Try each type, catch failures silently
try {
    dynamic_cast<SpecificType&>(ref);
    // Success
    return;
} catch (...) {
    // Try next type
}
```

## 📊 Cast Comparison Table

| Cast Type | Safety | Runtime Check | Use Case |
|-----------|--------|---------------|----------|
| `static_cast` | High | No | Related type conversions |
| `dynamic_cast` | High | Yes | Downcasting in hierarchies |
| `reinterpret_cast` | Low | No | Low-level bit reinterpretation |
| `const_cast` | Medium | No | Removing const (rarely needed) |
| C-style cast | Low | No | Avoid in C++ |

## 🔍 Testing Checklist

### Exercise 00
- ✅ Single character input (char)
- ✅ Integer input (positive, negative, zero)
- ✅ Float input with 'f' suffix
- ✅ Double input without 'f' suffix
- ✅ Special float values: `nanf`, `+inff`, `-inff`, `inff`
- ✅ Special double values: `nan`, `+inf`, `-inf`, `inf`
- ✅ Non-displayable characters (ASCII < 32 or = 127)
- ✅ Out-of-range values (overflow testing)
- ✅ Invalid input format
- ✅ Decimal precision (at least .1)

### Exercise 01
- ✅ Basic serialization/deserialization round-trip
- ✅ Pointer equality after deserialization
- ✅ Data integrity after deserialization
- ✅ Multiple serialize/deserialize cycles
- ✅ Different Data values
- ✅ Memory management (no leaks)

### Exercise 02
- ✅ Random generation creates all three types
- ✅ Pointer-based identification for A, B, C
- ✅ Reference-based identification for A, B, C
- ✅ Both identify functions produce same result
- ✅ No use of `<typeinfo>` header
- ✅ No pointers used inside reference identify function
- ✅ Proper memory cleanup

## 💻 Memory Management Notes

```cpp
// Exercise 00: No dynamic allocation needed
ScalarConverter::convert("42");  // Static method, no cleanup

// Exercise 01: Manual cleanup required
Data* ptr = new Data;
// ... use ptr ...
delete ptr;  // Don't forget!

// Exercise 02: Clean up generated objects
Base* obj = generate();
identify(obj);
delete obj;  // Essential - prevent memory leak
```

## 🎓 Learning Progression

This module builds upon:
- **Module 05:** Exception handling and inheritance
- **Module 04:** Polymorphism and virtual functions
- **Module 03:** Operator overloading
- **Module 02:** Orthodox Canonical Form

And prepares for:
- **Module 07:** Templates
- **Module 08:** STL containers
- **Module 09:** STL algorithms

## 📖 Key Takeaways

1. **Choose the right cast:** Each cast type has specific use cases
2. **Static cast for conversions:** Safe compile-time type conversions
3. **Dynamic cast for runtime checks:** Verify types at runtime safely
4. **Reinterpret cast for low-level work:** Dangerous but sometimes necessary
5. **Type detection requires careful parsing:** Order matters in detection logic
6. **Exception handling differs:** Pointers return NULL, references throw exceptions
7. **Special values need special handling:** `nan`, `inf` are valid floating-point values
8. **C++98 compatibility:** Avoid modern C++ features when required

---

*This module demonstrates the power and flexibility of C++'s casting system. Understanding when and how to use each cast type is essential for writing safe, maintainable C++ code. The exercises progress from string parsing and type conversion, through low-level pointer manipulation, to runtime type identification—core skills for any C++ developer*
