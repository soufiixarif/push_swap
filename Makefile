NAME = push_swap
SRC = push_swap.c libftfun.c libftfun1.c libftfun2.c utils.c actions.c\
sorting.c indexing.c sorting2.c checkvalidity.c sortingmore.c actions2.c\
actions3.c sortingmore2.c
OBJ = $(SRC:.c=.o)
FLAGS = -g -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
