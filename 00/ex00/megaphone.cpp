#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int	main(int argc, char **argv)
{
	std::string		str;
	int				i;

	if (argc > 1)
	{
		argv++;
		while (*argv)
		{
			i = -1;
			str = *argv;
			while (str[++i])
				std::cout << (char)(toupper(str[i]));
			argv++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
