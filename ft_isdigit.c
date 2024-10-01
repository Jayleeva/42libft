/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:26:27 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/01 13:35:14 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*int	main(int argc, char **argv)
{
	int	result;

	argc = 1;
	result = ft_isdigit(argv[1][0]);
	printf("CUSTOM = %d/n", result);
	result = isdigit(argv[1][0]);
	printf("OFFICIAL = %d/n", result);
}*/
