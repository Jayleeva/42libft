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

NAME = libft.a

SRC = libft.h ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ =

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)
fclean:
	clean rm -f $(NAME)
re: fclean $(NAME)

.PHONY : all clean fclean re
