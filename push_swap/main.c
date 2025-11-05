/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:12 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/05 13:39:37 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack a = stack_init('a');
    t_stack b = stack_init('b');

    if (ac < 2)
        return 0;

    if (parse_args_into_stack(ac, av, &a) < 0)
    {
        stack_clear(&a);
        return 1;
    }
    index_assign(&a);

    if (!is_sorted(&a)) {
        if (a.size == 2)
            sort_two(&a);
        else if (a.size == 3)
            sort_three(&a);
        else if (a.size == 4)
            sort_four(&a, &b);
        else if (a.size == 5)
            sort_five(&a, &b);
        else
            sort_big_chunks(&a, &b);
    }

    stack_clear(&a);
    (void)b;
    return 0;
}