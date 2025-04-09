/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:48:54 by raktas            #+#    #+#             */
/*   Updated: 2025/01/31 12:48:55 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(int *arr, int size, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				error_a(stack);
			}
			j++;
		}
		i++;
	}
}

int	*malloc_and_convert(char **arg, int size, t_stack *stack)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		arr[i] = ft_atoi_max(arg[i], stack, arr);
		i++;
	}
	return (arr);
}

int	*number_to_array(char **arg, t_stack *stack)
{
	int	size;
	int	*arr;

	size = 0;
	while (arg[size])
		size++;
	arr = malloc_and_convert(arg, size, stack);
	check_duplicates(arr, size, stack);
	return (arr);
}
