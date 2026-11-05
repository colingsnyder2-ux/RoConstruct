// from server: 57% by atomic.potato
struct S
{
    int *p;

    void f();
};

void S::f()
{
    if (p != 0)
    {
        struct T
        {
            int (**v)(int);
        };

        T *q = (T *)((char *)p + 4);
        q->v[1](1);
    }
}
