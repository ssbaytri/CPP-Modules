#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete j;
  delete i;

  // const WrongAnimal *meta = new WrongAnimal();
  // const WrongAnimal *cat = new WrongCat();

  // std::cout << meta->getType() << std::endl;
  // std::cout << cat->getType() << std::endl;

  // meta->makeSound();
  // cat->makeSound();

  // delete meta;
  // delete cat;

  return 0;
}