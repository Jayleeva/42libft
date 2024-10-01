# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 10:45:16 by cyglardo          #+#    #+#              #
#    Updated: 2024/10/01 11:41:50 by cyglardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = main.c function.c 

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
