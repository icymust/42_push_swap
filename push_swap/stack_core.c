/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:54 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/05 13:44:07 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_is_empty(t_stack *s)
{
    return (s->size == 0);
}

void stack_push_top(t_stack *s, t_node *n)
{
    if (!s || !n)
        return;
    n->prev = NULL;
    n->next = s->top;
    if (s->top)
        s->top->prev = n;
    s->top = n;
    if (s->bot == NULL)
        s->bot = n;
    s->size += 1;
}

t_node *stack_pop_top(t_stack *s)
{
    t_node *top;

    if (!s || s->size == 0)
        return NULL;

    top = s->top;
    s->top = top->next;
    if (s->top)
        s->top->prev = NULL;
    else
        s->bot = NULL;
    s->size -= 1;

    top->prev = NULL;
    top->next = NULL;
    return top;
}

void stack_clear(t_stack *s)
{
    t_node *n;

    if (!s)
        return;
    while ((n = stack_pop_top(s)) != NULL)
        free(n);
}

void    stack_push_bot(t_stack *s, t_node *n)
{
    if (!s || !n) return;
    n->next = NULL;
    n->prev = s->bot;
    if (s->bot)
        s->bot->next = n;
    else
        s->top = n;
    s->bot = n;
    s->size += 1;
}
