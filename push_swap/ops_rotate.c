/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:32 by mmustone          #+#    #+#             */
/*   Updated: 2025/10/31 18:07:32 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ---- ROTATE MECHANICS ---- */
/* internal: сдвиг вверх (top -> bot), без печати */
void	rotate_up(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = s->top;       /* бывший верх */
	second = first->next; /* станет новым top */
	/* 1) отцепляем first от верха */
	s->top = second;
	second->prev = NULL;
	/* 2) прицепляем first в самый низ */
	first->next = NULL;
	first->prev = s->bot;
	s->bot->next = first;
	s->bot = first;
}

/* публичные обёртки (пока без write("ra\n")) */
void	op_ra(t_stack *a)
{
	rotate_up(a);
	op_print("ra\n");
}
void	op_rb(t_stack *b)
{
	rotate_up(b);
	op_print("rb\n");
}
void	op_rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
}

/* Докрутить A так, чтобы элемент на позиции pos (0=top) стал вершиной */
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

/* То же самое для B */
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

