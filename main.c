/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:32:16 by cyglardo          #+#    #+#             */
/*   Updated: 2024/10/01 15:15:27 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	result;

	result = ft_isalnum(argv[1][0]);
	printf("CUSTOM = %d\n", result);
	result = isalnum(argv[1][0]);
	printf("OFFICIAL = %d\n", result);
}
