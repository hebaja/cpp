#pragma once

#include "Contact.hpp"

using namespace std;

class	Phonebook
{
	private:
		int		index;
		int		contacts_quantity;
		Contact contacts[8];

	public:
		Phonebook();
		Contact*	getContacts();
		int			getIndex();
		int			getContactsQuantity();
		int			getData(std::string *data);
		int			isValidIndex(std::string chosen_index);
		void		addMany();
		void		printFitInfo(std::string info);
		void		addContact(Contact *contact);
		void		printAllContacts();
		void		incrementContactsQuantity();
		void		incrementIndex();
		void		printContact(int index);
};
