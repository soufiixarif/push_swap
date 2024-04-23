NAME = push_swap
SRC_DIR = mandatory
SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/libftfun.c $(SRC_DIR)/libftfun1.c $(SRC_DIR)/libftfun2.c $(SRC_DIR)/utils.c $(SRC_DIR)/actions.c\
$(SRC_DIR)/sorting.c $(SRC_DIR)/indexing.c $(SRC_DIR)/sorting2.c $(SRC_DIR)/checkvalidity.c $(SRC_DIR)/sortingmore.c $(SRC_DIR)/actions2.c\
$(SRC_DIR)/actions3.c $(SRC_DIR)/sortingmore2.c
OBJ = $(SRC:.c=.o)
FLAGS = -g -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	rm -f $(OBJ)

%.o: %.c push_swap.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
