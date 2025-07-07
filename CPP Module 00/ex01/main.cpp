#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>

std::string getInput(const std::string& prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
			return input;
		else
			std::cout << "Input cannot be empty. Please try again." << std::endl;
	}
}

bool isValidPhoneNumber(const std::string& phoneNumber)
{
	if (phoneNumber.empty())
		return false;
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if(!std::isdigit(phoneNumber[i]))
			return false;
	}
	return true;
}

std::string getPhoneNumber()
{
	std::string phoneNumber;

	while (true)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, phoneNumber);

		if (isValidPhoneNumber(phoneNumber))
			return phoneNumber;
		else
			std::cout << "Invalid phone number. Please try again." << std::endl;
	}
}

Contact createContact()
{
	Contact contact;

	std::cout << "Enter contact information:" << std::endl;

	contact.setFirstName(getInput("First Name: "));
	contact.setLastName(getInput("Last Name: "));
	contact.setNickname(getInput("Nickname: "));
	contact.setPhoneNumber(getPhoneNumber());
	contact.setDarkestSecret(getInput("Darkest Secret: "));

	return contact;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	while (true)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);

		if (command == "ADD" || command == "add")
		{
			Contact newContact = createContact();
			phoneBook.addContact(newContact);
			std::cout << "Contact added successfully!" << std::endl;
		}
		else if (command == "SEARCH" || command == "search")
			phoneBook.searchContact();
		else if (command == "EXIT" || command == "exit")
		{
			std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}