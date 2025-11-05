/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:19 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/05 13:46:14 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_pa(t_stack *a, t_stack *b)
{
    t_node *n;

    if (!a || !b)
        return;
    n = stack_pop_top(b);
    if (n){
        stack_push_top(a, n);
        write(1, "pa\n", 3);
    }
    
}

void op_pb(t_stack *a, t_stack *b)
{
    t_node *n;

    if (!a || !b)
        return;
    n = stack_pop_top(a);
    if (n){
        stack_push_top(b, n);
        write(1, "pb\n", 3);
    }
}
