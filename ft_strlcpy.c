/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:21:05 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/03 11:41:43 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize && src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	if (dstsize != 0)
		dest[i -1] = '\0';
	return (i);
}

/*int	main(void)
{
	char		dest[7] = "abcdef";
	const char	src[9] = "ahahahah";
	size_t		dstsize = 7;
	size_t		result;

	result = ft_strlcpy(dest, src, dstsize);
	printf("%s\n", dest);
	printf("%lu", result);
}*/
