#include "push_swap.h"

/* Создаёт пустой стек с заданным именем */
t_stack	stack_init(char name)
{
	t_stack	s;

	s.top = NULL;
	s.bot = NULL;
	s.size = 0;
	s.name = name;
	return (s);
}

/* Выделяет новый узел и заполняет его значением */
t_node	*node_new(int val)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->val = val;
	n->prev = NULL; //указывает на пред узел, если топ -> null
	n->next = NULL; //указывает на след узел
	return (n);
}

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

//swap a,  b
static void swap_top_two(t_stack *s)
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
void op_sa(t_stack *a) { swap_top_two(a); }
void op_sb(t_stack *b) { swap_top_two(b); }
void op_ss(t_stack *a, t_stack *b)
{
    swap_top_two(a);
    swap_top_two(b);
}

//push a,b
void op_pb(t_stack *a, t_stack *b) /* переложить вершину a -> b */
{
    t_node *n;

    if (!a || !b)
        return;
    n = stack_pop_top(a);
    if (n)
        stack_push_top(b, n);
    /* при желании печать: write(1,"pb\n",3); */
}

void op_pa(t_stack *a, t_stack *b) /* переложить вершину b -> a */
{
    t_node *n;

    if (!a || !b)
        return;
    n = stack_pop_top(b);
    if (n)
        stack_push_top(a, n);
    /* при желании печать: write(1,"pa\n",3); */
}
