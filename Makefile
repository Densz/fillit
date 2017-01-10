#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzheng <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 13:30:45 by dzheng            #+#    #+#              #
#    Updated: 2016/12/14 17:48:47 by dzheng           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
LIB_PATH = ./libft/
LIB = $(LIB_PATH)/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
PATH_SRC = ./srcs/
SRCS = $(PATH_SRC)main.c \
	$(PATH_SRC)verif_grid.c \
	$(PATH_SRC)read_file.c \
	$(PATH_SRC)get_tetrimino.c \
	$(PATH_SRC)solver.c

#COLORS
C_GOOD			=	"\033[32m"

#MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$

all: $(NAME)

$(NAME): 
		make -C ./libft/
		@$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)
		@echo "Compiling" [ $(NAME) ] $(SUCCESS)
cc:
		@$(CC) $(SRC) $(LIB) -o $(NAME)

cexec: cc
		./fillit valid_sample_fillit
clean:
		make -C ./libft/ clean
fclean: clean
		/bin/rm -f $(NAME)
		make -C ./libft/ fclean

re: fclean all