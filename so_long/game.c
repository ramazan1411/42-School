/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:32:53 by raktas            #+#    #+#             */
/*   Updated: 2025/03/24 19:19:10 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_process(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		ft_printf("You lost! Moves: %d\n", game->moves);
		destroy_window(game);
		exit(0);
	}
	else if ((keycode == 119 && move_player(game, 0, -1) == 1)
		|| (keycode == 97 && move_player(game, -1, 0) == 1)
		|| (keycode == 115 && move_player(game, 0, 1) == 1)
		|| (keycode == 100 && move_player(game, 1, 0) == 1))
	{
		game->moves++;
		ft_printf("moves: %d\n", game->moves);
	}
	return (0);
}

void	found_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size_y)
	{
		j = 0;
		while (j < game->map_size_x - 1)
		{
			if (game->map[i][j] == 'E')
			{
				game->exit.x = j;
				game->exit.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	exit(0);
}

void	game_fun(t_game *game)
{
	found_exit(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, ((game->map_size_x - 1) * 48),
			((game->map_size_y) * 48), "Bitcoin_Mining");
	game->moves = 0;
	load_images(game);
	draw_map(game);
	mlx_hook(game->window, 2, 1L << 0, key_process, game);
	mlx_hook(game->window, 17, 1L << 17, destroy_window, game);
	mlx_loop(game->mlx);
}
