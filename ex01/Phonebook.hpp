#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class	Phonebook
{
	private:
		Contact		contacts[8];
		std::string	input;

	public:

		Phonebook(void);
		~Phonebook(void);

		void	add(void);
		void	search(void);
		void	exit(void);

		std::string get_input(void);
};

#endif