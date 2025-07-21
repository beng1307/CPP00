#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
};

Contact::~Contact(void)
{
	return ;
};

void Contact::set_first_name(std::string data)
{
	first_name = data;
}

std::string Contact::get_first_name(void)
{
	return (first_name);
}
void Contact::set_last_name(std::string data)
{
	last_name = data;
}
std::string Contact::get_last_name(void)
{
	return (last_name);
}

void Contact::set_phone_number(std::string data)
{
	phone_number = data;
}

std::string	Contact::get_phone_number(void)
{
	return (last_name);
}
void Contact::set_darkest_secret(std::string data)
{
	darkest_secret = data;
}
std::string Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}






