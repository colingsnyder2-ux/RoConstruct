// from server: 100% by atomic.potato
struct S
{
    int *a;
    int *b;
    int *c;
    void f();
};

void S::f()
{
    if (b != 0)
    {
        if (c != 0)
            *c = (int)a;

        if (a != 0)
            *(int **)((char *)a + 0xe0) = c;

        --*b;
        a = 0;
        c = 0;
        b = 0;
    }
}
