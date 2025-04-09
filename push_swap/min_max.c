/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:48:49 by raktas            #+#    #+#             */
/*   Updated: 2025/01/31 12:48:50 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_smaller(t_stack *stack, int index_a)
{
	int		i;
	int		j;
	int		index;
	long	smaller;

	i = stack->stack_a[index_a];
	j = 0;
	index = 0;
	smaller = -2147483649;
	while (j < stack->size_b)
	{
		if (stack->stack_b[j] > smaller && i > stack->stack_b[j])
		{
			index = j;
			smaller = stack->stack_b[j];
		}
		j++;
	}
	return (index);
}

int	get_next_bigger(t_stack *stack, int index_b)
{
	int		i;
	int		j;
	int		index;
	long	bigger;

	i = stack->stack_b[index_b];
	j = 0;
	index = 0;
	bigger = 2147483648;
	while (j < stack->size_a)
	{
		if (stack->stack_a[j] < bigger && i < stack->stack_a[j])
		{
			index = j;
			bigger = stack->stack_a[j];
		}
		j++;
	}
	return (index);
}

int	find_max_b(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack_b[0];
	stack->b_max_index = 0;
	while (i < stack->size_b)
	{
		if (stack->stack_b[i] > max)
		{
			max = stack->stack_b[i];
			stack->b_max_index = i;
		}
		i++;
	}
	return (max);
}

int	find_min_b(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stack_b[0];
	while (i < stack->size_b)
	{
		if (stack->stack_b[i] < min)
			min = stack->stack_b[i];
		i++;
	}
	return (min);
}

int	find_min_index_a(t_stack *stack)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = 0;
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] < stack->stack_a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}
