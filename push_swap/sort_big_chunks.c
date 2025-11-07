/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:06:51 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/07 15:32:59 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pos_of_max_idx(t_stack *s)
{
	t_node	*cur;
	int		pos;
	int		best_pos;
	int		best_idx;

	if (!s || s->size == 0)
		return (0);
	cur = s->top;
	pos = 0;
	best_pos = 0;
	best_idx = 0;
	while (cur)
	{
		if (cur->idx > best_idx)
		{
			best_idx = cur->idx;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	return (best_pos);
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk)
{
	int	target;
	int	x;

	target = 0;
	while (a->size > 0)
	{
		x = a->top->idx;
		if (x <= target)
		{
			op_pb(a, b);
			op_rb(b);
			target++;
		}
		else if (x <= target + chunk)
		{
			op_pb(a, b);
			target++;
		}
		else
			op_ra(a);
	}
}

static void	greedy_return_from_b(t_stack *a, t_stack *b)
{
	int	pos;

	while (b->size > 0)
	{
		pos = pos_of_max_idx(b);
		rotate_b_to_top(b, pos);
		op_pa(a, b);
	}
}

void	sort_big_chunks(t_stack *a, t_stack *b)
{
	int	n;
	int	chunk;

	n = a->size;
	if (n <= 100)
		chunk = 15;
	else
		chunk = 30;
	push_chunks_to_b(a, b, chunk);
	greedy_return_from_b(a, b);
}
