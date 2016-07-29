# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehansman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/10 12:36:11 by ehansman          #+#    #+#              #
#    Updated: 2016/07/10 12:36:18 by ehansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC_PATH = ./src/

INCL = includes/minishell.h

LIB_INCL = -L. libft/includes/libft.h $^ -ltermcap

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
		$(SRC_PATH)ft_echo.c		\
		$(SRC_PATH)ft_cd.c			\
		$(SRC_PATH)trim.c			\
		$(SRC_PATH)signals.c		\
		$(SRC_PATH)init_term.c
	  
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

all: $(NAME) qme

$(NAME):
	@$(call colorecho,"\nPreparing to compile $(NAME)...")
	@make re -C libft/
	@$(CC) $(C_FLAGS) -c $(SRC) $(INCL)
	@mv *.o src/
	@$(call colorecho,"Library has successfully compiled and object" \
		"files have been created and moved to src/")
	@$(CC) $(C_FLAGS) $(BIN) $(LIB_INCL) $(LIB_A)
	@mv ./a.out ./$(NAME)
	@clear
	@$(call colorecho, "$(NAME) has successfully been compiled.\n")

clean:
	@rm -f $(BIN)
	@$(call colorecho, "All object files have been removed. Please" \
		"ensure no sourcefiles have accidently been removed.")
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@$(call colorecho, "The executables ./$(NAME) and " \
		"./libft has been removed")
	@rm -f $(INCL:.h=.h.gch)

re: fclean all
	@clear
	@$(call colorecho, "$(NAME) has successfully recompiled.\n")

full: re clean
	@clear
	@$(call colorecho, "Done making and cleaning.\n")
	@./$(NAME)


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
