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
        if (c != 0)
            *(int *)c = a;

        if (a != 0)
            *(int *)(a + 0xe0) = c;

        --*(int *)b;
        a = 0;
        c = 0;
        b = 0;
    }
}
