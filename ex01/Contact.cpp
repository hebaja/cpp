#include <iostream>
#include "Contact.hpp"

using namespace std;

int	Contact::getIndex()
{
	return this->index;
}

std::string Contact::getFirstName()
{
	return this->first_name;
}

std::string Contact::getLastName()
{
	return this->last_name;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->phone_number;
}

std::string Contact::getDarkestSecret()
{
	return this->darkest_secret;
}

void	Contact::set_index(int index)
{
	this->index = index;
}

void	Contact::print()
{
	std::cout << this->getFirstName() << std::endl;
	std::cout << this->getLastName() << std::endl;
	std::cout << this->getNickname() << std::endl;
	std::cout << this->getPhoneNumber() << std::endl;
	std::cout << this->getDarkestSecret() << std::endl;
}
