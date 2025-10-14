#include "push_swap.h"

//swap a,  b
void swap_top_two(t_stack *s)
{
    t_node *first, *second;

    if (!s || s->size < 2)
        return;

    first  = s->top;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev  = second;

    s->top = second;
    if (first->next == NULL)
        s->bot = first;
}

/* публичные обёртки (пока без печати инструкций) */
void op_sa(t_stack *a) { swap_top_two(a); op_print("sa\n");}
void op_sb(t_stack *b) { swap_top_two(b); op_print("sb\n");}
void op_ss(t_stack *a, t_stack *b)
{
    swap_top_two(a);
    swap_top_two(b);
    op_print("ss\n");
}