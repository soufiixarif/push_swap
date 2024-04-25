NAME = push_swap
B_NAME = checker
SRC_DIR = mandatory
B_DIR = bonus
SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/libftfun.c $(SRC_DIR)/libftfun1.c $(SRC_DIR)/libftfun2.c $(SRC_DIR)/utils.c $(SRC_DIR)/actions.c\
$(SRC_DIR)/sorting.c $(SRC_DIR)/indexing.c $(SRC_DIR)/sorting2.c $(SRC_DIR)/checkvalidity.c $(SRC_DIR)/sortingmore.c $(SRC_DIR)/actions2.c\
$(SRC_DIR)/actions3.c $(SRC_DIR)/sortingmore2.c
B_SRC = $(B_DIR)/push_swap_bonus.c $(B_DIR)/libftfun_bonus.c $(B_DIR)/libftfun1_bonus.c $(B_DIR)/libftfun2_bonus.c $(B_DIR)/utils_bonus.c $(B_DIR)/actions_bonus.c\
$(B_DIR)/checkvalidity_bonus.c $(B_DIR)/actions2_bonus.c $(B_DIR)/actions3_bonus.c $(B_DIR)/Get_next_line/get_next_line_utils.c $(B_DIR)/Get_next_line/get_next_line.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32mMAKING SUCCESSFULY ✅\033[0;37m"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/push_swap.h Makefile
	@echo "compiling $@..."
	@$(CC) $(FLAGS) -c $< -o $@
	@clear

$(B_DIR)/%.o : $(B_DIR)/%.c $(B_DIR)/push_swap_bonus.h Makefile
	@echo "compiling $@..."
	@$(CC) $(FLAGS) -c $< -o $@
	@clear
clean:
	@rm -f $(OBJ) $(B_OBJ)
	@echo "\033[33mcleaning objects 🧼"

fclean: clean
	@rm -f $(NAME) $(B_NAME)
	@echo "\033[31mremoving exectable file ❌\033[0;37m"

re: fclean all

bonus : $(B_OBJ)
	@$(CC) $(FLAGS) $(B_OBJ) -o $(B_NAME)
	@echo "\033[32mMAKING BONUS SUCCESSFULY ✅\033[0;37m"