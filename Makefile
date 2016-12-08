#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 13:30:45 by dzheng            #+#    #+#              #
#    Updated: 2016/12/07 10:01:31 by dzheng           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
PATH_SRC = ./srcs/
SRC = $(PATH_SRC)main.c \
	$(PATH_SRC)verif_grid.c \
	$(PATH_SRC)read_file.c \
	$(PATH_SRC)get_tetrimino.c

#COLORS
C_GOOD			=	"\033[32m"

#MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$

all: $(NAME)

$(NAME): 
		$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)
		@echo "Compiling" [ $(NAME) ] $(SUCCESS)
clean:
		/bin/rm -f $(OBJ)
fclean: clean
		/bin/rm -f $(NAME)

re: fclean all