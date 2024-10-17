/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:24:07 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:09:47 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (j < (dstsize - i -1) && src[j])
	{
		dest[i + j] = src[j];
		j ++;
	}
	if (dstsize != 0)
		dest[i + j] = '\0';
	j = ft_strlen(src);
	return (i + j);
}

/*int	main(void)
{
	char		dest[7] = "abcdef";
	//char		dest2[7] = "abcdef";
	const char	src[5] = "ahah";
	size_t		dstsize = 11;
	size_t		result;
	
	result = ft_strlcat(dest, src, dstsize);
	printf("CUSTOM : %zu\n%s", result, dest);
	//result = strlcat(dest2, src, dstsize);
	//printf("OFFICIAL : %zu\n%s", result, dest2);
}*/
