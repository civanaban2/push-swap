NAME = push_swap

NAME_LIBFT = ft

DIR_BUILD = build
DIR_SRC = src
DIR_INC = inc
DIR_LIBFT = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	$(DIR_SRC)/push_swap.c \
		$(DIR_SRC)/arg_check.c \
		$(DIR_SRC)/arg_check_utils.c \
		$(DIR_SRC)/arg_check_utils_2.c \
		$(DIR_SRC)/sort.c \
		$(DIR_SRC)/sort_utils.c \
		$(DIR_SRC)/sort_utils_2.c \
		$(DIR_SRC)/print_utils.c \
		$(DIR_SRC)/cost.c \
		$(DIR_SRC)/cost_utils.c \
		$(DIR_SRC)/free_split.c \

INCLUDES_H = -I$(DIR_INC) -I$(DIR_LIBFT)
INCLUDES_LIB = -L$(DIR_LIBFT) -l$(NAME_LIBFT)

OBJ = $(SRC:.c=.o)

BUILD = $(DIR_BUILD)/$(NAME)
BUILD_LIBFT = $(DIR_LIBFT)/lib$(NAME_LIBFT).a

all: $(BUILD)

$(BUILD): $(BUILD_LIBFT) $(OBJ)
	mkdir -p $(DIR_BUILD)
	$(CC) $(OBJ) $(INCLUDES_LIB) -o $(BUILD)

$(BUILD_LIBFT):
	make -C $(DIR_LIBFT)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_H) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(DIR_BUILD)
	make -C $(DIR_LIBFT) fclean

re: fclean all

test: $(BUILD) checker/checker_linux
	@make -s tester

count: $(BUILD)
	@$(BUILD) $(ARG) | wc -l
	
tester:
	-@$(BUILD) $(ARG) | checker/checker_linux $(ARG)

leak:
	@valgrind --leak-check=full --show-leak-kinds=all -s $(BUILD) $(ARG)

.PHONY: all clean fclean re test tester count leak