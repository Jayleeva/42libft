/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:59:32 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:16:42 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;

	ptr = malloc((nelem + 1) * elsize);
	if (ptr == NULL)
		return (NULL);
	return ((char *)ptr);
}

/*int	main(void)
{
	size_t	nelem = 5;
	size_t	elsize = sizeof(char);
	char	*result;
	char	*result2;

	result = ft_calloc(nelem, elsize);
	result = ft_memset(result, 65, nelem);
	printf("CUSTOM : %s\n", result);
	result2 = calloc(nelem, elsize);
	result2 = ft_memset(result2, 65, nelem);
	printf("OFFICIAL : %s\n", result2);
}*/
