COMPILE = c++ -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRCS = phonebook.cpp
OBJS = $(OBJS_FOLDER)/%.o
OBJS_FOLDER = obj

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME) 

$(OBJS_FOLDER)/%.o: %.cpp
	@mkdir -p %(OBJS_FOLDER)
	$(COMPILE) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJSFOLDER)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
