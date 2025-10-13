#pragma once

#include <string>

using namespace std;

class	Contact
{
	private:
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
		int	getIndex();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		void	set_index(int index);
		void	print();
};
