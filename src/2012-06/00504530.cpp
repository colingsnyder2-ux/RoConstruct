// from server: 59% by atomic.potato
struct S
{
    void __cdecl f(void *begin, void *end, void *out);
};

void S::f(void *begin, void *end, void *out)
{
    unsigned long *p = (unsigned long *)begin;
    unsigned long *q = (unsigned long *)end;
    unsigned long *r = (unsigned long *)out;

    while (p != q)
    {
        r -= 2;
        p -= 2;
        r[0] = p[0];
        r[1] = p[1];
    }
}
