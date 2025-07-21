COMPILE = c++ -Wall -Wextra -Werror -std=c++98
NAME = megaphone
SRC = megaphone.cpp
OBJ = $(OBJ_FOLDER)/megaphone.o
OBJ_FOLDER = obj


$(NAME): $(OBJ)
	$(COMPILE) $(OBJ) -o $(NAME)

$(OBJ_FOLDER)/%.o: %.cpp
	@mkdir -p $(OBJ_FOLDER)
	$(COMPILE) -c $< -o $@
	
all: $(NAME)

clean:
	@rm -rf $(OBJ_FOLDER)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
