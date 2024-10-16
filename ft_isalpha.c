/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:10:18 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/01 13:34:51 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z') 
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (2);
	else
		return (0);
}

/*int	main(void)
{
	int	i = 'a';
	int	result;

	result = ft_isalpha(i);
	printf("CUSTOM = %d\n", result);
	result = isalpha(i);
	printf("OFFICIAL = %d\n", result);
}*/
