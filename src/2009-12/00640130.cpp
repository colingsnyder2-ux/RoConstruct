// from server: 43% by atomic.potato
struct S
{
    void __cdecl f(void *);
};

struct T
{
    char data[1];
};

void g(T *, int, char **);

void S::f(void *p)
{
    T *q = *(T **)p;
    char *x = 0;
    g(q + 1, 0, &x);
}
