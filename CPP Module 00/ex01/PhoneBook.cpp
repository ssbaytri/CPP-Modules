#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : oldestIndex(0), contactCount(0) {}

void PhoneBook::addContact(const Contact& contact) {
	if (contactCount < 8) {
		contacts[contactCount] = contact;
		contactCount++;
	} else {
		contacts[oldestIndex] = contact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
}

std::string PhoneBook::truncateString(const std::string& str, size_t width) const {
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	return str;
}

void PhoneBook::displayContactList() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName(), 10) << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName(), 10) << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickname(), 10) << std::endl;
    }
}

bool PhoneBook::isEmpty() const {
	return contactCount == 0;
}

int PhoneBook::getContactCount() const {
	return contactCount;
}

void PhoneBook::searchContact() const {
	if (isEmpty()) {
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	displayContactList();
	
	std::cout << "Enter the index of the contact you want to display: ";
	int index;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input. Please enter a number." << std::endl;
		return;
	}

	std::cin.ignore(1000, '\n');
	
	if (index < 0 || index >= contactCount) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	displayContact(index);
}

void PhoneBook::displayContact(int index) const {
	if (index >= 0 && index < contactCount) {
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
}
