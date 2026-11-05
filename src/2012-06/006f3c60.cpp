// from server: 61% by atomic.potato
struct S
{
    int f();
    int *p;
};

int S::f()
{
    struct V
    {
        int (**vtable)();
    };

    V *q = *(V **)((char *)this + 12);
    int *x = (int *)((char *)q + 336);
    int *y = (int *)((char *)x + 0);
    int z = (*((int (**)())((char *)*y + 4)))();
    return *((int *)((char *)z + 328)) == 4;
}
