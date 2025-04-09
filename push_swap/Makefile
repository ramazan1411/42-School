# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 12:45:48 by raktas            #+#    #+#              #
#    Updated: 2025/01/31 12:45:52 by raktas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
C_FLAGS = -Wall -Wextra -Werror -g
SRCS =  push_swap.c \
		atoi.c \
		cheap.c \
		cost.c \
		stack_init.c \
		min_max.c \
		number_converter.c \
		reverse_rotate.c \
		rotate.c \
		sort_stack.c \
		operations.c

OBJ =$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C ft_printf/
	@$(CC) $(C_FLAGS) $(OBJ) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

%.o: %.c
	@$(CC) $(C_FLAGS) -c $< -o $@

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(NAME) $(NAME_C)

clean:
	@make clean -C ft_printf/
	@make clean -C libft/
	@rm -rf $(OBJ) $(OBJ_C)

re: fclean all

.PHONY:	all clean fclean re