// from server: 26% by atomic.potato
struct S
{
    int __cdecl f(void *);
};

int S::f(void *p)
{
    void *q = p;
    q = p;
    f(&q);
    return 0;
}
