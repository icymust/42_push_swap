/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:25 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/05 13:45:06 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_stack *s)
{
	t_node	*last;
	t_node	*before;

	if (!s || s->size < 2)
		return ;
	last = s->bot;
	before = last->prev;
	before->next = NULL;
	s->bot = before;
	last->prev = NULL;
	last->next = s->top;
	s->top->prev = last;
	s->top = last;
}

void	op_rra(t_stack *a)
{
	rotate_down(a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *b)
{
	rotate_down(b);
	write(1, "rrb\n", 4);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	write(1, "rrr\n", 4);
}
