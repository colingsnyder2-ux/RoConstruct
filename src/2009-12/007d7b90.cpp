// from server: 100% by atomic.potato
struct S
{
    S *f(void *, void *);
};

S *S::f(void *a, void *b)
{
    S *p = this;
    p->f(a, b);
    *(int *)p = 0x9ef650;
    *(int *)((char *)p + 4) = 0x9ef648;
    return p;
}
