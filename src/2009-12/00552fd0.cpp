// from server: 32% by atomic.potato
struct S
{
    void f(void *);
};

void S::f(void *p)
{
    char *q = (char *)p;
    if (q != 0)
    {
        f(q);
    }
}
