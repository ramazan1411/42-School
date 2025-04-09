/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:50:03 by raktas            #+#    #+#             */
/*   Updated: 2025/03/21 15:51:02 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size_y - 1)
	{
		j = 0;
		while (j < game->map_size_x - 1)
		{
			if (map[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_coin(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_size_y - 1 > i)
	{
		j = 0;
		while (game->map_size_x - 1 > j)
		{
			if (map[i][j] == 'C')
			{
				game->coin.x = j;
				game->coin.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_exit(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size_y)
	{
		j = 0;
		while (j < game->map_size_x - 1)
		{
			if (map[i][j] == 'E')
			{
				game->exit.x = j;
				game->exit.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
