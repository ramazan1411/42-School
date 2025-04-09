/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:07 by raktas            #+#    #+#             */
/*   Updated: 2025/01/31 12:55:50 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check(unsigned long long result, int sign)
{
	if ((sign == 1 && result > 2147483647) || (sign == -1
			&& result > 2147483648))
		return (0);
	else
		return (1);
}

static int	ft_white_space(int i, const char *str)
{
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

static int	sign_checker(int i, const char *str)
{
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		i++;
	return (i);
}

static int	sign_finder(int i, const char *str, t_stack *stack, int *arr)
{
	int	sign;

	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
	{
		free(arr);
		error_a(stack);
	}
	return (sign);
}

int	ft_atoi_max(const char *str, t_stack *stack, int *arr)
{
	int			i;
	long long	result;
	int			sign;
	int			re;

	i = 0;
	result = 0;
	sign = 1;
	re = 0;
	i += ft_white_space(i, str);
	sign = sign_finder(i, str, stack, arr);
	i += sign_checker(i, str);
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = ((result * 10) + (str[i++] - 48));
		re = ft_check(result, sign);
		if (re == 0)
		{
			free(arr);
			error_a(stack);
		}
	}
	return ((int)(result * sign));
}
