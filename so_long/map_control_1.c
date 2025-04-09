/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:32:03 by raktas            #+#    #+#             */
/*   Updated: 2025/03/24 20:51:29 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->map_size_x = 0;
	game->map_size_y = 0;
	game->moves = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->coin.x = 0;
	game->coin.y = 0;
	game->map_coord.x = 0;
	game->map_coord.y = 0;
	game->map = NULL;
}

void	map_size_y(int fd, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	game->map_size_y = i;
	if (i == 0)
	{
		ft_putstr_fd("Error\nMap is false", 2);
		exit(1);
	}
}

void	map_size_x(int fd, char **map, t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	i = 0;
	while (map[0][i])
		i++;
	len = i;
	game->map_size_x = len;
}

void	rectangle_control(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_size_y > i)
	{
		j = 0;
		while (map[i][j])
			j++;
		if (i == game->map_size_y - 1 && j != game->map_size_x - 1)
			map_error(map, "Error\nMap isn't rectangle");
		else if (i != game->map_size_y - 1 && j != game->map_size_x)
			map_error(map, "Error\nMap isn't rectangle");
		i++;
	}
}

void	map(char *str)
{
	char	**map;
	t_game	game;
	int		fd1;
	int		fd2;

	fd1 = open(str, O_RDWR);
	fd2 = open(str, O_RDWR);
	if (fd1 == -1 || fd2 == -1)
	{
		ft_putstr_fd("Error\nFile didn't open.", 2);
		exit(1);
	}
	init_game(&game);
	map_size_y(fd1, &game);
	map = malloc(sizeof(char *) * (game.map_size_y + 1));
	map_size_x(fd2, map, &game);
	rectangle_control(map, &game);
	wall_control(map, &game);
	char_control(map, &game);
	map_arg_control(map);
	map_dup(map, &game);
	map_process(map, &game);
	game_fun(&game);
}
