NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./src/

INCL = includes/minishell.h

LIB_INCL = -L. libft/includes/libft.h

LIB_A = -lm libft/libft.a

SRC = $(SRC_PATH)command.c		\
	  $(SRC_PATH)errors.c		\
	  $(SRC_PATH)get_line.c		\
	  $(SRC_PATH)main.c			\
	  $(SRC_PATH)own_command.c	\
	  $(SRC_PATH)set_env.c
	  
BIN =  $(SRC_PATH)command.o		\
	   $(SRC_PATH)errors.o		\
	   $(SRC_PATH)get_line.o	\
	   $(SRC_PATH)main.o		\
	   $(SRC_PATH)own_command.o	\
	   $(SRC_PATH)set_env.o

all: $(NAME)

$(NAME): qme
	@echo "\nPreparing to compile minishell..."
	@make re -C libft/
	@$(CC) $(C_FLAGS) -c $(SRC) $(INCL)
	@mv *.o src/
	@echo "Library has successfully compiled and object files have been" \
		"created and moved to src/"
	@$(CC) $(C_FLAGS) $(BIN) $(LIB_INCL) $(LIB_A)
	@mv ./a.out ./minishell
	@echo "Minishell has successfully been compiled.\n"

clean:
	@rm -f $(BIN)
	@echo "All object files have been removed. Please ensure no source" \
		"files have accidently been removed."
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "The executables ./minishell and ./libft has been removed"

re: fclean all
	@echo "Minishell has successfully recompiled.\n"

format: norme me
	@echo "All good!"

norme:
	norminette $(SRC) $(INCL)

me: qme
	@echo "Author:"
	cat -e author

qme:
	@rm -Rf author
	@whoami > author
