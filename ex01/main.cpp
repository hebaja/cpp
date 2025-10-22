#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#ifndef ADD
# define ADD 0
#endif

bool	showPrompt(std::string *command)
{
	std::cout << "Input a command: ADD | SEARCH | EXIT: " ;
	if (!std::getline(std::cin, *command))
		return false;
	return true;
}

int	fillData(std::string msg, Phonebook *phonebook, std::string *data)
{
	int	flag;

	std::cout << msg;
	flag = phonebook->getData(data);
	if (flag >= 0)
	{
		if (flag == 0)
		{
			while (phonebook->getData(data) == 0)
				std::cout << msg;
		}
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	std::string	command;
	Phonebook	phonebook;

	(void)argv;
	if (argc > 1)
		phonebook.addMany();
	if (showPrompt(&command))
	{
		while (command.compare("EXIT") != 0)
		{
			if (command.compare("ADD") == 0)
			{
				std::string	firstName;
				std::string	lastName;
				std::string	nickname;
				std::string	phoneNumber;
				std::string	darkestSecret;
				if (fillData("Input contact first name: ", &phonebook, &firstName) == -1)
					break ;
				if (fillData("Input contact last name: ", &phonebook, &lastName) == -1)
					break ;
				if (fillData("Input contact nickname: ", &phonebook, &nickname) == -1)
					break ;
				if (fillData("Input contact phone number: ", &phonebook, &phoneNumber) == -1)
					break ;
				if (fillData("Input contact darkest secret: ", &phonebook, &darkestSecret) == -1)
					break ;
				Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
				phonebook.addContact(&contact);
			}
			else if (command.compare("SEARCH") == 0)
			{
				std::string	chosen_index;
				int			num_index;

				phonebook.printAllContacts();
				std::cout << "Input contact's index: ";
				if (std::getline(std::cin, chosen_index))
				{
					if (phonebook.isValidIndex(chosen_index))
					{
						num_index = std::stoi(chosen_index);
						phonebook.printContact(num_index);
					}
				}
				else
					break ;
			}
			else
				std::cout << "Invalid command" << std::endl;
			command.clear();
			if (!showPrompt(&command))
				break ;
		}
	}
	return (0);
}
