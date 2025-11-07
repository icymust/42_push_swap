/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:07:12 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/07 16:23:27 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_type(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		sort_big_chunks(a, b);
}

int	main(int ac, char **av)
{
    t_stack	a;
    t_stack	b;

    a = stack_init();
    b = stack_init();
    if (ac < 2)
        return (0);
    if (parse_args_into_stack(ac, av, &a) < 0)
        ps_error(&a, &b);
    index_assign(&a);
    if (!is_sorted(&a))
        sort_type(&a, &b);
    stack_clear(&a);
    stack_clear(&b);
    return (0);
}
