/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:32:03 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:09:00 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_;
	const char	*src_;
	char		temp;

	dest_ = dest;
	src_ = src;
	i = 0;
	while (i < n)
	{
		temp = src_[i];
		dest_[i] = temp;
		i ++;
	}
	return (dest);
}

/*int	main(void)
{
	char		dest[7] = "abcdef";
	char		dest2[7] = "abcdef";
	const char	src[7] = "ahahah";
	size_t		n = 5;
	char		*result;

	result = ft_memmove(dest, src, n);	
	printf("CUSTOM : %s\n", result);
	result = memmove(dest2, src, n);
	printf("OFFICIAL : %s\n", result);
}*/
