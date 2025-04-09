/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:49:06 by raktas            #+#    #+#             */
/*   Updated: 2025/01/31 12:49:07 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	space_checker(int argc, char **argv)
{
	int	i;
	int	j;
	int	counter;

	i = 1;
	j = 0;
	counter = 0;
	while (i < argc)
	{
		j = 0;
		counter = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				counter++;
			j++;
		}
		if (j == counter || ft_strncmp(argv[i], "", 42) == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	num_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != 32
				&& argv[i][j] != 45 && argv[i][j] != 43)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			if ((argv[i][j + 1] == 45 || argv[i][j + 1] == 43)
				&& (argv[i][j] >= 48 && argv[i][j] <= 57))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

char	**combine_and_split_numbers(int argc, char **argv, int *size)
{
	char	*joined;
	char	**split;
	char	*temp;
	int		i;

	if (argc < 2)
		return (NULL);
	joined = ft_strdup(argv[1]);
	i = 2;
	while (i < argc)
	{
		temp = joined;
		joined = ft_strjoin(temp, " ");
		free(temp);
		temp = joined;
		joined = ft_strjoin(temp, argv[i++]);
		free(temp);
	}
	split = ft_split(joined, ' ');
	free(joined);
	i = 0;
	while (split[i])
		i++;
	*size = i;
	return (split);
}

void	stack_free(t_stack *stck)
{
	int	i;

	i = -1;
	while (stck->args[++i])
		free(stck->args[i]);
	free(stck->args);
}

int	main(int argc, char **argv)
{
	t_stack	stck;

	if (1 < argc)
	{
		space_checker(argc, argv);
		num_checker(argv);
		stck.args = combine_and_split_numbers(argc, argv, &stck.size_a);
		stck.stack_a = number_to_array(stck.args, &stck);
		create_stack(&stck);
		is_sorted(&stck);
		if (stck.size_a == 2)
			sort_two(&stck);
		else if (stck.size_a == 3)
			sort_three(&stck);
		else
			sort_stack(&stck);
		stack_free(&stck);
		free(stck.stack_a);
		free(stck.stack_b);
	}
}
