/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:49:20 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/03 12:10:41 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
//#include <unistd.h>

int	ft_toupper(int c)
{
	c = (unsigned char)c;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*int	main(void)
{
	int	c;

	c = 93;
	c = ft_toupper(c);
	write(1, &c, 1);
}*/
