/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:12:04 by raktas            #+#    #+#             */
/*   Updated: 2025/03/24 15:23:47 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_control(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		ft_putstr_fd("Error\nFile type is false.", 2);
		exit(1);
	}
	while (str[i])
		i++;
	if (!(str[i - 1] == 'r' && str[i - 2] == 'e'
			&& str[i - 3] == 'b' && str[i - 4] == '.'))
	{
		ft_putstr_fd("Error\nFile type is false.", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ber_control(argv[1]);
		map(argv[1]);
	}
	else
	{
		ft_putstr_fd("Error\nWrong Argument!", 2);
		exit(1);
	}
}
