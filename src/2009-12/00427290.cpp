// from server: 81% by atomic.potato
struct V
{
    void (*destroy)(int);
};

struct S
{
    V *value;
    void f(S *first, S *last);
};

void S::f(S *first, S *last)
{
    while (first != last)
    {
        if (first->value)
            first->value->destroy(1);
        first = (S *)((char *)first + 8);
    }
}
