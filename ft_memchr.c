/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:00:05 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/21 15:37:52 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_;
	unsigned char	c_;

	s_ = (unsigned char *)s;
	c_ = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_[i] == c_)
			return ((void *)&s_[i]);
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
