#include "push_swap.h"
#include <unistd.h>

/* ---- tiny print helpers (no stdio) ---- */
static void putstr(const char *s) { while (*s) write(1, s++, 1); }

static void putnbr(int n)
{
    char    c;
    long    x = n;           /* чтобы корректно печатать INT_MIN */
    if (x < 0) { write(1, "-", 1); x = -x; }
    if (x >= 10) putnbr((int)(x / 10));
    c = '0' + (x % 10);
    write(1, &c, 1);
}

static void print_stack(const char *name, t_stack *s)
{
    t_node *cur;

    putstr(name); putstr(" (top ↑): ");
    if (!s || !s->top) { putstr("[empty]\n"); return; }
    cur = s->top;
    while (cur)
    {
        putstr("[");
        putnbr(cur->val);
        putstr("]");
        if (cur->next) putstr(" ");
        cur = cur->next;
    }
    putstr("\n");
}

int main(void)
{
    t_stack a = stack_init('a');
    t_stack b = stack_init('b');

    /* a: [9,7,5] */
    stack_push_top(&a, node_new(5));
    stack_push_top(&a, node_new(7));
    stack_push_top(&a, node_new(9));

    /* b: [6,2,1] */
    stack_push_top(&b, node_new(1));
    stack_push_top(&b, node_new(2));
    stack_push_top(&b, node_new(6));

    putstr("Initial:\n");
    print_stack("A", &a);    /* A (top ↑): [9] [7] [5] */
    print_stack("B", &b);    /* B (top ↑): [6] [2] [1] */

    putstr("\nAfter sa:\n");
    op_sa(&a);
    print_stack("A", &a);    /* A (top ↑): [7] [9] [5] */
    print_stack("B", &b);

    putstr("\nAfter sb:\n");
    op_sb(&b);
    print_stack("A", &a);
    print_stack("B", &b);    /* B (top ↑): [2] [6] [1] */

    putstr("\nAfter ss:\n");
    op_ss(&a, &b);
    print_stack("A", &a);
    print_stack("B", &b);

    stack_clear(&a);
    stack_clear(&b);
    return 0;
}
