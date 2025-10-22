#pragma once

#include <string>

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
		Contact();
		Contact(std::string first_name, 
		  std::string last_name, 
		  std::string nickname, 
		  std::string phone_number, 
		  std::string darkest_secret);
		int	getIndex();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		void		setIndex(int index);
		void		print();
};
