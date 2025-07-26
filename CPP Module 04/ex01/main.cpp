#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  delete j;
  delete i;

  std::cout << "=== Deep copy test ===" << std::endl;
  Dog original;
  Dog copy = original;

  std::cout << "Original brain: " << original.getBrain() << std::endl;
  std::cout << "Copy brain: " << copy.getBrain() << std::endl;

  std::cout << "=== Array test ===" << std::endl;

  Animal* animals[4];

  animals[0] = new Dog();
  animals[1] = new Dog();

  animals[2] = new Cat();
  animals[3] = new Cat();

  animals[0]->makeSound();

  for (int i = 0; i < 4; i++)
    delete animals[i];

  Brain* brain = new Brain();
  brain->printAllIdeas();

  return 0;
}