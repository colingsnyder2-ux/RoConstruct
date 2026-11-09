// from server: 100% by atomic.potato
struct S
{
    int a;
    int b;
    int c;

    void f();
};

void S::f()
{
    if (b != 0)
    {
        int *p = (int *)c;
        if (p != 0)
            *p = a;

        if (a != 0)
            *(int *)((char *)a + 0xe0) = c;

        --*((int *)b);
        a = 0;
        c = 0;
        b = 0;
    }
}
