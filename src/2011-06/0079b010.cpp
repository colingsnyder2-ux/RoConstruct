// from server: 64% by atomic.potato
struct S
{
    void *f(void *p);
};

void *S::f(void *p)
{
    if (p)
        p = (char *)p + 8;
    else
        p = 0;
    return p;
}
