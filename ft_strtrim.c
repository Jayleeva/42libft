/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:46:48 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/10 15:06:55 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_;
	const char	*src_;

	dest_ = dest;
	src_ = src;
	i = 0;
	while (i < n)
	{
		dest_[i] = src_[i];
		i ++;
	}
	dest_[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*copy;
	size_t		i;
	
	copy = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	copy = (char *)s1;
	i = 0;
	while (set[i])
	{
		start = 0;
		while (copy[start] == set[i])
			start ++;
		copy = &copy[start];
		end = ft_strlen(copy) -1;
		while (copy[end] == set[i])
			end --;
		copy = ft_memcpy(copy, copy, end); 
		i ++;
	}
	return (copy);
}

int	main(void)
{
	const char	s1[] = "?!?ah bah? voila?!?!";
	const char	set[] = "?!";
	char		*result;

	result = ft_strtrim(s1, set);
	printf("\n%s", result);
}
