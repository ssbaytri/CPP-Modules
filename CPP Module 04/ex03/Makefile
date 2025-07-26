CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = rpg
SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean