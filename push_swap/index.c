/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:07 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/06 17:39:50 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arr_insertion_sort(int *arr, int n)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	arr_index_of(int *arr, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

static int	*extract_stack_values(t_stack *a, int n)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->val;
		cur = cur->next;
	}
	return (arr);
}

static void	assign_indices_to_stack(t_stack *a, int *arr, int n)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		cur->idx = arr_index_of(arr, n, cur->val);
		cur = cur->next;
	}
}

void	index_assign(t_stack *a)
{
	int	n;
	int	*arr;

	if (!a || a->size <= 0)
		return ;
	n = a->size;
	arr = extract_stack_values(a, n);
	if (!arr)
		return ;
	arr_insertion_sort(arr, n);
	assign_indices_to_stack(a, arr, n);
	free(arr);
}
