/* main.c — мини-тесты парсера и заполнения стека */
#include "push_swap.h"
#include <unistd.h>
#include <limits.h>

/* --- tiny print helpers --- */
static void putstr(const char *s){ while(*s) write(1, s++, 1); }
// static void putnbr(int n){
//     long x = n; char c;
//     if (x < 0){ write(1,"-",1); x = -x; }
//     if (x >= 10) { int q = (int)(x/10); putnbr(q); x -= (long)q*10; }
//     c = '0' + (char)x; write(1, &c, 1);
// }
#define ASSERT(ok,msg) do{ putstr((ok)?"OK  ":"KO  "); putstr(msg); putstr("\n"); }while(0)

/* сравнить стек сверху вниз с ожидаемой последовательностью ints */
static int stack_equals(t_stack *s, const int *arr, int n)
{
    if (!s) return 0;
    if (s->size != n) return 0;

    t_node *cur = s->top;
    for (int i = 0; i < n; i++) {
        if (!cur || cur->val != arr[i]) return 0;
        cur = cur->next;
    }
    return cur == NULL;
}

/* единичный прогон: создаёт стек, парсит argv, сверяет результат, чистит */
static void run_case(const char *label, int argc, char **argv,
                     const int *expected, int exp_len, int expect_error)
{
    t_stack a = stack_init('a');
    int rc = parse_args_into_stack(argc, argv, &a);

    if (expect_error) {
        ASSERT(rc < 0, label);
        stack_clear(&a);
        return;
    }
    if (rc < 0) {
        ASSERT(0, label); /* получили Error, а не ожидали */
        stack_clear(&a);
        return;
    }
    ASSERT(stack_equals(&a, expected, exp_len), label);
    stack_clear(&a);
}

int main(void)
{
    /* Case 1: несколько аргументов -> порядок сохраняется (первый остаётся TOP) */
    {
        char *argv1[] = { "./push_swap", "2", "1", "3" };
        int   exp1[]  = { 2, 1, 3 };
        run_case("args split: 2 1 3", 4, argv1, exp1, 3, 0);
    }

    /* Case 2: одно argv со множеством чисел и пробелами */
    {
        char *argv2[] = { "./push_swap", "   -12   3   +7  " };
        int   exp2[]  = { -12, 3, 7 };
        run_case("one arg with spaces", 2, argv2, exp2, 3, 0);
    }

    /* Case 3: дубликат -> Error */
    {
        char *argv3[] = { "./push_swap", "1", "2", "2" };
        run_case("duplicate -> Error", 4, argv3, NULL, 0, 1);
    }

    /* Case 4: overflow выше INT_MAX -> Error */
    {
        char *argv4[] = { "./push_swap", "2147483648" }; /* INT_MAX + 1 */
        run_case("overflow + -> Error", 2, argv4, NULL, 0, 1);
    }

    /* Case 5: пустая строка / только пробелы -> Error */
    {
        char *argv5[] = { "./push_swap", "   " };
        run_case("only spaces -> Error", 2, argv5, NULL, 0, 1);
    }

    /* Case 6: валидные границы int */
    {
        char *argv6[] = { "./push_swap", "42", "-2147483648", "2147483647" };
        int   exp6[]  = { 42, INT_MIN, INT_MAX };
        run_case("int bounds ok", 4, argv6, exp6, 3, 0);
    }

    /* если хочешь увидеть реальный стек — раскомментируй мини-печать:
    t_stack demo = stack_init('a');
    char *argv_demo[] = { "./push_swap", "5 4 3 2 1" };
    if (parse_args_into_stack(2, argv_demo, &demo) == 0) {
        t_node *c = demo.top;
        putstr("DEMO A (top->bot): ");
        while (c){ putstr("["); putnbr(c->val); putstr("] "); c = c->next; }
        putstr("\n");
    }
    stack_clear(&demo);
    */

    return 0;
}
