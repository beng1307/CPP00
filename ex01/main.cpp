#include <iostream>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		Phonebook phonebook;
		
		if (phonebook.get_input() == "ADD")
			Contact.add_data();
		else if (phonebook.get_input() == "SEARCh")

		else if (phonebook.get_input() == "EXIT")

		else
			std::cout << "Wrong command!" << std::endl;
	}

	return (0);
}