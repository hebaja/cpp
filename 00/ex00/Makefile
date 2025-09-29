CXX = c++
FLAGS = -Wall -Wextra -Werror
NAME = megaphone
SRC = megaphone.cpp
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(SRC:.cpp=.o)

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

.PHONY: all clean fclean re
