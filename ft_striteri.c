/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:17:34 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/15 15:54:54 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*void	ft_toupper_(unsigned int i, char *str)
{
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i ++;
	}
	printf("%s", s);
}

/*int	main(void)
{
	char	s[] = "aBc";

	ft_striteri(s, ft_toupper_);
}*/
