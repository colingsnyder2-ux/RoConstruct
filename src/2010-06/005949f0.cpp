// from server: 62% by atomic.potato
struct S
{
    int value;
};

struct T
{
    int (*function)(T *, S *, int);
};

struct U
{
    int value;
};

void __stdcall f(U *a, int b, int c)
{
    S *p = a->value ? (S *)a->value : 0;
    while (p)
    {
        b = c;
        ((T *)((char *)((void **)b)[0] + 0x4c))->function((T *)b, p, c);
        p = (S *)p->value;
    }
}
