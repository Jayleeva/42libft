# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 10:45:16 by cyglardo          #+#    #+#              #
#    Updated: 2024/10/17 13:55:43 by cyglardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = libft.h $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

$(NAME): $(OBJ)
     ar -rcs $(NAME) $(OBJ) 

all: $(NAME) clean
clean:
	rm -f $(OBJ)
fclean:
	clean rm -f $(NAME)
re: fclean $(NAME)

.PHONY : all clean fclean re
