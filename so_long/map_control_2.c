/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:18:33 by raktas            #+#    #+#             */
/*   Updated: 2025/03/24 14:44:52 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_control(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_size_y - 1 > i)
	{
		j = 0;
		while (game->map_size_x - 1 > j)
		{
			if (map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'P' && map[i][j] != 'C')
				map_error(map, "Error\nCharacter is false in map.");
			j++;
		}
		i++;
	}
}

void	wall_control(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (game->map_size_x - 1 > i)
	{
		if (map[0][i] != '1')
			map_error(map, "Error\nThere's a hole in the wall");
		i++;
	}
	i = 0;
	while (map[game->map_size_y - 1][i])
	{
		if (map[game->map_size_y - 1][i] != '1')
			map_error(map, "Error\nThere's a hole in the wall");
		i++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][game->map_size_x - 2] != '1')
			map_error(map, "Error\nThere's a hole in the wall");
		i++;
	}
}

void	map_arg_control(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;
	int	c;

	i = -1;
	p = 0;
	e = 0;
	c = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
		}
	}
	if (p != 1 || e != 1 || c < 1)
		map_error(map, "Error\nItem is false in map.");
}

void	fill(char **map, int player_x, int player_y, t_game *game)
{
	if (player_x < 0 || player_x >= game->map_size_x || player_y < 0
		|| player_y >= game->map_size_y || map[player_y][player_x] == '1'
		|| map[player_y][player_x] == '*')
	{
		return ;
	}
	map[player_y][player_x] = '*';
	fill(map, player_x + 1, player_y, game);
	fill(map, player_x - 1, player_y, game);
	fill(map, player_x, player_y + 1, game);
	fill(map, player_x, player_y - 1, game);
}
