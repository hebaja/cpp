#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

class	Contact
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	Contact	*next;
	public:
	Contact(){};
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->nickname = nickname;
		this->phone_number = phone_number;
		this->darkest_secret = darkest_secret;
		this->next = NULL;
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
	Contact	*getNext()
	{
		return this->next;
	}
	void	setNext(Contact *contact)
	{
		this->next = contact;
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

void	addContact(Contact **contact_lst, Contact *new_contact)
{
	if (*contact_lst && new_contact)
	{
		new_contact->setNext(*contact_lst);
		*contact_lst = new_contact;
		return ;
	}
	if (new_contact)
		*contact_lst = new_contact;
}

void	print_all(Contact **contact_lst)
{
	Contact	*contact;
	int		index;

	contact = *contact_lst;
	index = 0;
	while (contact)
	{
		std::cout << setw(10) << index << "|";
		print_fit_info(contact->getFirstName());
		print_fit_info(contact->getLastName());
		print_fit_info(contact->getNickname());
		print_fit_info(contact->getPhoneNumber());
		std::cout << std::endl;
		contact = contact->getNext();
		index++;
	}
}

void	print_one(Contact **contact_lst, int index)
{
	Contact	*contact;
	int	count;

	contact = *contact_lst;
	count = 0;
	while (contact)
	{
		if (count == index)
		{
			std::cout << contact->getFirstName() << std::endl;
			std::cout << contact->getLastName() << std::endl;
			std::cout << contact->getNickname() << std::endl;
			std::cout << contact->getPhoneNumber() << std::endl;
			std::cout << contact->getDarkestSecret() << std::endl;
			return ;
		}
		contact = contact->getNext();
		count++;
	}
	std::cout << "Contact not found" << std::endl;
}

class	Phonebook
{
	int		contacts_quantity;
	int		index;
	Contact *contact_lst;

	public:
	Phonebook(int contacts_quantity)
	{
		this->contacts_quantity = contacts_quantity;
		this->contacts_quantity = 0;
		this->index = 0;
	};
	void	add(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
	{
		Contact *contact = new Contact(first_name, last_name, nickname, phone_number, darkest_secret);
		addContact(&this->contact_lst, contact);
	}
	Contact	**getContacts()
	{
		return &this->contact_lst;
	}
	void	print_all_contacts()
	{
		print_all(this->getContacts());
	}
	void	print_contact(int index)
	{
		print_one(this->getContacts(), index);
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
		// phonebook->addContact(contact);
		addContact(phonebook->getContacts(), &contact);
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
	Contact		contact;

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
			phonebook.add(first_name, last_name, nickname, phone_number, darkest_secret);
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
