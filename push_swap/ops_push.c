#include "push_swap.h"

//push a,b
void op_pa(t_stack *a, t_stack *b) /* переложить вершину b -> a */
{
    t_node *n;

    if (!a || !b)
        return;
    n = stack_pop_top(b);
    if (n){
        stack_push_top(a, n);
        op_print("pa\n");
    }
    
}


void op_pb(t_stack *a, t_stack *b) /* переложить вершину a -> b */
{
    t_node *n;

    if (!a || !b)
        return;
    n = stack_pop_top(a);
    if (n){
        stack_push_top(b, n);
        op_print("pb\n");
    }
    
}