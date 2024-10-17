/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:01:33 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:11:58 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i --;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	s[7] = "ABCDCF";
	int			c = 67;
	char		*result;
   
	result = ft_strrchr(s, c);
	printf("CUSTOM : %s\n", result);
	result = strrchr(s, c);
	printf("OFFICIAL : %s\n", result);	
}*/
