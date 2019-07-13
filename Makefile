# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcreux <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 22:02:03 by jcreux            #+#    #+#              #
#    Updated: 2019/06/17 22:08:27 by jcreux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_SRC = ./
PATH_INC = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fractol.h

SRCS = main.c \
	   display.c \
	   error.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRCS)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
