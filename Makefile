# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 10:45:16 by cyglardo          #+#    #+#              #
#    Updated: 2024/10/21 12:22:54 by cyglardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = part1/ft_isalpha.c part1/ft_isdigit.c part1/ft_isalnum.c part1/ft_isascii.c part1/ft_isprint.c part1/ft_strlen.c part1/ft_memset.c part1/ft_bzero.c part1/ft_memcpy.c part1/ft_memmove.c part1/ft_strlcpy.c part1/ft_strlcat.c part1/ft_toupper.c part1/ft_tolower.c part1/ft_strchr.c part1/ft_strrchr.c part1/ft_strncmp.c part1/ft_memchr.c part1/ft_memcmp.c part1/ft_strnstr.c part1/ft_atoi.c part1/ft_calloc.c part1/ft_strdup.c part2/ft_substr.c part2/ft_strjoin.c part2/ft_strtrim.c part2/ft_split.c part2/ft_itoa.c part2/ft_strmapi.c part2/ft_striteri.c part2/ft_putchar_fd.c part2/ft_putstr_fd.c part2/ft_putendl_fd.c part2/ft_putnbr_fd.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) libft.h
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean re
