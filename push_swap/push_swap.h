/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:00:02 by mmustone          #+#    #+#             */
/*   Updated: 2025/11/07 16:23:42 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bot;
	int				size;
}					t_stack;

t_stack				stack_init(void);
t_node				*node_new(int val);

int					stack_is_empty(t_stack *s);
void				stack_push_top(t_stack *s, t_node *n);
t_node				*stack_pop_top(t_stack *s);
void				stack_push_bot(t_stack *s, t_node *n);
void				stack_clear(t_stack *s);

void				op_sa(t_stack *a);
void				op_sb(t_stack *b);

void				op_pa(t_stack *a, t_stack *b);
void				op_pb(t_stack *a, t_stack *b);

void				op_ra(t_stack *a);
void				op_rb(t_stack *b);
void				op_rr(t_stack *a, t_stack *b);

void				op_rra(t_stack *a);
void				op_rrb(t_stack *b);

int					parse_args_into_stack(int argc, char **argv, t_stack *a);
int					ps_error(t_stack *a, t_stack *b);
int					is_space(char c);
int					is_digit(char c);
int					stack_contains(t_stack *s, int v);

int					is_sorted(t_stack *a);
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
int					is_sorted(t_stack *a);
int					pos_of_idx(t_stack *s, int idx);

void				index_assign(t_stack *a);

void				rotate_a_to_top(t_stack *a, int pos);
void				rotate_b_to_top(t_stack *b, int pos);

void				sort_big_chunks(t_stack *a, t_stack *b);

#endif
