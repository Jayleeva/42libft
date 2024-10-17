/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:21:05 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:09:23 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
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
	i = ft_strlen(src);
	return (i);
}

/*int	main(void)
{
	char		dest[7] = "abcdef";
	char		dest2[7] = "abcdef";
	const char	src[9] = "ahahahah";
	size_t		dstsize = 7;
	size_t		result;

	result = ft_strlcpy(dest, src, dstsize);
	printf("CUSTOM : %zu\n%s\n", result, dest);
	result = strlcpy(dest2, src, dstsize);
	printf("OFFICIAL : %zu\n%s\n", result, dest2);
}*/
