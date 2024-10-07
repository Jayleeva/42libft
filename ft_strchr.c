/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:19:26 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/07 14:30:15 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*dest_;
	const char		*src_;
	char			temp;

	dest_ = dest;
	src_ = src;
	while (i < n)
	{
		temp = src_[i];
		dest_[i] = temp;
		write(1, "ok", 3);
		i ++;
	}
	dest_[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	//size_t		i;
	//size_t		j;
	char		*s_;

	c = (unsigned char)c;
	//i = 0;
	//j = 0;
	
	if (c == '\0')
	{
		while (*s)
			*s ++;
		return (s);
	}
	//s_ = ft_memmove(s_, s, ft_strlen(s));
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		*s ++;
	}
	return (NULL);
}

int	main(void)
{
	const char	s[7] = "ABCDEF";
	int			c = 68;
	char		*result;
   
	result = ft_strchr(s, c);
	printf("\n%s", result);
	return (0);
}
