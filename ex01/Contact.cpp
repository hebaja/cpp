#include <iostream>
#include "Contact.hpp"

using namespace std;

Contact::Contact(){}

Contact::Contact(std::string first_name, 
				 std::string last_name, 
				 std::string nickname, 
				 std::string phone_number, 
				 std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

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

void	Contact::setIndex(int index)
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
