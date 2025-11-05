/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:07 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/05 13:39:24 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void arr_insertion_sort(int *arr, int n)
{
    int i = 1;
    while (i < n)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        i++;
    }
}

static int arr_index_of(int *arr, int n, int value)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == value)
            return i;
        i++;
    }
    return 0;
}

void index_assign(t_stack *a)
{
    int     n;
    int    *arr;
    t_node *cur;
    int     i;

    if (!a)
        return;
    n = a->size;
    if (n <= 0)
        return;

    arr = (int *)malloc(sizeof(int) * n);
    if (!arr)
        return;

    cur = a->top;
    i = 0;
    while (cur)
    {
        arr[i++] = cur->val;
        cur = cur->next;
    }
    arr_insertion_sort(arr, n);

    cur = a->top;
    while (cur)
    {
        cur->idx = arr_index_of(arr, n, cur->val);
        cur = cur->next;
    }

    free(arr);
}
