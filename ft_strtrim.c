/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:46:48 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/14 10:27:04 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *) malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		result[j] = s[i];
		j ++;
		i ++;
	}
	result[j] = '\0';
	return (result);
}

int	is_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*copy;

	copy = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	copy = (char *)s1;
	end = ft_strlen(copy) -1;
	start = 0;
	while (is_in_set(set, copy[start]) == 1)
		start ++;
	while (is_in_set(set, copy[end]) == 1)
		end --;
	copy = ft_substr(copy, start, end - start + 1);
	return (copy);
}

/*int	main(void)
{
	const char	s1[] = "?!?ah bah? voila?!?!";
	const char	set[] = "?!";
	char		*result;

	result = ft_strtrim(s1, set);
	printf("\n\n%s", result);
}*/