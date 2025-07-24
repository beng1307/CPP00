#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class	Phonebook
{
	private:

		Contact		contacts[8];
		int			contact_count;
		
		std::string	input;
		std::string	first_name_input;
		std::string	last_name_input;
		std::string	nickname_input;
		std::string	phone_number_input;
		std::string	darkest_secret_input;

	public:

		Phonebook(int contact_count);
		~Phonebook(void);

		void		add(void);
		void		search(void);

		std::string get_input(void);
		void		add_data(void);
		void		insert_data(void);
		void		print_options(Contact current, int index);
		int			phonebook_atoi(std::string input);
		bool		is_wrong(std::string);
		bool		correct_input(void);
};

#endif