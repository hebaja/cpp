#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "Phonebook.hpp"

using namespace std;

Phonebook::Phonebook()
{
	this->contacts_quantity = 0;
	this->index = 0;
};

int	Phonebook::getData(std::string *data)
{
	int	flag;

	flag = 0;
	if (std::getline(std::cin, *data))
	{
		if (data->empty())
		{
			std::cout << "Field can't be empty" << std::endl;
			return (0);
		}
		for (char c : *data)
		{
			if (!std::isspace(c))
			{
				flag = 1;
				break ;
			}
		}
		if (!flag)
			std::cout << "Field can't be empty" << std::endl;
	}
	else
		return (-1);
	return (flag);
}

Contact*	Phonebook::getContacts()
{
	return this->contacts;
}

int	Phonebook::getIndex()
{
	return this->index;
}

int	Phonebook::getContactsQuantity()
{
	return this->contacts_quantity;
}

void	Phonebook::addMany()
{
	std::string	base_name = "Contact_";
	std::string	base_nick = "con_";

	for (int i = 0; i < 8; i++)
	{
		char	suffix = 'a' + i;
		std::string name = base_name + suffix;
		std::string nick = base_nick + suffix;
		Contact contact(name, "Last name", nick, "555 5555", "dark");
		this->addContact(&contact);
	}
}

int	Phonebook::isValidIndex(std::string chosen_index)
{
	for (char c : chosen_index)
	{
		if (!std::isdigit(c))
		{
			std::cout << "Invalid index" << std::endl;
			return (0);
		}
	}
	return (1);
}

void	Phonebook::printFitInfo(std::string info)
{
	if (info.size() > 10)
	{
		std::string tmp = info;
		tmp.resize(9);
		tmp.shrink_to_fit();
		std::cout << setw(9) << tmp << "." << "|";
	}
	else
		std::cout << setw(10) << info << "|";
}

void	Phonebook::incrementContactsQuantity()
{
	this->contacts_quantity++;
}

void	Phonebook::incrementIndex()
{
	this->index++;
}

void	Phonebook::addContact(Contact *contact)
{
	int	curr_index;

	curr_index = this->index % 8;
	contact->setIndex(curr_index);
	this->getContacts()[contact->getIndex()] = *contact;
	if (this->getContactsQuantity() < 8)
		this->incrementContactsQuantity();
	this->incrementIndex();
}

void	Phonebook::printContact(int index)
{
	if (index >= 0 && index <= 7)
	{
		if (index <= this->getContactsQuantity())
		{
			this->getContacts()[index].print();
		}
		else
			std::cout << "Contact not found" << std::endl;
	}
	else
		std::cout << "Index out of bounds" << std::endl;
}

void	Phonebook::printAllContacts()
{
	for (int i = 0; i < this->contacts_quantity; i++) {
		std::cout << setw(10) << this->getContacts()[i].getIndex() << "|";
		printFitInfo(this->getContacts()[i].getFirstName());
		printFitInfo(this->getContacts()[i].getLastName());
		printFitInfo(this->getContacts()[i].getNickname());
		printFitInfo(this->getContacts()[i].getPhoneNumber());
		std::cout << std::endl;
	}
}
