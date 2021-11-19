NAME = a.out
COMPILER = clang++
# COMPILER = clang++ -fsanitize=address

WFLAG = -Wall -Werror -Wextra

SRC =	*.cpp
OBJ = $(SRC:.cpp=.o)

all:
	$(COMPILER) $(WFLAG) -c $(SRC)
	$(COMPILER) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all