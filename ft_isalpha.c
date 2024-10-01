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
/*#include <stdio.h>
#include <ctype.h>*/

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*int	main(int argc, char **argv)
{
	int	result;

	argc = 1;
	result = ft_isalpha(argv[1][0]);
	printf("CUSTOM = %d\n", result);
	result = isalpha(argv[1][0]);
	printf("OFFICIAL = %d\n", result);
}*/
