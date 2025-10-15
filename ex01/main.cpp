#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"

void	show_prompt(std::string *command)
{
	std::cout << "Input a command: ADD | SEARCH | EXIT: " ;
	std::getline(std::cin, *command);
}

int	main()
{
	std::string	command;
	Phonebook	phonebook;

	phonebook.add_many();
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
			while (phonebook.get_data(&first_name) == 0)
				std::cout << "Input contact first name: ";
			std::cout << "Input contact last name: ";
			while (phonebook.get_data(&last_name) == 0)
				std::cout << "Input contact last name: ";
			std::cout << "Input contact nickname: ";
			while (phonebook.get_data(&nickname) == 0)
				std::cout << "Input contact nickname: ";
			std::cout << "Input contact phone number: ";
			while (phonebook.get_data(&phone_number) == 0)
				std::cout << "Input contact phone number: ";
			std::cout << "Input contact darkest secret: ";
			while (phonebook.get_data(&darkest_secret) == 0)
				std::cout << "Input contact darkest secret: ";
			Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
			phonebook.addContact(&contact);
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::string	chosen_index;
			int			num_index;

			phonebook.print_all_contacts();
			std::cout << "Input contact's index: ";
			std::getline(std::cin, chosen_index);
			if (phonebook.is_valid_index(chosen_index))
			{
				num_index = std::stoi(chosen_index);
				phonebook.printContact(num_index);
			}
		}
		else
			std::cout << "Invalid command" << std::endl;
		show_prompt(&command);
	}
	return (0);
}
