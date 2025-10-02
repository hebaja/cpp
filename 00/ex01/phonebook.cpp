#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class	Contact
{
	int	index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	public:
		Contact(){};
		Contact(int index, std::string first_name, std::string last_name, std::string nickname, std::string phone_number) {
			this->index = index;
			this->first_name = first_name;
			this->last_name = last_name;
			this->nickname = nickname;
			this->phone_number = phone_number;
		};
		int	getIndex()
		{
			return this->index;
		};
		std::string getFirstName()
		{
			return this->first_name;
		};
		std::string getLastName()
		{
			return this->last_name;
		};
		std::string getNickname()
		{
			return this->nickname;
		};
		std::string getPhoneNumber()
		{
			return this->phone_number;
		};
};

class	Phonebook
{
	int		contacts_quantity;
	Contact contacts[8];

	public:
	Phonebook(int contacts_quantity)
	{
		this->contacts_quantity = contacts_quantity;
		this->contacts_quantity = 0;
	};
	void	addContact(Contact contact, int index)
	{
		this->contacts[index] = contact;
		contacts_quantity++;
	}
	Contact*	getContacts()
	{
		return this->contacts;
	}
	void	print_all_contacts()
	{
		for (int i = 0; i < this->contacts_quantity; i++) {
			std::cout << setw(10) << this->getContacts()[i].getIndex() << "|";
			if (this->getContacts()[i].getFirstName().size() > 10)
			{
				std::string tmp = this->getContacts()[i].getFirstName();
				tmp.resize(9);
				tmp.shrink_to_fit();
				std::cout << setw(9) << tmp << "." << "|";
			}
			else
			{
				std::cout << setw(10) << this->getContacts()[i].getFirstName() << "|";
			}
			std::cout << setw(10) << this->getContacts()[i].getLastName() << "|";
			std::cout << setw(10) << this->getContacts()[i].getNickname() << "|";
			std::cout << setw(10) << this->getContacts()[i].getPhoneNumber() << "|" << std::endl;
		}
	}
};

int	main()
{
	Phonebook phonebook(8);
	Contact contact_a(0, "Habiloaldo", "Ambr", "aldo", "555-5555");
	Contact contact_b(1, "Ale", "Peroba", "xandy", "777-7777");
	Contact contact_c(2, "Alexsandrino", "Peroba", "xandy", "777-7777");
	phonebook.addContact(contact_a, contact_a.getIndex());
	phonebook.addContact(contact_b, contact_b.getIndex());
	phonebook.addContact(contact_c, contact_c.getIndex());
	phonebook.print_all_contacts();
	return (0);
}
