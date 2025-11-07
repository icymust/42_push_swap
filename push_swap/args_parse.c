/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:21 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/07 16:23:18 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_spaces_and_sign(const char *s, int *idx, int *sign)
{
	int	i;

	i = *idx;
	while (s[i] && is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			*sign = -1;
		else
			*sign = 1;
		i++;
	}
	*idx = i;
	return (1);
}

static int	parse_one_int(const char *s, int *idx, long *out)
{
    int		sign;
    long	val;
    int		have_digits;

    sign = 1;
    val = 0;
    have_digits = 0;
    skip_spaces_and_sign(s, idx, &sign);
    while (is_digit(s[*idx]))
    {
        have_digits = 1;
        val = val * 10 + (s[*idx] - '0');
        if (val > 2147483648)
            break ;
        (*idx)++;
    }
    if (!have_digits || val * sign < -2147483648 || val * sign > 2147483647)
        return (0);
    *out = val * sign;
    return (1);
}

static int	process_argument(const char *arg, t_stack *a)
{
    int		idx;
    long	val;
    t_node	*n;

    idx = 0;
    if (!arg || !*arg)
        return (ps_error(a, NULL));
    while (arg[idx])
    {
        while (arg[idx] && is_space(arg[idx]))
            idx++;
        if (!arg[idx])
            break ;
        if (!parse_one_int(arg, &idx, &val))
            return (ps_error(a, NULL));
        if (arg[idx] && !is_space(arg[idx]) && !is_digit(arg[idx]))
            return (ps_error(a, NULL));
        if (stack_contains(a, (int)val))
            return (ps_error(a, NULL));
        n = node_new((int)val);
        if (!n)
            return (ps_error(a, NULL));
        stack_push_bot(a, n);
    }
    return (1);
}

int	parse_args_into_stack(int argc, char **argv, t_stack *a)
{
    int	i;
    int	progressed;

    i = 1;
    while (i < argc)
    {
        progressed = process_argument(argv[i], a);
        if (!progressed)
            return (-1);
        i++;
    }
    return (0);
}
