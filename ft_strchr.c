/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:19:26 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/03 15:13:00 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*from_ptr(const char *s, size_t ptr)
{
	int		i;
	char	*s_;

	i = 0;
	while (s[ptr])
	{
		s_[i] = s[ptr];
		ptr ++;
	}
	return (s_);
}

char	*ft_strchr(const char *s, int c)
{
	int			i;
	size_t		ptr;

	c = (unsigned char)c;
	
	if (c == '\0')
	{
		ptr = ft_strlen(s);
		return (from_ptr(s, ptr));
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (from_ptr(s, i));
		i ++;
	}
	return (NULL);
}

int	main(void)
{
	const char	s[7] = "ABCDEF";
	int			c = 68;
	char		*result;
   
	result = ft_strchr(s, c);
	printf("%s", result);
}
