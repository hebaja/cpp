#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "Phonebook.hpp"

using namespace std;

void	Phonebook::add_many()
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

int	Phonebook::get_data(std::string *data)
{
	int	flag;

	flag = 0;
	std::getline(std::cin, *data);
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
	return (flag);
}
			
int	Phonebook::is_valid_index(std::string chosen_index)
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

void	Phonebook::print_fit_info(std::string info)
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

	contact->set_index(curr_index);

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

void	Phonebook::print_all_contacts()
{
	for (int i = 0; i < this->contacts_quantity; i++) {
		std::cout << setw(10) << this->getContacts()[i].getIndex() << "|";
		print_fit_info(this->getContacts()[i].getFirstName());
		print_fit_info(this->getContacts()[i].getLastName());
		print_fit_info(this->getContacts()[i].getNickname());
		print_fit_info(this->getContacts()[i].getPhoneNumber());
		std::cout << std::endl;
	}
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
