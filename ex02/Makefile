CXX = c++
FLAGS = -Wall -Wextra -Werror
NAME = bankster
SRC = main.cpp Account.cpp
SRC_TEST = tests.cpp Account.cpp 
OBJS = $(SRC:.cpp=.o)
OBJS_TEST = $(SRC_TEST:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(FLAGS) $(SRC) -o $(NAME)

.c.o:
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	$(CXX) $(FLAGS) $(SRC_TEST) -o $(NAME)

.PHONY: all clean fclean re
