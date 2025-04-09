/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:31:42 by raktas            #+#    #+#             */
/*   Updated: 2025/03/24 14:45:30 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_dup(char **map, t_game *game)
{
	int	i;

	game->map = (char **)malloc(sizeof(char *) * (game->map_size_y + 1));
	if (!game->map)
		map_error(map, "Error\nMalloc failed.");
	i = -1;
	while (map[++i])
	{
		game->map[i] = ft_strdup(map[i]);
		if (!game->map[i])
			map_error(map, "Error\nMalloc failed.");
	}
	game->map[i] = NULL;
}

void	map_process(char **map, t_game *game)
{
	int	i;

	find_player(map, game);
	fill(map, game->player.x, game->player.y, game);
	find_exit(map, game);
	find_coin(map, game);
	if (game->coin.x != 0 || game->coin.y != 0 || game->exit.x != 0
		|| game->exit.y != 0)
	{
		while (game->map_size_y--)
			free(game->map[game->map_size_y]);
		free(game->map);
		map_error(map, "Error\nNo path to exit or coin.");
	}
	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}
