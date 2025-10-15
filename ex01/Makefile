CXX = c++
FLAGS = -Wall -Wextra -Werror
NAME = phonebook
SRC = main.cpp Contact.cpp Phonebook.cpp
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(FLAGS) $(SRC) -o $(NAME) -g

.c.o:
	$(CXX) $(FLAGS) -c $< -o $@ -g

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
