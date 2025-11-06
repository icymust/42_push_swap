/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:48 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/06 18:15:12 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	if (a->top->val > a->top->next->val)
		op_sa(a);
}

void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	if (!a || a->size != 3 || is_sorted(a))
		return ;
	x = a->top->val;
	y = a->top->next->val;
	z = a->bot->val;
	if (x > y && y < z && x < z)
		op_sa(a);
	else if (x > y && y > z)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (x > y && y < z && x > z)
		op_ra(a);
	else if (x < y && y > z && x < z)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (x < y && y > z && x > z)
		op_rra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	pos_min;

	if (a->size != 4)
		return ;
	pos_min = pos_of_idx(a, 0);
	rotate_a_to_top(a, pos_min);
	op_pb(a, b);
	sort_three(a);
	op_pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pos;

	if (a->size != 5)
		return ;
	pos = pos_of_idx(a, 0);
	rotate_a_to_top(a, pos);
	op_pb(a, b);
	pos = pos_of_idx(a, 1);
	rotate_a_to_top(a, pos);
	op_pb(a, b);
	sort_three(a);
	if (b->size >= 2 && b->top->idx < b->top->next->idx)
		op_sb(b);
	op_pa(a, b);
	op_pa(a, b);
}
