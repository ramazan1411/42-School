# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raktas <raktas@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 03:49:34 by raktas            #+#    #+#              #
#    Updated: 2025/03/24 18:01:56 by raktas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

MLX = minilibx-linux/libmlx.a
LIBFT = libft/libft.a
PRINT = ft_printf/libftprintf.a

SRCS = main.c error.c map_control_1.c map_control_2.c map_dup_and_process.c find_pce.c get_next_line.c get_next_line_utils.c game.c image.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C libft all
	@make -C ft_printf all
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS_MLX) $(LIBFT) $(PRINT) $(MLX) -o $(NAME)

all: $(NAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	@rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all
