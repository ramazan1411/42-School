/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raktas <raktas@student.42İstanbul.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:45:15 by raktas            #+#    #+#             */
/*   Updated: 2025/01/31 12:45:18 by raktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_cheapest(t_stack *stack, t_moves *moves)
{
	int	j;

	j = -1;
	while (++j < moves->rrr)
		rrr(stack);
	j = -1;
	while (++j < moves->rr)
		rr(stack);
	j = -1;
	while (++j < moves->ra)
		ra(stack);
	j = -1;
	while (++j < moves->rb)
		rb(stack);
	j = -1;
	while (++j < moves->rra)
		rra(stack);
	j = -1;
	while (++j < moves->rrb)
		rrb(stack);
	pb(stack);
}

void	make_b(t_stack *stack, t_moves *moves)
{
	int	j;

	j = -1;
	while (++j < moves->rrr)
		rrr(stack);
	j = -1;
	while (++j < moves->rr)
		rr(stack);
	j = -1;
	while (++j < moves->ra)
		ra(stack);
	j = -1;
	while (++j < moves->rb)
		rb(stack);
	j = -1;
	while (++j < moves->rra)
		rra(stack);
	j = -1;
	while (++j < moves->rrb)
		rrb(stack);
}

void	make_and_push_a(t_stack *stack, t_moves *moves)
{
	int	j;

	j = -1;
	while (++j < moves->ra)
		ra(stack);
	j = -1;
	while (++j < moves->rra)
		rra(stack);
	j = -1;
	pa(stack);
}

void	initiate_moves(t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->cost = 0;
}
