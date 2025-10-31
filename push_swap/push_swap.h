#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

/* =========================================================================
**  INCLUDES
** ========================================================================= */
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

/* =========================================================================
**  TYPES
** ========================================================================= */
/* Forward-declare, чтобы прототипы могли использовать t_stack до его описания */
typedef struct s_stack t_stack;

/* Узел двусвязного списка (элемент стека) */
typedef struct s_node {
    int             val;   /* исходное значение */
    int             idx;   /* ранг (0..n-1) после индексирования */
    struct s_node  *prev;
    struct s_node  *next;
} t_node;

/* Стек: верх, низ, размер, имя ('a'/'b' для отладки) */
struct s_stack {
    t_node *top;
    t_node *bot;
    int     size;
    char    name;
};

/* =========================================================================
**  STACK CORE (инициализация и базовые примитивы)
** ========================================================================= */
t_stack  stack_init(char name);
t_node  *node_new(int val);

int      stack_is_empty(t_stack *s);
void     stack_push_top(t_stack *s, t_node *n);
t_node  *stack_pop_top(t_stack *s);
void     stack_push_bot(t_stack *s, t_node *n);
void     stack_clear(t_stack *s);

/* =========================================================================
**  OPS (разрешённые операции проекта)
** ========================================================================= */
/* swap */
void     op_sa(t_stack *a);
void     op_sb(t_stack *b);
void     op_ss(t_stack *a, t_stack *b);

/* push */
void     op_pa(t_stack *a, t_stack *b); /* b -> a */
void     op_pb(t_stack *a, t_stack *b); /* a -> b */

/* rotate */
void     op_ra(t_stack *a);
void     op_rb(t_stack *b);
void     op_rr(t_stack *a, t_stack *b);

/* reverse rotate */
void     op_rra(t_stack *a);
void     op_rrb(t_stack *b);
void     op_rrr(t_stack *a, t_stack *b);

/* вывод одной операции (если используешь) */
void     op_print(const char *s);

/* =========================================================================
**  PARSE
** ========================================================================= */
int      parse_args_into_stack(int argc, char **argv, t_stack *a);

/* =========================================================================
**  SMALL SORTS
** ========================================================================= */
int      is_sorted(t_stack *a);
void     sort_two(t_stack *a);
void     sort_three(t_stack *a);
void sort_four(t_stack *a, t_stack *b);
void sort_five(t_stack *a, t_stack *b);

/* =========================================================================
**  UTILS (позиции/докрутка)
** ========================================================================= */
int      min_pos(t_stack *s);
int      max_pos(t_stack *s);


/* =========================================================================
**  INDEXING (ранги 0..n-1)
** ========================================================================= */
void     index_assign(t_stack *a);

int  pos_of_idx(t_stack *s, int idx);  /* позиция узла с данным idx (0=top) */

void rotate_a_to_top(t_stack *a, int pos);
void rotate_b_to_top(t_stack *b, int pos);

/* big sort: chunks + greedy */
void sort_big_chunks(t_stack *a, t_stack *b);


#endif /* PUSH_SWAP_H */
