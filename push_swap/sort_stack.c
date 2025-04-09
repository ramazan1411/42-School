/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:49:31 by raktas            #+#    #+#             */
/*   Updated: 2025/01/31 12:49:32 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	cost(t_stack *stack, int i)
{
	t_moves	moves;
	int		max;
	int		min;
	int		next_smaller;

	initiate_moves(&moves);
	min = find_min_b(stack);
	max = find_max_b(stack);
	if (stack->stack_a[i] > max || stack->stack_a[i] < min)
	{
		cost_b(stack, stack->b_max_index, &moves);
		cost_a(stack, i, &moves);
	}
	else
	{
		next_smaller = get_next_smaller(stack, i);
		cost_b(stack, next_smaller, &moves);
		cost_a(stack, i, &moves);
	}
	doubly_cost(&moves);
	moves.cost = moves.ra + moves.rb + moves.rr + moves.rra + moves.rrb
		+ moves.rrr;
	return (moves);
}

void	push_to_b(t_stack *stack)
{
	t_moves	moves;
	t_moves	cheapest;
	int		i;

	while (stack->size_a > 3)
	{
		initiate_moves(&moves);
		initiate_moves(&cheapest);
		cheapest = cost(stack, 0);
		i = 1;
		while (i < stack->size_a)
		{
			moves = cost(stack, i);
			if (moves.cost < cheapest.cost)
				cheapest = moves;
			i++;
		}
		make_cheapest(stack, &cheapest);
	}
}

void	push_to_a(t_stack *stack)
{
	t_moves	push_a;
	int		index;
	int		i;

	i = 0;
	while (stack->size_b > 0)
	{
		initiate_moves(&push_a);
		if (a_has_greater_value(stack, i) == 1)
			index = get_next_bigger(stack, i);
		else
			index = find_min_index_a(stack);
		cost_a(stack, index, &push_a);
		make_and_push_a(stack, &push_a);
	}
}

void	final(t_stack *stack)
{
	int		index;
	t_moves	rot_a;

	initiate_moves(&rot_a);
	index = find_min_index_a(stack);
	cost_a(stack, index, &rot_a);
	while (is_sorted_a(stack) == 0)
	{
		if (rot_a.ra > 0)
			ra(stack);
		else
			rra(stack);
	}
}

void	sort_stack(t_stack *stack)
{
	pb(stack);
	pb(stack);
	push_to_b(stack);
	if (is_sorted_a(stack) == 0)
	{
		if (stack->size_a == 3)
			sort_three(stack);
		else
			sort_two(stack);
	}
	push_to_a(stack);
	final(stack);
}
