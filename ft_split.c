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

#include "ft_strchr.c"
#include "ft_substr.c"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/*void	ft_print(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("\n%s", tab[i]);
		i ++;
	}
}*/

size_t	ft_strlen_(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
		i ++;
	return (i);
}

char	**cut(char **result, int nb, char const *s, char c)
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
		result[i] = ft_substr(result[i], 0, ft_strlen_(result[i], c));
		i ++;
	}
	ft_print(result);
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
		result[i] = (char *)malloc((ft_strlen_(s, '\0') + 1) * sizeof(char));
		if (result[i] == NULL)
			return (NULL);
		i++;
	}
	result = cut(result, nb, s, c);
	return (result);
}

/*int	main(void)
{
	char const	s[] = "Salut ca va?|-Non et toi?|-Bien merci.|-Cool.";
	char		c = '|';

	ft_split(s, c);
}*/
