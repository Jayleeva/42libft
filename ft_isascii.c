/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:42:36 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:03:40 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	int	i = -1;
	int	result;

	result = ft_isascii(i);
	printf("CUSTOM = %d\n", result);
	result = isascii(i);
	printf("OFFICIAL = %d\n", result);
}*/
