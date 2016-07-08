# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/16 08:04:07 by cdebruyn          #+#    #+#              #
#    Updated: 2016/07/08 13:49:56 by cdebruyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./src/

INCLUDES = /includes/libft.h

SRC = $(SRC_PATH)ft_strlen.c	\
	  $(SRC_PATH)ft_putstr.c	\
	  $(SRC_PATH)ft_strdup.c	\
	  $(SRC_PATH)ft_strcpy.c	\
	  $(SRC_PATH)ft_putchar.c	\
	  $(SRC_PATH)ft_strncpy.c	\
	  $(SRC_PATH)ft_strchr.c	\
	  $(SRC_PATH)ft_strrchr.c	\
	  $(SRC_PATH)ft_strstr.c	\
	  $(SRC_PATH)ft_strnstr.c	\
	  $(SRC_PATH)ft_strcmp.c	\
	  $(SRC_PATH)ft_atoi.c		\
	  $(SRC_PATH)ft_isalpha.c	\
	  $(SRC_PATH)ft_isdigit.c	\
	  $(SRC_PATH)ft_isalnum.c	\
	  $(SRC_PATH)ft_isascii.c	\
	  $(SRC_PATH)ft_isprint.c	\
	  $(SRC_PATH)ft_toupper.c	\
	  $(SRC_PATH)ft_tolower.c	\
	  $(SRC_PATH)ft_memset.c	\
	  $(SRC_PATH)ft_bzero.c		\
	  $(SRC_PATH)ft_memcpy.c	\
	  $(SRC_PATH)ft_memccpy.c	\
	  $(SRC_PATH)ft_strnew.c	\
	  $(SRC_PATH)ft_strdel.c	\
	  $(SRC_PATH)ft_strclr.c	\
	  $(SRC_PATH)ft_striter.c	\
	  $(SRC_PATH)ft_striteri.c	\
	  $(SRC_PATH)ft_strcat.c	\
	  $(SRC_PATH)ft_strsplit.c	\
	  $(SRC_PATH)ft_strsub.c	\
	  $(SRC_PATH)ft_intcmp.c	\
	  $(SRC_PATH)ft_strjoin.c	\
	  $(SRC_PATH)ft_2charcmp.c	\
	  $(SRC_PATH)ft_3charcmp.c	\
	  $(SRC_PATH)ft_memchr.c	\
	  $(SRC_PATH)ft_memcmp.c	\
	  $(SRC_PATH)ft_check_literal.c		\
	  $(SRC_PATH)ft_replace_literal.c	\
	  $(SRC_PATH)ft_atoi_isdigit.c

OBJ = $(SRC_PATH)ft_strlen.o	\
	  $(SRC_PATH)ft_putstr.o	\
	  $(SRC_PATH)ft_strdup.o	\
	  $(SRC_PATH)ft_strcpy.o	\
	  $(SRC_PATH)ft_putchar.o	\
	  $(SRC_PATH)ft_strncpy.o	\
	  $(SRC_PATH)ft_strchr.o	\
	  $(SRC_PATH)ft_strrchr.o	\
	  $(SRC_PATH)ft_strstr.o	\
	  $(SRC_PATH)ft_strnstr.o	\
	  $(SRC_PATH)ft_strcmp.o	\
	  $(SRC_PATH)ft_atoi.o		\
	  $(SRC_PATH)ft_isalpha.o	\
	  $(SRC_PATH)ft_isdigit.o	\
	  $(SRC_PATH)ft_isalnum.o	\
	  $(SRC_PATH)ft_isascii.o	\
	  $(SRC_PATH)ft_isprint.o	\
	  $(SRC_PATH)ft_toupper.o	\
	  $(SRC_PATH)ft_tolower.o	\
	  $(SRC_PATH)ft_memset.o	\
	  $(SRC_PATH)ft_bzero.o		\
	  $(SRC_PATH)ft_memcpy.o	\
	  $(SRC_PATH)ft_memccpy.o	\
	  $(SRC_PATH)ft_strnew.o	\
	  $(SRC_PATH)ft_strdel.o	\
	  $(SRC_PATH)ft_strclr.o	\
	  $(SRC_PATH)ft_striter.o	\
	  $(SRC_PATH)ft_striteri.o	\
	  $(SRC_PATH)ft_strcat.o	\
	  $(SRC_PATH)ft_strsplit.o	\
	  $(SRC_PATH)ft_strsub.o	\
	  $(SRC_PATH)ft_intcmp.o	\
	  $(SRC_PATH)ft_strjoin.o	\
	  $(SRC_PATH)ft_memchr.o	\
	  $(SRC_PATH)ft_2charcmp.o	\
	  $(SRC_PATH)ft_3charcmp.o	\
	  $(SRC_PATH)ft_replace_literal.o	\
	  $(SRC_PATH)ft_check_literal.o		\
	  $(SRC_PATH)ft_memcmp.o	\
	  $(SRC_PATH)ft_atoi_isdigit.o

all: $(NAME)

$(NAME):
	@echo "Crystal is preparing to make your libft"
	@$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
	@echo "Crystal has created all your object files..."
	@mv *.o src/
	@echo "Crystal has successfully moved all the object files to src/"	
	@echo "Crystal is preparing to create your libft.."
	@ar rc $(NAME) $(OBJ)
	@ranlib	$(NAME) 
	@echo "Crystal has successfully created your libft"

clean:
	@rm -f $(OBJ)
	@echo "Crystal has removed all object files.\n"

fclean: clean
	@rm -f $(NAME)
	@echo "Crystal has removed the executable.\n"

re: fclean all
	@echo "Crystal has successfully recompiled your libft.\n"

norme:
	norminette $(SRC)
	@echo "Crystal has successfully normed all your source files.\n"
