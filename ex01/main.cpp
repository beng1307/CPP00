#include <iostream>
#include "Phonebook.hpp"

int main(void)
{
	Phonebook	phonebook(0);
	std::string	input;

	while (1)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);

		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
