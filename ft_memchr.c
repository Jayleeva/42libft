/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:00:05 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:14:01 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s_;

	s_ = s;
	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s_[ft_strlen(s)]);
	i = 0;
	while (i < n)
	{
		if (s_[i] == c)
			return ((char *)&s_[i]);
		i ++;
	}
	return (NULL);
}

/*int main(void)
{
    const char  s[7] = "ABCDEF";
    int         c = 66;
    size_t      n = 2;
    char        *result;

    result = ft_memchr(s, c, n);
    printf("CUSTOM : %s\n", result);
	result = memchr(s, c, n);
	printf("OFFICIAL : %s\n", result);
}*/
