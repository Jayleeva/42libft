/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:58:58 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/10 10:18:06 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (i < n)
	{
		j = 0;
		while (to_find[j] == str[i + j] && (i + j) < n)
			j ++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i ++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	str[100] = "Mais vous savez moi je crois pas...";
	const char	to_find[10] = "savez";
	size_t		n = 14;
	char		*result;
	
	result = ft_strnstr(str, to_find, n);
	printf("CUSTOM : %s", result);
}*/
