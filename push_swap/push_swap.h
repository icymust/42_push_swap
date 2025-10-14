#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

/* Узел стека (двусвязный список) */
typedef struct s_node {
    int             val;
    struct s_node  *prev;
    struct s_node  *next;
} t_node;

/* Стек: указатели на верх/низ и размер */
typedef struct s_stack {
    t_node *top;  /* вершина (голова) */
    t_node *bot;  /* низ (хвост)     */
    int     size; /* текущее кол-во узлов */
    char    name; /* 'a' или 'b' — для отладки */
} t_stack;

/* Базовые конструкторы */
t_stack  stack_init(char name);
t_node  *node_new(int val);

/* Примитивы работы со стеком */
int      stack_is_empty(t_stack *s);
void     stack_push_top(t_stack *s, t_node *n);
t_node  *stack_pop_top(t_stack *s);
void     stack_push_bot(t_stack *s, t_node *n);
void     stack_clear(t_stack *s);

/* Операции swap */
void     op_sa(t_stack *a);
void     op_sb(t_stack *b);
void     op_ss(t_stack *a, t_stack *b);

/* Операции push */
void     op_pa(t_stack *a, t_stack *b); /* b -> a */
void     op_pb(t_stack *a, t_stack *b); /* a -> b */

/* Операции rotate */
void     op_ra(t_stack *a);
void     op_rb(t_stack *b);
void     op_rr(t_stack *a, t_stack *b);

/* Операции reverse rotate */
void     op_rra(t_stack *a);
void     op_rrb(t_stack *b);
void     op_rrr(t_stack *a, t_stack *b);

/* Вывод операции */
void     op_print(const char *s);

//parse
int     parse_args_into_stack(int argc, char **argv, t_stack *a);


#endif 
