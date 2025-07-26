#include "Brain.hpp"
#include <iostream>


Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Empty Thought";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called - DEEP COPY!" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called - DEEP COPY!" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "Invalid index";
}

void Brain::printAllIdeas() const
{
	for (int i = 0; i < 10; i++)
		std::cout << "Idea " << i << ": " << ideas[i] << std::endl;
	std::cout << "... (and 90 more ideas)" << std::endl;

}

