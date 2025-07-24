#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"


Phonebook::Phonebook(int count) : contact_count(count)
{
	std::cin >> input;
}

Phonebook::~Phonebook(void)
{
	return ;
}

///////////////////////////////////////////////////////////////////////////////

void	Phonebook::insert_data(int index)
{
	std::cout << "First name: " << std::endl; 
	std::cin >> first_name_input;
	
	std::cout << "Last name: " << std::endl;
	std::cin >> last_name_input;

	std::cout << "Nickname: " << std::endl; 
	std::cin >> nickname_input;
	
	std::cout << "Phone number: " << std::endl;
	std::cin >> phone_number_input;
	
	std::cout << "Darkest Secret: " << std::endl;
	std::cin >> darkest_secret_input;
}

bool	Phonebook::is_wrong(std::string input)
{
	if (input.empty())
		return (false);
	for (char character : input)
	{
		if (!std::isspace(character))
			return (false);
	}
	return (true);
}

bool	Phonebook::correct_input(void)
{
	return (!is_wrong(first_name_input) && !is_wrong(last_name_input) && !is_wrong(nickname_input)
		&& !is_wrong(phone_number_input) && !is_wrong(darkest_secret_input));
}

void	Phonebook::add_data(void)
{
	contacts[contact_count].set_first_name(first_name_input);
	contacts[contact_count].set_last_name(last_name_input);
	contacts[contact_count].set_nickname(nickname_input);
	contacts[contact_count].set_phone_number(phone_number_input);
	contacts[contact_count].set_darkest_secret(darkest_secret_input);
}

void	Phonebook::add(void)
{
	int	index = 0;
	
	if (contact_count < 8)
	{
		while (!contacts[index].empty() && index < 8)
			index++;
		insert_data(index);	
	}
	else
	{
		while (index < 7)
			contacts[index++] = contacts[index + 1];
		insert_data(index);
	}
	if (correct_input())
	{
		add_data();
		contact_count++;
	}
	else
		std::cout << "Wrong data input!" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////

void Phonebook::search(void)
{

}

///////////////////////////////////////////////////////////////////////////////

std::string Phonebook::get_input(void)
{
	return (input);
}
