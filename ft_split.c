/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:45:53 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/22 17:46:46 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	ft_strlen_to(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
		i ++;
	return (i);
}

static char	**fill_tab(char **tab, int nb, char const *s, char c)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		tab[i] = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[0] = (char *)s;
	i = 1;
	while (i < nb)
	{
		tab[i] = ft_strchr(tab[i -1], c) + 1; //si plusieurs sep a suivre, la couille
		i ++;
	}
	i = 0;
	while (i < nb)
	{
		tab[i] = ft_substr(tab[i], 0, ft_strlen_to(tab[i], c));
		i ++;
	}
	return (tab);
}

static char	**clean_tab(char **result, char **tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		result[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i ++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	**result;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if ((i == 0 || s[i -1] == c) && s[i] != c)
			nb ++;
		i ++;
	}
	tab = (char **)malloc((nb + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab = fill_tab(tab, nb, s, c);
	result = (char **)malloc((nb + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = clean_tab(result, tab, nb);
	free(tab);
	return (result);
}

/*int	main(void)
{
	char const	s[] = "Salut ca va?|-Non et toi?|-Bien merci.|-Cool.";
	char		c = '|';
	char		**result;
	int			i;

	result = ft_split(s, c);
	i = 0;
	while (result[i])
	{
		printf("\n%s", result[i]);
		i ++;
	}
}*/
