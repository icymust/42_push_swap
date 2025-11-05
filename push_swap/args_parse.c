/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:38:21 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/05 13:39:06 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	parse_one_int(const char *s, int *idx, long *out)
{
	int		i;
	int		sign;
	long	val;
	int		have_digits;

	i = *idx;
	sign = 1;
	val = 0;
	have_digits = 0;
	while (s[i] && is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (is_digit(s[i]))
	{
		have_digits = 1;
		val = val * 10 + (s[i] - '0');
		if (val > (long)INT_MAX + 1)
			break ;
		i++;
	}
	if (have_digits != 1)
		return (0);
	val *= sign;
	
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	
	*out = val;
	*idx = i;
	return (1);
}

static int	stack_contains(t_stack *s, int v)
{
	t_node	*cur;

	cur = s->top;
	while (cur)
	{
		if (cur->val == v)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int parse_args_into_stack(int argc, char **argv, t_stack *a)
{
    int i;
    int idx;
    long val;
    t_node *n;

    i = 1;
    while (i < argc)
    {
        const char *arg = argv[i];
        idx = 0;
        int progressed = 0;
        while (arg[idx])
        {
            while (arg[idx] && is_space(arg[idx]))
                idx++;
            if (!arg[idx])
                break;
            if (!parse_one_int(arg, &idx, &val))
                return (ps_error());
            progressed = 1;
            if (arg[idx] && !is_space(arg[idx]))
                return (ps_error());
            if (stack_contains(a, (int)val))
                return (ps_error());
            n = node_new((int)val);
            if (!n)
                return (ps_error());
            stack_push_bot(a, n);
        }
        if (!progressed)
            return (ps_error());
        i++;
    }
    return (0);
}
