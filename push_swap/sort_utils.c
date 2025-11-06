/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:10:34 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/06 18:14:35 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_to_top(t_stack *a, int pos)
{
	int	n;
	int	i;

	if (!a || a->size < 2)
		return ;
	n = a->size;
	if (pos <= n / 2)
	{
		i = 0;
		while (i < pos)
		{
			op_ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (n - pos))
		{
			op_rra(a);
			i++;
		}
	}
}

void	rotate_b_to_top(t_stack *b, int pos)
{
	int	n;
	int	i;

	if (!b || b->size < 2)
		return ;
	n = b->size;
	if (pos <= n / 2)
	{
		i = 0;
		while (i < pos)
		{
			op_rb(b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (n - pos))
		{
			op_rrb(b);
			i++;
		}
	}
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || a->size < 2)
		return (1);
	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->val > cur->next->val)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	pos_of_idx(t_stack *s, int idx)
{
	t_node	*cur;
	int		p;

	cur = s->top;
	p = 0;
	while (cur)
	{
		if (cur->idx == idx)
			return (p);
		cur = cur->next;
		p++;
	}
	return (0);
}
