/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:32 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/05 13:46:36 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	s->top = second;
	second->prev = NULL;
	first->next = NULL;
	first->prev = s->bot;
	s->bot->next = first;
	s->bot = first;
}

void	op_ra(t_stack *a)
{
	rotate_up(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	rotate_up(b);
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
}

void rotate_a_to_top(t_stack *a, int pos)
{
    int n, i;

    if (!a || a->size < 2)
        return;

    n = a->size;
    if (pos <= n / 2)
    {
        i = 0;
        while (i < pos) { op_ra(a); i++; }
    }
    else
    {
        i = 0;
        while (i < (n - pos)) { op_rra(a); i++; }
    }
}

void rotate_b_to_top(t_stack *b, int pos)
{
    int n, i;

    if (!b || b->size < 2)
        return;

    n = b->size;
    if (pos <= n / 2)
    {
        i = 0;
        while (i < pos) { op_rb(b); i++; }
    }
    else
    {
        i = 0;
        while (i < (n - pos)) { op_rrb(b); i++; }
    }
}
