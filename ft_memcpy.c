/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:21:42 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/10 14:16:08 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_;
	const char	*src_;

	dest_ = dest;
	src_ = src;
	i = 0;
	while (i < n)
	{
		dest_[i] = src_[i];
		i ++;
	}
	dest_[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char		dest[7] = "abcdef";
	const char	src[7] = "ahahah";
	size_t		n = 5;
	char		*result;

	result = ft_memcpy(dest, src, n);
	printf("%s", result);
}*/
