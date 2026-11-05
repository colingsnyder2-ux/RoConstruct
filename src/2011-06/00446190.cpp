// from server: 91% by atomic.potato
struct S
{
    int f(void *, void *);
    void *a[78];
};

struct T
{
    void *vtable;
};

typedef int (__thiscall *F)(void *, void *, void *);

int S::f(void *a, void *b)
{
    void *p;
    T *q;

    if (a)
        p = (char *)a + 28;
    else
        p = 0;

    q = (T *)((char *)this->a[78] + 28);
    return ((F)((void **)q->vtable)[3])(q, p, b);
}
