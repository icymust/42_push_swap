/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:07 by mmustone          #+#    #+#             */
/*   Updated: 2025/10/31 18:07:09 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* index.c — присваивает каждому узлу стека A ранг (idx) 0..n-1 */
#include "push_swap.h"
#include <stdlib.h>

/* простая сортировка вставками (insertion sort) */
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

/* линейный поиск индекса значения в отсортированном массиве */
static int arr_index_of(int *arr, int n, int value)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == value)
            return i;
        i++;
    }
    return 0; /* до сюда не дойдём, дубликатов нет по условиям парсинга */
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

    /* 1) скопировать значения из стека в массив */
    cur = a->top;
    i = 0;
    while (cur)
    {
        arr[i++] = cur->val;
        cur = cur->next;
    }

    /* 2) отсортировать массив по возрастанию */
    arr_insertion_sort(arr, n);

    /* 3) присвоить каждому узлу ранг (позицию в отсортированном массиве) */
    cur = a->top;
    while (cur)
    {
        cur->idx = arr_index_of(arr, n, cur->val);
        cur = cur->next;
    }

    free(arr);
}
