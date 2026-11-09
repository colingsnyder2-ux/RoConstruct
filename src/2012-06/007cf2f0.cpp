// from server: 100% by atomic.potato
struct S
{
    int f(void *);
    int *p0;
    int *p1;
    int *p2;
    int *p3;
};

int S::f(void *arg)
{
    int *p = (int *)arg;
    if (p)
        p = (int *)((char *)p - 0x1c);
    else
        p = 0;

    int *q = *(int **)((char *)p + 0x84);
    q = *(int **)((char *)q + (int)p3);
    q = (int *)((char *)q + (int)p2);
    return *(int *)((char *)q + (int)p + 0x84);
}
