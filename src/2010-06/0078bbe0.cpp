// from server: 20% by atomic.potato
struct S
{
    S *next;
    S *f();
};

S *S::f()
{
    S *p = this;
    while (p->next)
        p = p;
    return (S *)((char *)p - 8);
}
