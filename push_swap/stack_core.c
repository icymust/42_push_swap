#include "push_swap.h"

/* 1 — пуст, 0 — не пуст */
int stack_is_empty(t_stack *s)
{
    return (s->size == 0);
}

/* вставка узла наверх: O(1) */
void stack_push_top(t_stack *s, t_node *n)
{
    if (!s || !n)
        return;
    n->prev = NULL;
    n->next = s->top;
    if (s->top)
        s->top->prev = n;
    s->top = n;
    if (s->bot == NULL)      /* если стек был пуст */
        s->bot = n;
    s->size += 1;
}

/* снять верхний узел и вернуть его (caller сам решает: использовать или free) */
t_node *stack_pop_top(t_stack *s)
{
    t_node *top;

    if (!s || s->size == 0)
        return NULL;

    top = s->top;            /* запоминаем старую верхушку */
    s->top = top->next;      /* сдвигаем вершину вниз (на следующий узел) */
    if (s->top)              /* если новый top существует */
        s->top->prev = NULL; /* у новой вершины нет «предыдущего» */
    else
        s->bot = NULL;       /* стек опустел: bot тоже NULL */
    s->size -= 1;

    /* отцепим узел от списка на всякий случай — чтобы не было «хвостов» */
    top->prev = NULL;
    top->next = NULL;
    return top;              /* возвращаем снятый узел */
}

/* снять и освободить все узлы стека */
void stack_clear(t_stack *s)
{
    t_node *n;

    if (!s)
        return;
    while ((n = stack_pop_top(s)) != NULL)
        free(n);
}

/* push вниз (в хвост): сохраняет порядок ввода слева направо */
void    stack_push_bot(t_stack *s, t_node *n)
{
    if (!s || !n) return;
    n->next = NULL;
    n->prev = s->bot;
    if (s->bot)
        s->bot->next = n;
    else
        s->top = n;     /* стек был пуст */
    s->bot = n;
    s->size += 1;
}
