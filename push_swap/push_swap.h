/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:49:12 by raktas            #+#    #+#             */
/*   Updated: 2025/01/31 12:49:13 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	char	**args;
	int		*stack_a;
	int		*stack_b;
	int		cost;
	int		b_max_index;
	int		size_a;
	int		size_b;
}			t_stack;

typedef struct s_moves
{
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		cost;
}			t_moves;

int			*number_to_array(char **arg, t_stack *stack);
int			ft_atoi_max(const char *str, t_stack *stack, int *arr);
void		error_a(t_stack *stack);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);
void		create_stack(t_stack *stack);
void		is_sorted(t_stack *stack);
void		sort_two(t_stack *stack);
void		sort_three(t_stack *stack);
void		sort_stack(t_stack *stack);
void		cost_a(t_stack *stack, int index, t_moves *moves);
void		cost_b(t_stack *stack, int index, t_moves *moves);
void		doubly_cost(t_moves *moves);
void		initiate_moves(t_moves *moves);
void		make_cheapest(t_stack *stack, t_moves *moves);
void		make_and_push_a(t_stack *stack, t_moves *moves);
int			is_sorted_a(t_stack *stack);
void		make_b(t_stack *stack, t_moves *moves);
int			get_next_bigger(t_stack *stack, int index_b);
int			get_next_smaller(t_stack *stack, int index_a);
int			find_max_b(t_stack *stack);
int			find_min_b(t_stack *stack);
int			a_has_greater_value(t_stack *stack, int i);
int			find_min_index_a(t_stack *stack);
void		stack_free(t_stack *stck);

#endif