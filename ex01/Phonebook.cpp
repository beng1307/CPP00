#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <limits>
#include "Phonebook.hpp"
#include "Contact.hpp"


Phonebook::Phonebook(int count) : contact_count(count)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

///////////////////////////////////////////////////////////////////////////////

void	Phonebook::insert_data(void)
{
	std::cout << "First name: " << std::endl; 
	std::getline(std::cin, first_name_input);
	
	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, last_name_input);

	std::cout << "Nickname: " << std::endl; 
	std::getline(std::cin, nickname_input);

	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, phone_number_input);

	std::cout << "Darkest Secret: " << std::endl;
	std::getline(std::cin, darkest_secret_input);
}

bool	Phonebook::is_wrong(std::string input)
{
	if (input.empty())
		return (false);
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (!std::isspace(input[i]))
			return (false);
	}
	return (true);
}

bool	Phonebook::is_number_wrong(std::string input)
{
	bool	spaces_only = true;

	if (input.empty())
		return (false);
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (!std::isspace(input[i]))
			spaces_only = false;
		if (!std::isdigit(input[i]) && !std::isspace(input[i]))
			return (true);
	}
	if (spaces_only)
		return (true);
	else
		return (false);
}

bool	Phonebook::correct_input(void)
{
	return (!is_wrong(first_name_input) && !is_wrong(last_name_input) && !is_wrong(nickname_input)
	&& !is_number_wrong(phone_number_input) && !is_wrong(darkest_secret_input));
}

void	Phonebook::add_data(void)
{
	int	contact_to_set;

	if (contact_count < 8)
		contact_to_set = contact_count;
	else
		contact_to_set = contact_count - 1;
	contacts[contact_to_set].set_first_name(first_name_input);
	contacts[contact_to_set].set_last_name(last_name_input);
	contacts[contact_to_set].set_nickname(nickname_input);
	contacts[contact_to_set].set_phone_number(phone_number_input);
	contacts[contact_to_set].set_darkest_secret(darkest_secret_input);
}

void	Phonebook::add(void)
{
	int	index = 0;
	
	if (contact_count < 8)
	{
		while (!contacts[index].empty() && index < 8)
			index++;
		insert_data();	
	}
	else
	{
		while (index < 7)
		{
			contacts[index] = contacts[index + 1];
			index++;
		}
		insert_data();
	}
	if (correct_input())
	{
		add_data();
		if (contact_count < 8)
			contact_count++;
	}
	else
		std::cout << "\033[1;31m"
			<< "Wrong data input, contact won't be saved!"
				<< "\033[0m" <<  std::endl;
}

///////////////////////////////////////////////////////////////////////////////

void	Phonebook::print_options(Contact current, int index)
{
	int	length;

	std::cout << std::string(9, ' ') << index << '|';
	
	length = current.get_first_name().length();
	if (length <= 10)
		std::cout << std::string(std::abs(length - 10), ' ') << current.get_first_name();
	else
		std::cout << current.get_first_name().substr(0, 9) << ".";
		
	std::cout << '|';

	length = current.get_last_name().length();
	if (length <= 10)
		std::cout << std::string(std::abs(length - 10), ' ') << current.get_last_name();
	else
		std::cout << current.get_last_name().substr(0, 9) << ".";
	
	std::cout << '|';
	
	length = current.get_nickname().length();
	if (length <= 10)
		std::cout << std::string(std::abs(length - 10), ' ') << current.get_nickname();
	else
		std::cout << current.get_nickname().substr(0, 9) << ".";
	
	std::cout << std::endl;
}

int	Phonebook::phonebook_atoi(std::string input)
{
	int	index = 0;
	int	number = 0;
	
	while (input[index])
	{
		if (!std::isdigit(input[index]) && !std::isspace(input[index]))
			return (-1);
		if (number >= INT_MAX / 10 && (input[index] - '0') > INT_MAX % 10)
			return (-1);
		number = number * 10 + input[index++] - '0';
	}
	return (number);
}

void Phonebook::search(void)
{
	int	entry = 0;
	
	for (int index = 0; index < contact_count; index++)
	{
		if (!contacts[index].empty())
			print_options(contacts[index], index + 1);
	}
	if (!contacts[0].empty())
	{
		std::cout << "Which entry do u want to display?" << std::endl;
		std::getline(std::cin, input);
		
		entry = phonebook_atoi(input);
		if (entry > 0 && entry <= contact_count)
		{
			std::cout << contacts[entry - 1].get_first_name() << std::endl;
			std::cout << contacts[entry - 1].get_last_name() << std::endl;
			std::cout << contacts[entry - 1].get_nickname() << std::endl;
			std::cout << contacts[entry - 1].get_phone_number() << std::endl;
			std::cout << contacts[entry - 1].get_darkest_secret() << std::endl;
		}
		else
			std::cout << "\033[1;31m" << "Entry not existent!" << "\033[0m" << std::endl;
	}

}
