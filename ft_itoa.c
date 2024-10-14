/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:12:43 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/14 17:58:12 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memset.c"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strcat_(char *result, int n)
{
	int	i;

	i = 0;
	while (result[i])
	{
		result[i] = n;
		i ++;
	}
	return (result);
}

void	ft_putnbr_(int nb, char *result)
{
	if (nb > 9)
	{
		ft_putnbr_(nb / 10, result);
		ft_putnbr_(nb % 10, result);
	}
	else
		result = ft_strcat_(result, nb + '0');
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	int		temp;
	char	*result;
	
	result = (char *)malloc((11 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result = ft_memset(result, '+', 11); 
	i = 0;
	if (n < 0)
	{
		n = n * -1;
		result[0] = '-';
		i ++;
	}
	ft_putnbr_(n, result);
	return (result);
}

int	main(void)
{
	int		n = -2147483648;
	char	*result;

	result = ft_itoa(n);
	printf("\n%s", result);
}
