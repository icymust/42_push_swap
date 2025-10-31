/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:48 by mmustone          #+#    #+#             */
/*   Updated: 2025/10/31 18:07:49 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* sort_small.c */
#include "push_swap.h"

/* проверка: стек a уже по возрастанию сверху вниз? */
int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (!a || a->size < 2)
		return (1);
	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->val > cur->next->val)
			return (0); /* нашли инверсию — не отсортировано */
		cur = cur->next;
	}
	return (1); /* прошли все пары: строго по возрастанию */
}

/* 2 элемента: если сверху больше второго — меняем местами */
void	sort_two(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	if (a->top->val > a->top->next->val)
		op_sa(a); /* выведет "sa\n" */
}

/* 3 элемента: 5 случаев; используем только sa/ra/rra */
void	sort_three(t_stack *a)
{
	int x, y, z;
	if (!a || a->size != 3 || is_sorted(a))
		return ;
	x = a->top->val;       /* верх */
	y = a->top->next->val; /* середина */
	z = a->bot->val;       /* низ */
	if (x > y && y < z && x < z) /* 2 1 3 */
		op_sa(a);
	else if (x > y && y > z) /* 3 2 1 */
	{
		op_sa(a);
		op_rra(a);
	}
	else if (x > y && y < z && x > z) /* 3 1 2 */
		op_ra(a);
	else if (x < y && y > z && x < z) /* 2 3 1 */
	{
		op_sa(a);
		op_ra(a);
	}
	else if (x < y && y > z && x > z) /* 1 3 2 */
		op_rra(a);
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
	return (0); /* не должно случиться */
}

/* n = 4: убираем минимум в B, тройку сортируем, возвращаем */
void	sort_four(t_stack *a, t_stack *b)
{
	int	pos_min;

	if (a->size != 4)
		return ;
	pos_min = pos_of_idx(a, 0);  /* минимальный idx=0 */
	rotate_a_to_top(a, pos_min); /* короткой стороной */
	op_pb(a, b);                 /* min → B */
	sort_three(a); /* A (3 элемента) */
	op_pa(a, b); /* вернуть min наверх A */
}

void	sort_five(t_stack *a, t_stack *b)
{
	int pos;

	if (a->size != 5)
		return ;

	/* вытащить min (idx=0) в B */
	pos = pos_of_idx(a, 0);
	rotate_a_to_top(a, pos);
	op_pb(a, b);

	/* вытащить следующий min (idx=1) в B */
	pos = pos_of_idx(a, 1);
	rotate_a_to_top(a, pos);
	op_pb(a, b);

	/* теперь в A осталось 3 — отсортируем */
	sort_three(a);

	/* хотим, чтобы сверху в B был idx=1, ниже — idx=0,
		тогда после pa, pa получим 0 наверху A (0,1,2,3,4). */
	if (b->size >= 2 && b->top->idx < b->top->next->idx)
		op_sb(b);

	op_pa(a, b);
	op_pa(a, b);
}
