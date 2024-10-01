# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 10:45:16 by cyglardo          #+#    #+#              #
#    Updated: 2024/10/01 16:59:43 by cyglardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = libft.h main.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isacii.c ft_isprint.c ft_strlen.c ft_memset.c

NAME = name
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f
RMDIR = /bin/rmdir

.PHONY : all clean fclean re
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) 
fclean:
	$(RM) $(NAME)

re: fclean all
