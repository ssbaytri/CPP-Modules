#include "iter.hpp"

template <typename T>
void print_elem(const T &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void increment(T &elem)
{
	elem += 1;
}


class Person {
private:
    std::string _name;
    int _age;

public:
    Person() : _name("Unknown"), _age(0) {}
    Person(const std::string &name, int age) : _name(name), _age(age) {}

    std::string getName() const { return _name; }
    int getAge() const { return _age; }
};

void printPerson(const Person &p) {
    std::cout << p.getName() << " is " << p.getAge() << " years old." << std::endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    std::string strs[3] = {"hello", "world", "iter"};

    std::cout << "Original int array:" << std::endl;
    iter(arr, 5, print_elem<int>);

    std::cout << "\nIncrementing int array:" << std::endl;
    iter(arr, 5, increment<int>);
    iter(arr, 5, print_elem<int>);

    std::cout << "\nString array:" << std::endl;
    iter(strs, 3, print_elem<std::string>);

	Person people[3] = {
        Person("Alice", 30),
        Person("Bob", 25),
        Person("Charlie", 40)
    };

	std::cout << "\nPeople in the array:" << std::endl;
    iter(people, 3, printPerson);

    return 0;
}