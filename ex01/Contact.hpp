#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact
{
	private:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	
	public:

		Contact(void);
		~Contact(void);

		void		set_first_name(std::string data);
		std::string	get_first_name(void);

		void		set_last_name(std::string data);
		std::string	get_last_name(void);

		void		set_nickname(std::string data);
		std::string	get_nickname(void);

		void		set_phone_number(std::string data);
		std::string	get_phone_number(void);

		void		set_darkest_secret(std::string data);
		std::string	get_darkest_secret(void);

		bool		empty(void);

};

#endif