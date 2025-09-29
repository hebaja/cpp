#include <iostream>
#include <cctype>

using namespace std;

void	put_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		cout << (char)toupper(str[i]);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
		while (argv[++i])
			put_str(argv[i]);
	else
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	cout << endl;

	return (0);
}
