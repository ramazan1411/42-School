/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:11:56 by raktas            #+#    #+#             */
/*   Updated: 2025/03/24 13:57:53 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_coordinat
{
	int		x;
	int		y;
}			t_coordinat;

typedef struct s_game
{
	int			map_size_x;
	int			map_size_y;
	int			moves;
	char		**map;
	void		*mlx;
	void		*window;
	void		*wall_img;
	void		*player_img;
	void		*coin_img;
	void		*exit_img;
	void		*empty_img;
	t_coordinat	player;
	t_coordinat	exit;
	t_coordinat	coin;
	t_coordinat	map_coord;
}				t_game;

void	ber_control(char *str);
void	init_game(t_game *game);
void	map_size_y(int fd, t_game *game);
void	map_size_x(int fd, char **map, t_game *game);
void	map(char *str);
void	rectangle_control(char **map, t_game *game);
void	wall_control(char **map, t_game *game);
void	char_control(char **map, t_game *game);
void	map_arg_control(char **map);
void	map_dup(char **map, t_game *game);
void	map_process(char **map, t_game *game);
void	map_error(char **map, char *error_message);
void	find_player(char **map, t_game *game);
void	find_coin(char **map, t_game *game);
void	find_exit(char **map, t_game *game);
void	game_fun(t_game *game);
void	found_exit(t_game *game);
void	load_images(t_game *game);
void	draw_map(t_game *game);
void	init_image(t_game *image);
void	fill(char **map, int player_x, int player_y, t_game *game);
int		all_coin_collected(t_game *game);
int		key_process(int keycode, t_game *game);
int		destroy_window(t_game *game);
int		move_player(t_game *game, int dx, int dy);

#endif