/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:38:52 by raktas            #+#    #+#             */
/*   Updated: 2025/03/21 15:49:33 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&img_width, &img_height);
	game->coin_img = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm",
			&img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&img_width, &img_height);
	game->empty_img = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm",
			&img_width, &img_height);
}

void	draw_map(t_game *game)
{
	game->map_coord.y = -1;
	while (++game->map_coord.y < game->map_size_y)
	{
		game->map_coord.x = -1;
		while (++game->map_coord.x < game->map_size_x - 1)
		{
			if (game->map[game->map_coord.y][game->map_coord.x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall_img,
					game->map_coord.x * 48, game->map_coord.y * 48);
			else if (game->map[game->map_coord.y][game->map_coord.x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, game->map_coord.x * 48,
					game->map_coord.y * 48);
			else if (game->map[game->map_coord.y][game->map_coord.x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->coin_img,
					game->map_coord.x * 48, game->map_coord.y * 48);
			else if (game->map[game->map_coord.y][game->map_coord.x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
					game->map_coord.x * 48, game->map_coord.y * 48);
			else
				mlx_put_image_to_window(game->mlx, game->window,
					game->empty_img, game->map_coord.x * 48,
					game->map_coord.y * 48);
		}
	}
}

int	all_coin_collected(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size_y)
	{
		j = 0;
		while (j < game->map_size_x - 1)
		{
			if (game->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	destroy_window(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_size_y)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx, game->coin_img);
	mlx_destroy_image(game->mlx, game->empty_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	move_player(t_game *game, int dx, int dy)
{
	int	x;
	int	y;

	x = game->player.x + dx;
	y = game->player.y + dy;
	if (x >= 0 && x < game->map_size_x && y >= 0 && y < game->map_size_y
		&& game->map[y][x] != '1')
	{
		if ((all_coin_collected(game) == 1 && game->map[y][x] == 'E'))
		{
			ft_printf("You won! Moves: %d\n", game->moves);
			destroy_window(game);
		}
		if (game->player.x == game->exit.x && game->player.y == game->exit.y)
			game->map[game->player.y][game->player.x] = 'E';
		else
			game->map[game->player.y][game->player.x] = '0';
		game->player.x = x;
		game->player.y = y;
		game->map[game->player.y][game->player.x] = 'P';
		draw_map(game);
		return (1);
	}
	return (0);
}
