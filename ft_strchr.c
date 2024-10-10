/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:19:26 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/10 09:58:50 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i ++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	s[7] = "ABCDEF";
	int			c = 68;
	char		*result;
   
	result = ft_strchr(s, c);
	printf("\n%s", result);
	return (0);
}*/
