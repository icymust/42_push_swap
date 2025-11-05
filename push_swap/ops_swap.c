/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:37 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/05 13:45:54 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_stack *s)
{
	t_node *first, *second;
	if (!s || s->size < 2)
		return ;
	first = s->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	s->top = second;
	if (first->next == NULL)
		s->bot = first;
}

void	op_sa(t_stack *a)
{
	swap_top_two(a);
    write(1, "sa\n", 3);
}
void	op_sb(t_stack *b)
{
	swap_top_two(b);
	write(1, "sb\n", 3);
}
void	op_ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	write(1, "ss\n", 3);
}
