#include <iostream>
#include "Phonebook.hpp"

int main(void)
{
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		Phonebook phonebook(0);
		
		if (phonebook.get_input() == "ADD")
			phonebook.add();
		else if (phonebook.get_input() == "SEARCH")
			phonebook.search();
		else if (phonebook.get_input() == "EXIT")
			break ;
	}
	return (0);
}