/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:11:00 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:11:24 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_tolower(int c)
{
	c = (unsigned char)c;
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*int	main(void)
{
	int	c;

	c = 65;
	c = ft_tolower(c);
	printf("CUSTOM : %d\n", c);
	c = 65;
	c = tolower(c);
	printf("OFFICIAL : %d\n", c);
}*/
