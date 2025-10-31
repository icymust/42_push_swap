/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:25 by mmustone          #+#    #+#             */
/*   Updated: 2025/10/31 18:07:26 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rra, rrb, rrr
/* ---- REVERSE ROTATE MECHANICS ---- */
/* internal: сдвиг вниз (bot -> top), без печати */
void rotate_down(t_stack *s)
{
    t_node *last;     /* был bot */
    t_node *before;   /* был bot->prev */

    if (!s || s->size < 2)
        return;

    last   = s->bot;
    before = last->prev;  /* существует, т.к. size>=2 */

    /* 1) отцепляем last от низа */
    before->next = NULL;
    s->bot = before;

    /* 2) вставляем last наверх */
    last->prev = NULL;
    last->next = s->top;
    s->top->prev = last;
    s->top = last;
}

/* публичные обёртки (пока без write("rra\n")) */
void op_rra(t_stack *a) { rotate_down(a); write(1, "rra\n", 4);}
void op_rrb(t_stack *b) { rotate_down(b); write(1, "rrb\n", 4);}
void op_rrr(t_stack *a, t_stack *b)
{
    rotate_down(a);
    rotate_down(b);
    write(1, "rrr\n", 4);
}