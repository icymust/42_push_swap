#include "push_swap.h"

/* ---- ROTATE MECHANICS ---- */
/* internal: сдвиг вверх (top -> bot), без печати */
void rotate_up(t_stack *s)
{
    t_node *first;
    t_node *second;

    if (!s || s->size < 2)
        return;

    first  = s->top;          /* бывший верх */
    second = first->next;     /* станет новым top */

    /* 1) отцепляем first от верха */
    s->top = second;
    second->prev = NULL;

    /* 2) прицепляем first в самый низ */
    first->next = NULL;
    first->prev = s->bot;
    s->bot->next = first;
    s->bot = first;
}

/* публичные обёртки (пока без write("ra\n")) */
void op_ra(t_stack *a) { rotate_up(a); op_print("ra\n");}
void op_rb(t_stack *b) { rotate_up(b); op_print("rb\n");}
void op_rr(t_stack *a, t_stack *b)
{
    rotate_up(a);
    rotate_up(b);
    write(1, "rr\n", 3);
}