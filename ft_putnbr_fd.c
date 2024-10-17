/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:53:22 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/17 16:32:59 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i ++;
	}
}

/*int	main(void)
{
	int	n = -2147483648;
	int	fd = 1;

	ft_putnbr_fd(n, fd);
}*/
