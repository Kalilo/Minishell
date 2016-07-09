NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./src/

INCL = includes/minishell.h

LIB_INCL = -L. libft/includes/libft.h

LIB_A = -lm libft/libft.a

SRC =	$(SRC_PATH)checks.c			\
		$(SRC_PATH)command.c		\
		$(SRC_PATH)count.c			\
		$(SRC_PATH)errors.c			\
		$(SRC_PATH)exit.c			\
		$(SRC_PATH)ft_export.c		\
		$(SRC_PATH)ft_strchr_f.c	\
		$(SRC_PATH)ft_unset.c		\
		$(SRC_PATH)get_env.c		\
		$(SRC_PATH)get_line.c		\
		$(SRC_PATH)main.c			\
		$(SRC_PATH)own_command.c	\
		$(SRC_PATH)set_env.c		\
		$(SRC_PATH)ft_env.c			\
		$(SRC_PATH)find_path.c		\
		$(SRC_PATH)echo.c			\

	  
BIN =  $(SRC:.c=.o)

define colorecho
      @tput setaf 14
      @echo $1
      @tput sgr0
endef

define colorecho2
      @tput setaf 2
      @echo $1
      @tput sgr0
endef

all: $(NAME)

$(NAME): qme
	@$(call colorecho,"\nPreparing to compile minishell...")
	@make re -C libft/
	@$(CC) $(C_FLAGS) -c $(SRC) $(INCL)
	@mv *.o src/
	@$(call colorecho,"Library has successfully compiled and object " \
		"files have been created and moved to src/")
	@$(CC) $(C_FLAGS) $(BIN) $(LIB_INCL) $(LIB_A)
	@mv ./a.out ./minishell
	@clear
	@$(call colorecho, "Minishell has successfully been compiled.\n")

clean:
	@rm -f $(BIN)
	@$(call colorecho, "All object files have been removed. Please" \
		" ensure no sourcefiles have accidently been removed.")
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@$(call colorecho, "The executables ./minishell and " \
		"./libft has been removed")
	@rm -f $(INCL:.h=.h.gch)

re: fclean all
	@clear
	@$(call colorecho, "Minishell has successfully recompiled.\n")

format: norme me
	@$(call colorecho2, "All good!")

norme:
	@$(call colorecho2, "Normenette:\n")
	@norminette $(SRC) $(INCL)

me: qme
	@$(call colorecho2, "Author:")
	cat -e author

qme:
	@rm -Rf author
	@whoami > author
