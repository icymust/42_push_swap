/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:21:58 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/07 16:23:36 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_error(t_stack *a, t_stack *b)
{
    write(2, "Error\n", 6);
    stack_clear(a);
    stack_clear(b);
    exit(1);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	stack_contains(t_stack *s, int v)
{
	t_node	*cur;

	cur = s->top;
	while (cur)
	{
		if (cur->val == v)
			return (1);
		cur = cur->next;
	}
	return (0);
}
