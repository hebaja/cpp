#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

class	Contact
{
	int	index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	public:
		Contact(){};
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret) {
			this->first_name = first_name;
			this->last_name = last_name;
			this->nickname = nickname;
			this->phone_number = phone_number;
			this->darkest_secret = darkest_secret;
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
		std::string getDarkestSecret()
		{
			return this->darkest_secret;
		};
		void	set_index(int index)
		{
			this->index = index;
		}
};

void	print_fit_info(std::string info)
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

class	Phonebook
{
	int		contacts_quantity;
	int		index;
	Contact contacts[8];

	public:
	Phonebook(int contacts_quantity)
	{
		this->contacts_quantity = contacts_quantity;
		this->contacts_quantity = 0;
		this->index = 0;
	};
	void	addContact(Contact contact)
	{
		contact.set_index(this->index);
		this->contacts[this->index] = contact;
		contacts_quantity++;
		this->index++;
	}
	Contact*	getContacts()
	{
		return this->contacts;
	}
	void	print_all_contacts()
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
	void	print_contact(int index)
	{
		for (int i = 0; i < this->contacts_quantity; i++) {
			if (index == this->getContacts()[i].getIndex())
			{
				std::cout << this->getContacts()[i].getFirstName() << std::endl;
				std::cout << this->getContacts()[i].getLastName() << std::endl;
				std::cout << this->getContacts()[i].getNickname() << std::endl;
				std::cout << this->getContacts()[i].getPhoneNumber() << std::endl;
				std::cout << this->getContacts()[i].getDarkestSecret() << std::endl;
				return ;
			}
		}
		std::cout << "Contact not found" << std::endl;
	}
};

void	add_many(Phonebook *phonebook)
{
	std::string	base_name = "Contact_";
	std::string	base_nick = "con_";

	for (int i = 0; i < 2; i++)
	{
		char	suffix = 'a' + i;
		std::string name = base_name + suffix;
		std::string nick = base_nick + suffix;
		Contact contact(name, "Last name", nick, "555 5555", "dark");
		phonebook->addContact(contact);
	}
}

void	show_prompt(std::string *command)
{
	std::cout << "Input a command: ADD | SEARCH | EXIT: " ;
	std::getline(std::cin, *command);
}

int	get_data(std::string *data)
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
			
int	is_valid_index(std::string chosen_index)
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

int	main()
{
	std::string	command;
	Phonebook	phonebook(8);

	add_many(&phonebook);
	show_prompt(&command);
	while (command.compare("EXIT") != 0)
	{
		if (command.compare("ADD") == 0)
		{
			std::string	first_name;
			std::string	last_name;
			std::string	nickname;
			std::string	phone_number;
			std::string	darkest_secret;
			std::cout << "Input contact first name: ";
			while (get_data(&first_name) == 0)
				std::cout << "Input contact first name: ";
			std::cout << "Input contact last name: ";
			while (get_data(&last_name) == 0)
				std::cout << "Input contact last name: ";
			std::cout << "Input contact nickname: ";
			while (get_data(&nickname) == 0)
				std::cout << "Input contact nickname: ";
			std::cout << "Input contact phone number: ";
			while (get_data(&phone_number) == 0)
				std::cout << "Input contact phone number: ";
			std::cout << "Input contact darkest secret: ";
			while (get_data(&darkest_secret) == 0)
				std::cout << "Input contact darkest secret: ";
			Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
			phonebook.addContact(contact);
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::string	chosen_index;
			int			num_index;

			phonebook.print_all_contacts();
			std::cout << "Input contact's index: ";
			std::getline(std::cin, chosen_index);
			if (is_valid_index(chosen_index))
			{
				num_index = std::stoi(chosen_index);
				phonebook.print_contact(num_index);
			}
		}
		else
			std::cout << "Invalid command" << std::endl;
		show_prompt(&command);
	}
	return (0);
}
