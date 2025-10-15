#pragma once

#include "Contact.hpp"

using namespace std;

class	Phonebook
{
	int		index;
	Contact contacts[8];
	int		contacts_quantity;

	public:
	Phonebook()
	{
		this->contacts_quantity = 0;
		this->index = 0;
	};
	int		get_data(std::string *data);
	int		is_valid_index(std::string chosen_index);
	void	add_many();
	void	print_fit_info(std::string info);
	void	addContact(Contact *contact);
	void	print_all_contacts();
	Contact*	getContacts();
	int		getIndex();
	int		getContactsQuantity();
	void	incrementContactsQuantity();
	void	incrementIndex();
	void	printContact(int index);
};
