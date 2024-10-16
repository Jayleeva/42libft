/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:45:53 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/14 14:12:12 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_strchr.c"
#include "ft_substr.c"
#include <stdlib.h>
#include <string.h>
//#include <stdio.h>

size_t	ft_strlen_to(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
		i ++;
	return (i);
}

char	**fill_tab(char **result, int nb, char const *s, char c)
{
	int	i;

	result[0] = (char *)s;
	i = 1;
	while (i < nb)
	{
		result[i] = ft_strchr(result[i -1], c) + 1;
		i ++;
	}
	i = 0;
	while (i < nb)
	{
		result[i] = ft_substr(result[i], 0, ft_strlen_to(result[i], c));
		i ++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		nb;

	i = 0;
	nb = 1;
	while (s[i])
	{
		if (s[i] == c)
			nb ++;
		i ++;
	}
	result = (char **)malloc((nb + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		result[i] = (char *)malloc((ft_strlen_to(s, '\0') + 1) * sizeof(char));
		if (result[i] == NULL)
			return (NULL);
		i++;
	}
	result = fill_tab(result, nb, s, c);
	return (result);
}

/*void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("\n%s", tab[i]);
		i ++;
	}
}

int	main(void)
{
	char const	s[] = "Salut ca va?|-Non et toi?|-Bien merci.|-Cool.";
	char		c = '|';
	char		**result;

	result = ft_split(s, c);
	ft_print_tab(result);
}*/
