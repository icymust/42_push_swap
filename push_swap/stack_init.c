/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:59 by mmustone          #+#    #+#             */
/*   Updated: 2025/10/31 18:08:00 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Создаёт пустой стек с заданным именем */
t_stack	stack_init(char name)
{
	t_stack	s;

	s.top = NULL;
	s.bot = NULL;
	s.size = 0;
	s.name = name;
	return (s);
}

/* Выделяет новый узел и заполняет его значением */
t_node	*node_new(int val)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->val = val;
	n->prev = NULL; //указывает на пред узел, если топ -> null
	n->next = NULL; //указывает на след узел
	return (n);
}