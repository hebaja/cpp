CXX = c++
FLAGS = -Wall -Wextra -Werror
NAME = PhoneBook
SRC = main.cpp Contact.cpp PhoneBook.cpp
SRC_DIR = .
SRCS=$(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
