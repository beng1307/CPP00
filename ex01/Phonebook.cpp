#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"


Phonebook::Phonebook(void)
{
	std::cin >> this->input;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void Phonebook::add(void)
{

}

void Phonebook::search(void)
{

}

void Phonebook::exit(void)
{

}

std::string Phonebook::get_input(void)
{
	return (input);
}
