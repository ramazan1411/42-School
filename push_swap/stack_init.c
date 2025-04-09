/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:53:33 by raktas            #+#    #+#             */
/*   Updated: 2025/01/31 12:53:34 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack *stack)
{
	stack->stack_b = (int *)malloc(sizeof(int) * stack->size_a);
	stack->cost = 0;
	stack->size_b = 0;
}

void	is_sorted(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i;
		while (j < stack->size_a - 1)
		{
			if (stack->stack_a[j] > stack->stack_a[j + 1])
			{
				return ;
			}
			j++;
		}
		i++;
	}
	stack_free(stack);
	free(stack->stack_a);
	free(stack->stack_b);
	exit(1);
}

int	is_sorted_a(t_stack	*stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i;
		while (j < stack->size_a - 1)
		{
			if (stack->stack_a[j] > stack->stack_a[j + 1])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	sort_two(t_stack *stack)
{
	sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->stack_a[0];
	b = stack->stack_a[1];
	c = stack->stack_a[2];
	if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > c && b < c)
		ra(stack);
	else if (b > a && a > c)
		rra(stack);
	else if (b > c && c > a)
	{
		sa(stack);
		ra(stack);
	}
	else if (c > a && a > b)
		sa(stack);
}
