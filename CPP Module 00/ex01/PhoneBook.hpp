#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int oldestIndex;
		int contactCount;
	public:
		PhoneBook();
		void addContact(const Contact& contact);
		void searchContact() const;
		void displayContact(int index) const;
		bool isEmpty() const;
		int getContactCount() const;
	private:
		std::string truncateString(const std::string& str, size_t width) const;
		void displayContactList() const;
};

#endif